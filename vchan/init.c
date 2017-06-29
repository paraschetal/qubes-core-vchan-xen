/*
 * The Qubes OS Project, http://www.qubes-os.org
 *
 * Copyright (C) 2010  Rafal Wojtczuk  <rafal@invisiblethingslab.com>
 * Copyright (C) 2017  Paras Chetal  <paras.chetal@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libvchan.h"
#include "libvchan_private.h"

libvchan_t *libvchan_server_init(int domain, int port, size_t read_min, size_t write_min) {
    char fvchan_path[255];
    libvchan_t *ctrl;

    ctrl = malloc(sizeof(*ctrl));
    if (!ctrl)
        return NULL;

    snprintf(fvchan_path, sizeof(fvchan_path), "/tmp/data/vchan/%d/%d", domain, port);
    ctrl->filevchan = fopen(fvchan_path, "rb+");
    if (!ctrl->filevchan) {
        free(ctrl);
        return NULL;
    }
    ctrl->fvchan_path = strdup(fvchan_path);
    ctrl->filedes = fileno(ctrl->filevchan);
    ctrl->blocking = 1;
    ctrl->read_min = read_min;
    ctrl->write_min = write_min;
    
    return ctrl;
}

libvchan_t *libvchan_client_init(int domain, int port) {
    char fvchan_path[255];
    libvchan_t *ctrl;

    ctrl = malloc(sizeof(*ctrl));
    if (!ctrl)
        return NULL;

    snprintf(fvchan_path, sizeof(fvchan_path), "/tmp/local/domain/%d/data/vchan/%d", domain, port);
    ctrl->filevchan = fopen(fvchan_path, "rb+");
    if (!ctrl->filevchan) {
        free(ctrl);
        return NULL;
    }
    ctrl->fvchan_path = strdup(fvchan_path);
    ctrl->filedes = fileno(ctrl->filevchan);
    ctrl->blocking = 1;
    return ctrl;
}
