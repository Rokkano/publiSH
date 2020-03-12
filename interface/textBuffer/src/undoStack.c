#include <gtk/gtk.h>
#include "../../infoBar/infoBar.h"
#include "../../../core/struct.h"
#include <stdlib.h>
#include <stdio.h>

struct stackNode *undoStack_initNode()
{
	struct stackNode *temp = malloc(sizeof(struct stackNode));
	return temp;
}

void undoStack_stack(struct stackNode *st,const char* value, int x, int y)
{
	//Create the Node
	struct stackNode *new = malloc(sizeof(struct stackNode));
	new->value = value;
	new->x = x;
	new->y = y;
	new->next = NULL;
	
	//Put it in the right place
	struct stackNode* temp = st;
	for(;temp->next!=NULL;temp=temp->next);
	temp->next = new;
}

void undoStack_unStack(struct stackNode *st)
{
	struct stackNode *temp = st;
	if (st==NULL)
		return;
	if(st->next==NULL)
	{
		free(st->next);
		st->next=NULL;
		return;
	}
	for(;temp->next->next!=NULL;temp=temp->next);
	free(temp->next);
	temp->next = NULL;
}

void undoStack_print(struct stackNode *st)
{
	if (st==NULL)
		return;
	for(struct stackNode *temp = st; temp!= NULL; temp = temp->next)
		printf("- %s \n",temp->value==NULL?" ":temp->value);
	printf("\n");
}