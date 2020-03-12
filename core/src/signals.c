#include <gtk/gtk.h>

#include "../../interface/textBuffer/textBuffer.h"
#include "../../interface/infoBar/infoBar.h"
#include "../struct.h"
#include "../../interface/menuItems/menuItems.h"



void connectMain(Data *data)
{
	//Main Signals Handling
	g_signal_connect(data->mainWindow->window,"destroy", G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(data->fileChooser->window,"delete-event", G_CALLBACK(on_widget_deleted),data);
	
	//TextView Signals Handling
	g_signal_connect(data->mainWindow->textView, "backspace", G_CALLBACK(textBuffer_on_backspace),data);
	g_signal_connect(data->mainWindow->textView, "copy-clipboard", G_CALLBACK(textBuffer_on_copy),data);
	g_signal_connect(data->mainWindow->textView, "cut-clipboard", G_CALLBACK(textBuffer_on_cut),data);
	
	g_signal_connect(data->mainWindow->textView, "key-press-event", G_CALLBACK(textBuffer_key_event), data);
    
	//FileChooser Signals Handling
	g_signal_connect(data->mainWindow->menuNew, "activate", G_CALLBACK(on_save),data);
	
	
	
	
}