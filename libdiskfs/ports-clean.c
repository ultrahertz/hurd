/* 
   Copyright (C) 1994 Free Software Foundation

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include "priv.h"
#include <hurd/pager.h>

/* Indexed by port type (PT_*); called when the last reference goes
   away on a port. */
void (*ports_cleanroutines[])(void *)=
{
  [PT_PROTID] = diskfs_protid_rele,
  [PT_PAGER] = pager_clean,
  [PT_TRANSBOOT] = fshelp_transboot_clean,
  [PT_CTL] = _diskfs_control_clean,
};
