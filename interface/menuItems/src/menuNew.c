#include <gtk/gtk.h>
#include "../../../core/struct.h"


gboolean on_save(GtkWidget *widget, gpointer data)
{
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(DATA(data)->fileChooser->window),"~/");
	gtk_widget_show(GTK_WIDGET(DATA(data)->fileChooser->window));                
	return FALSE;
}

gboolean on_widget_deleted(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    gtk_widget_hide(widget);
    return TRUE;
}