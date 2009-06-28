/*
 *      folder-view.h
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


#ifndef __FOLDER_VIEW_H__
#define __FOLDER_VIEW_H__

#include <gtk/gtk.h>
#include "fm-file-info.h"
#include "fm-path.h"

G_BEGIN_DECLS

#define FM_FOLDER_VIEW_TYPE				(fm_folder_view_get_type())
#define FM_FOLDER_VIEW(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj),\
			FM_FOLDER_VIEW_TYPE, FmFolderView))
#define FM_FOLDER_VIEW_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST((klass),\
			FM_FOLDER_VIEW_TYPE, FmFolderViewClass))
#define IS_FM_FOLDER_VIEW(obj)			(G_TYPE_CHECK_INSTANCE_TYPE((obj),\
			FM_FOLDER_VIEW_TYPE))
#define IS_FM_FOLDER_VIEW_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE((klass),\
			FM_FOLDER_VIEW_TYPE))

typedef enum _FmFolderViewMode FmFolderViewMode;
enum _FmFolderViewMode
{
	FM_FV_NONE,
	FM_FV_ICON_VIEW,
	FM_FV_LIST_VIEW,
	FM_FV_COMPACT_VIEW
};

typedef struct _FmFolderView			FmFolderView;
typedef struct _FmFolderViewClass		FmFolderViewClass;

struct _FmFolderView
{
	GtkScrolledWindow parent;

	FmFolderViewMode mode;
	GtkSelectionMode sel_mode;
	GtkSortType sort_type;
	int sort_by;

	gboolean show_hidden;

	GtkWidget* view;
	GtkTreeModel* model;
	char* cwd; /* FIXME: replace this with FmPath later. */
};

struct _FmFolderViewClass
{
	GtkScrolledWindowClass parent_class;
	void (*file_clicked)(FmFolderView* fv, FmFileInfo* file, int type, int btn);
};

GType		fm_folder_view_get_type		(void);
GtkWidget*	fm_folder_view_new			(FmFolderViewMode mode);

void fm_folder_view_set_mode(FmFolderView* fv, FmFolderViewMode mode);
FmFolderViewMode fm_folder_view_get_mode(FmFolderView* fv);

void fm_folder_view_set_selection_mode(FmFolderView* fv, GtkSelectionMode mode);
GtkSelectionMode fm_folder_view_get_selection_mode(FmFolderView* fv);

void fm_folder_view_sort(FmFolderView* fv, GtkSortType type, int by);
GtkSortType fm_folder_view_get_sort_type(FmFolderView* fv);
int fm_folder_view_get_sort_by(FmFolderView* fv);

void fm_folder_view_set_show_hidden(FmFolderView* fv, gboolean show);
gboolean fm_folder_view_get_show_hidden(FmFolderView* fv);

gboolean fm_folder_view_chdir(FmFolderView* fv, const char* path_str);
const char* fm_folder_view_get_cwd(FmFolderView* fv);

FmFileInfoList* fm_folder_view_get_selected_files(FmFolderView* fv);
guint fm_folder_view_get_n_selected_files(FmFolderView* fv);

FmPathList* fm_folder_view_get_selected_file_paths(FmFolderView* fv);

G_END_DECLS

#endif /* __FOLDER_VIEW_H__ */