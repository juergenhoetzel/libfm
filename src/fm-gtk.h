/*
 *      fm-gtk.h
 *      
 *      Copyright 2009 Hong Jen Yee (PCMan) <pcman.tw@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#ifndef __FM_GTK_H__
#define __FM_GTK_H__

#include "fm.h"
#include "fm-cell-renderer-text.h"
#include "fm-cell-renderer-pixbuf.h"
#include "fm-clipboard.h"
#include "fm-dnd-dest.h"
#include "fm-dnd-src.h"
#include "fm-file-menu.h"
#include "fm-file-properties.h"
#include "fm-folder-model.h"
#include "fm-folder-view.h"
#include "fm-gtk-utils.h"
#include "fm-icon-pixbuf.h"
#include "fm-path-entry.h"
#include "fm-places-view.h"
#include "fm-progress-dlg.h"
#include "fm-app-chooser-dlg.h"
#include "fm-app-menu-view.h"
#include "fm-thumbnail.h"

G_BEGIN_DECLS

gboolean fm_gtk_init(FmConfig* config);
void fm_gtk_finalize();

G_END_DECLS

#endif
