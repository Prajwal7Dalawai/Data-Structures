//WAMCP to do the intersection of two linked lists.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE createnode()
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
    return ptr;
}

