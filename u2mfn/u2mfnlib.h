/*
 * The Qubes OS Project, http://www.qubes-os.org
 *
 * Copyright (C) 2010  Rafal Wojtczuk  <rafal@invisiblethingslab.com>
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

int u2mfn_get_fd(void);
int u2mfn_get_mfn_for_page(long va, int *mfn) ;
int u2mfn_get_mfn_for_page_with_fd(int fd, long va, int *mfn) ;
int u2mfn_get_last_mfn(int *mfn) ;
int u2mfn_get_last_mfn_with_fd(int fd, int *mfn) ;
char *u2mfn_alloc_kpage(void);
char *u2mfn_alloc_kpage_with_fd(int fd);
