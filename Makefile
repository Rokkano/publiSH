CC = gcc
CFLAGS = -Wall 
LDFLAGS = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
OBJ = 	./core/src/main.c ./interface/infoBar/src/infoBar.c ./interface/textBuffer/src/textBuffer.c ./interface/menuItems/src/menuNew.c ./core/src/init.c ./core/src/signals.c ./interface/textBuffer/src/undoStack.c
HEADER= ./core/main.h ./interface/infoBar/infoBar.h ./interface/textBuffer/textBuffer.h ./core/struct.h ./interface/menuItems/menuItems.h
	
#Compilation
main : 
			$(CC) -o publiSH $(OBJ) $(CFLAGS) $(LDFLAGS) 

#Developpment
dev_all:
			notepad-plus-plus $(OBJ) $(HEADER) ./Makefile
dev_c:
			notepad-plus-plus $(OBJ)
dev_h:
			notepad-plus-plus $(HEADER)
			
#Clean
clean : 
			rm -f $(OBJ)  $(EXE)
			