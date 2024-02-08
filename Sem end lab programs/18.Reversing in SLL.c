//Write a c program to reverse the elements of a given linked lists
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
void reverse(NODE root)
{
    if(root==NULL)
    {
    printf("List is empty.\n");
    return;
    }
    else
    {
        NODE rev=NULL,temp;
        while(root!=NULL)
        {
            temp=root;
            root=root->link;
            rev=temp;
        }
        return rev;
    }
}
NODE insert(NODE root, int ele)
{
    NODE temp;
    temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    {

        return temp;
    }
    else
    {
        NODE cur=root;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=temp;;
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
main()
{
    NODE first=NULL;
    int ele,choice;
    for(;;)
    {
        printf("1.Insert\t2.Reverse\t3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number to be inserted: ");
            scanf("%d",&ele);
            first=insert(first,ele);
            break;
            case 2: reverse(first);
            break;
            case 3: display(first);
            break;
            case 4: exit(0);
        }
    }
}