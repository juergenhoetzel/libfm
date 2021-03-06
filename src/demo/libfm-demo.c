/*
 *      pcmanfm.c
 *      
 *      Copyright 2009 PCMan <pcman.tw@gmail.com>
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

#include <config.h>
#include <gtk/gtk.h>
#include <stdio.h>

#include "fm-gtk.h"
#include "main-win.h"

int main(int argc, char** argv)
{
	GtkWidget* w;
	gtk_init(&argc, &argv);

	fm_gtk_init(NULL);

	w = fm_main_win_new();
	gtk_window_set_default_size(GTK_WINDOW(w), 640, 480);
	gtk_widget_show(w);

    if(argc > 1)
    {
        FmPath* path = fm_path_new(argv[1]);
        fm_main_win_chdir(FM_MAIN_WIN(w), path);
        fm_path_unref(path);
    }
	
	gtk_main();

    fm_finalize();

	return 0;
}
