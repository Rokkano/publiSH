#include <gtk/gtk.h>
#include "../struct.h"

void initMain(Data *data)
{

    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "./interface/glade/mainWindow.glade", NULL);
    
	//Initialize Data_mainWindow
	struct Data_mainWindow *mainWindow = malloc(sizeof(struct Data_mainWindow));
	mainWindow->window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    mainWindow->textView = GTK_WIDGET(gtk_builder_get_object(builder,"textview"));
	mainWindow->infoBar = GTK_LABEL(gtk_builder_get_object(builder,"infoBar"));
	mainWindow->scrollWindow = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrollWindow"));
	
	mainWindow->menuNew = GTK_MENU_ITEM(gtk_builder_get_object(builder,"menuNew"));
	
	// Initialize Data_fileChooser
	struct Data_fileChooser *fileChooser = malloc(sizeof(struct Data_fileChooser));
	fileChooser->window = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder,"fileChooser"));
	
	//Regroup datas in the data pointer
	data->builder = builder;
	data-> mainWindow = mainWindow;
	data-> fileChooser = fileChooser;
	data->buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(mainWindow->textView));
}