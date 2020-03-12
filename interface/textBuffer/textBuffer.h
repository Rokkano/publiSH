#pragma once

gboolean textBuffer_on_backspace(GtkWidget *widget, gpointer data);
gboolean textBuffer_on_copy(GtkWidget *widget, gpointer data);
gboolean textBuffer_on_cut(GtkWidget *widget, gpointer data);

gboolean textBuffer_key_event(GtkWidget *widget, GdkEventKey *event, gpointer data);

struct stackNode *undoStack_initNode();
void undoStack_stack(struct stackNode *st,const char* value, int x, int y);
void undoStack_unStack(struct stackNode *st);
void undoStack_print(struct stackNode *st);
