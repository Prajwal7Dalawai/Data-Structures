// Write a c program to delete an element from the given position of the linked list.
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
void delete(NODE root, int pos)
{
    if(root==NULL)
    {
        printf("NOthing to delete.\n");
        return;
    }
    else
    {
        NODE cur=root,prev;
        int i=1;
        while(i!=pos)
        {
            prev=cur;
            cur=cur->link;
            i++;
        }
        NODE temp=cur;
        prev->link=cur->link;
        free(temp);
        return;
    }
}
int main()
{
    NODE first=NULL;
    int ele,choice,pos;
    for(;;)
    {
        printf("1.Insert\t2.Delete at position\t3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number to be inserted: ");
            scanf("%d",&ele);
            first=insert(first,ele);
            break;
            case 2: printf("Enter the position to be deleted: ");
            scanf("%d",&pos);
            delete(first,pos);
            break;
            case 3: display(first);
            break;
            case 4: exit(0);
        }
    }
    return 0;
}