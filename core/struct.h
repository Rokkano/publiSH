#pragma once

//------------------------------------------------------------------ Main Datas Structure ------------------------------------------------------------------//
#define DATA(i) ( (Data*) i )
struct Data_mainWindow
{
	//Widgets
	GtkWidget *window;
	GtkWidget *textView;
	GtkScrolledWindow *scrollWindow;
	GtkLabel *infoBar;
	
	//Menu Items
	GtkMenuItem *menuNew;
};

struct Data_fileChooser
{
	//Widgets
	GtkFileChooserDialog *window;
	
	//Buttons
	GtkButton *fileChooserOpen;
	GtkButton *fileChooserCancel;
};

typedef struct Data
{
	//builder
	GtkBuilder *builder;
	
	//Windows
	struct Data_mainWindow *mainWindow;
	struct Data_fileChooser *fileChooser;
	
	//Buffers
	GtkTextBuffer *buffer;
	struct stackNode *undoStack; 
	char tempBuffer[256];
	int tempBufferIndex;
} Data;

//------------------------------------------------------------------ Undo Stack Structure ------------------------------------------------------------------//
struct stackNode
{
	const char* value;
	int x;
	int y;
	
	struct stackNode* next;
	struct stackNode* prev;
};
