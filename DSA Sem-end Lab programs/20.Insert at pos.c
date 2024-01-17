// Write a c program to insert an element at a given position of the linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE createnode()
{
    NODE ptr = (NODE)malloc(sizeof(struct node));
    return ptr;
}
NODE  insert(NODE first,int ele)
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        printf("The first node has been inserted. The date inserted is %d\n\n",temp->data);
        return temp;
    }
    else
    {
        NODE cur=first;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=temp;
        printf("The element %d has been inserted and its link is %p\n\n",temp->data,temp->link);
        return first;
    }
}

void display(NODE first)
{
    if(first==NULL)
    {
        printf("Empty list\n\n");
        return;
    }
    else
    {
        NODE cur=first;
        printf("DATA\tLINK\n");
        while(cur->link!=NULL)
        {
            printf("%d\t%p\n",cur->data,cur->link);
            cur=cur->link;
        }
        printf("%d\t%p\n",cur->data,cur->link);
    }
}
NODE insertposition(NODE first,int pos,int ele)
{
    NODE cur=first,prev=NULL,temp=createnode();
    int count=1;
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL && pos==1)
    return temp;
    while(cur->link!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->link;
        count++;
    }
    if(count==pos)
    {
    prev->link=temp;
    temp->link=cur;
    return first;
    }
    if(cur==NULL && pos!=count)
    {
        printf("Invalid position\n");
        return first;
    }
}

    int main()
{
    int ele,choice,pos;
    NODE first=NULL;
    for(;;)
    {
        printf("LINKED LIST OPERATION MENU...\n");
        printf("1.INSERT\n2.DISPLAY\n3INSERT AT POSITION\n4.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first = insert(first,ele);
        break;
        case 2: display(first); 
            break;
        case 3: 
        printf("Enter the position:\n");
        scanf("%d",&pos);
        printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first=insertposition(first,pos,ele);
        break;
        case 4: exit(0);
        }
    }
    return 0;
}
