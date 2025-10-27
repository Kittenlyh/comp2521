#include <stdlib.h>
#include <assert.h> 
#include <stdio.h>
#include <string.h>
#include "list.h" 

struct node {
    int data;
    struct node * next;
};//链表的基本结构
static Node * create_node(int item);
Node * ListNew() {
    // TODO
    return NULL;
}

void ListDestroy(Node * l) {
    // TODO
}

Node * ListInsertStart(Node * l, int item) {
    // TODO
    Node *n=create_node(item);
    n->next=l;
    return n;
}

Node * ListInsertEnd(Node * l, int item) {
    // TODO
    Node *n=create_node(item);
    if(l==NULL) return n;
    //想要遍历到最后只需要添加一个新的节点就可以了
    Node *curr=l;
    while(curr->next!=NULL){
        curr=curr->next; 
        //没找到就一直下一个
    }
    curr->next=n;
    return l; //返回链表头
}

Node * ListRemoveStart(Node * l) {
    assert(!ListIsEmpty(l));
    // TODO
    Node *n=l->next;
    free(l);
    return n;
}

Node * ListRemoveEnd(Node * l) {
    assert(!ListIsEmpty(l));
    // TODO
    //一定要考虑多种情况
    Node *curr=l;
    Node *prev=NULL;

    //链表只有一个节点
    if(l->next==NULL){
        free(l);
        return NULL;
    }
    //多节点
    while (curr->next!=NULL)//next是null退出循环
    {
        //遍历中
        prev=curr;
        curr=curr->next;
    }
    free(curr);
    prev->next=NULL;
    return l;
}

int ListSize(Node * l) {
    // TODO
    int count=0;
    Node *curr=l;
    while (curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    
    return count;
}

bool ListIsEmpty(Node * l) {
    // TODO
    if(l==NULL) return true;
    else return false;
}

Node * ListReverse(Node * start) {
    // TODO
    if(start==NULL||start->next==NULL) return start;
    Node *res=ListReverse(start->next);
    start->next->next=start;
    start->next=NULL;
    return res;
}

char * ListToString(Node * l) {
    char * s = calloc(MAX_PRINT_LENGTH+1, sizeof(char));
    Node * curr = l;
    char snum[5];
    while (curr != NULL) {
        snprintf(snum, 5, " %d", curr->data);
        strncat(s, snum, MAX_PRINT_LENGTH);
        curr = curr->next;
    }
    return s;
}

void ListDisplay(Node * l) {
    // TODO
    Node *curr=l;
    while (curr!=NULL)
    {
        printf("%d",curr->data);
        printf("->");
        curr=curr->next;
    }
    printf("NULL\n");
}

// Helper Functions

static Node * create_node(int item) {
    // TODO
    Node    *new_node=malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    return new_node;
}

