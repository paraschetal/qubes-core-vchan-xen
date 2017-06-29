/*
 * The Qubes OS Project, http://www.qubes-os.org
 *
 * Copyright (C) 2010  Rafal Wojtczuk      <rafal@invisiblethingslab.com>
 * Copyright (C) 2013  Marek Marczykowski  <marmarek@invisiblethingslab.com>
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


int libvchan_write(libvchan_t *ctrl, const void *data, size_t size) {
    return fwrite((char*)data , size, 1, ctrl->filevchan);
}

int libvchan_send(libvchan_t *ctrl, const void *data, size_t size) {
    return fwrite((char*)data , size, 1, ctrl->filevchan);
}

int libvchan_read(libvchan_t *ctrl, void *data, size_t size) {
    return fread((char*)data, size, 1, ctrl->filevchan);
}

int libvchan_recv(libvchan_t *ctrl, void *data, size_t size) {
    return fread((char*)data, size, 1, ctrl->filevchan);
}

int libvchan_wait(libvchan_t *ctrl) {
    UNUSED(ctrl);
    return 1;
}

void libvchan_close(libvchan_t *ctrl) {

    fclose(ctrl->filevchan);
    free(ctrl);
}

EVTCHN libvchan_fd_for_select(libvchan_t *ctrl) {
    return ctrl->filedes;
}

int libvchan_data_ready(libvchan_t *ctrl) {
    UNUSED(ctrl);
    return 1;
}

int libvchan_buffer_space(libvchan_t *ctrl) {
    UNUSED(ctrl);
    return MOCK_BUFFER_SPACE;
}

int libvchan_is_open(libvchan_t *ctrl) {
    UNUSED(ctrl);
    return 1;
}
