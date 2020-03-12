#include <gtk/gtk.h>
void infoBar_init(GtkLabel *infoBar)
{
	//gtk_label_set_justify(infoBar,GTK_JUSTIFY_LEFT);
}
void infoBar_update(GtkLabel *infoBar, char* message)
{
	gtk_label_set_text(infoBar,message);
}