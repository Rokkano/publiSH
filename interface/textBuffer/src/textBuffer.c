#include <gtk/gtk.h>
#include "../../infoBar/infoBar.h"
#include "../../../core/struct.h"
#include "../textBuffer.h"



gboolean textBuffer_on_backspace(GtkWidget *widget, gpointer data)
{
	return FALSE;
}


gboolean textBuffer_on_copy(GtkWidget *widget, gpointer data)
{
	infoBar_update((DATA(data))->mainWindow->infoBar,"Copied to clipboard");
	return FALSE;
}
gboolean textBuffer_on_cut(GtkWidget *widget, gpointer data)
{
	return FALSE;
}

gboolean textBuffer_key_event(GtkWidget *widget, GdkEventKey *event, gpointer data)
{   
	// Data *info = data;
	// if(event->keyval==GDK_KEY_s && event->state & GDK_CONTROL_MASK)
	// {
		// infoBar_update(info->infoBar,"Saved");
		// GtkTextIter start, end;
		// gtk_text_buffer_get_iter_at_offset (info->buffer, &start, 0);
		// gtk_text_buffer_get_iter_at_offset (info->buffer, &end, gtk_text_buffer_get_char_count (info->buffer));
		// printf("%s\n",gtk_text_buffer_get_text(info->buffer,&start,&end,FALSE));
	// }
	if (!(event->state & GDK_CONTROL_MASK) && !(event->state & GDK_SHIFT_MASK))
	{
		if(event->keyval==GDK_KEY_Return)
		{
			char* string = malloc(DATA(data)->tempBufferIndex*sizeof(char));
			memcpy(string, DATA(data)->tempBuffer,DATA(data)->tempBufferIndex);
			for(int i = DATA(data)->tempBufferIndex; i >= 0; i--)
				DATA(data)->tempBuffer[i]=0;
			DATA(data)->tempBufferIndex = 0;
			printf("%s\n",string);
			undoStack_stack(DATA(data)->undoStack,string,0,0);
			// undoStack_print(DATA(data)->undoStack);
		}
		else
		{
			DATA(data)->tempBuffer[DATA(data)->tempBufferIndex] = event->keyval;
			DATA(data)->tempBufferIndex++;
		}
	}
	return FALSE;
}