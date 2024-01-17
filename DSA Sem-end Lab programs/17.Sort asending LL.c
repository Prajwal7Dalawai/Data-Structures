//Write a C program to create an ordered (ascending) linked list for the given set of data.
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
typedef struct node *NODE;
NODE rear,front=NULL;
NODE createnode ()                   //NODE CREATION
{
  NODE ptr;
  ptr = (NODE) malloc (sizeof (struct node));
  return ptr;
}
NODE insert(NODE root, int ele)
{
    NODE temp;
    temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL || root->data>=temp->data)
    {
        temp->link=root;
        return temp;
    }
    else
    {
        NODE cur=root;
        while(cur->link!=NULL && cur->link->data < temp->data)
        cur=cur->link;
        temp->link=cur->link;
        cur->link=temp;
        return root;
    }
}

void display(NODE root)
{
    if(root==NULL)
    {
        printf("List is empty.");
        return;
    }
    else
    {
        NODE cur=root;
        printf("DATA\tLINK\n");
        while(cur!=NULL)
        {
            printf("%d\t%p\n",cur->data,cur->link);
            cur=cur->link;
        }
        return;
    }
}
int main()
{
    NODE first=NULL;
   int choice,ele;
    for(;;)
    {
        printf("1.Insert\t2.Display\t3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted.\n");
                    scanf("%d",&ele);
                    first=insert(first,ele);
                    break;
            case 2: display(first);
            break;
            case 3: exit(0);
        }
    }
    return 0;
}