#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX_PRINT_LENGTH 50

typedef struct node Node;

Node * ListNew();
void ListDestroy(Node * l);

Node * ListInsertStart(Node * l, int item);
Node * ListInsertEnd(Node * l, int item);
int ListGetStartItem(Node * l);
int ListGetEndItem(Node * l);
Node * ListRemoveStart(Node * l);
Node * ListRemoveEnd(Node * l);

int ListSize(Node * l);
bool ListIsEmpty(Node * l);

Node * ListReverse(Node * l);

char * ListToString(Node * l); // Used for testing only
void ListDisplay(Node * l); // Used for debugging only

#endif