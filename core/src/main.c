#include <gtk/gtk.h>

#include "../main.h"
#include "../../interface/textBuffer/textBuffer.h"
#include "../../interface/infoBar/infoBar.h"
#include "../struct.h"
#include "../../interface/menuItems/menuItems.h"

int main(int argc, char *argv[])
{
    
	//data initialization
	gtk_init(&argc, &argv);
	Data *data = malloc(sizeof(Data));
    
	initMain(data);
	connectMain(data);
	
	data->undoStack = undoStack_initNode();
	data->tempBufferIndex=0;
	for(int i = 0; i < 256; i++)
		data->tempBuffer[i]=0;
	
	g_object_unref(data->builder);
	gtk_widget_show(data->mainWindow->window);                
    gtk_main();
}