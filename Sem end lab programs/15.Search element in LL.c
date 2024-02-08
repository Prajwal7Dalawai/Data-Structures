/* Write a C program to search an element in the list and print the position of the element if 
found otherwise add the element to the list.*/
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
void search(NODE root, int key)
{
    if(root==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    else
    {
        int pos=0;
        NODE cur=root;
        while(cur!=NULL)
        {
            pos++;
            if(key==cur->data)
            break;
            else
            cur=cur->link;
        }
        if(cur==NULL)
            printf("Search Unsuccessfull. Element not found.\n");
        else
            printf("The element %d is located at position %d\n",key,pos);
        return;
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
    int ele,choice,key;
    for(;;)
    {
        printf("1.Insert\t2.Search\t3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted.\n");
                    scanf("%d",&ele);
                    first=insert(first,ele);
                    break;
            case 2: printf("Enter the element to be searched.\n");
                    scanf("%d",&key);
                    search(first,key);
                    break;
            case 3: display(first);
            break;
            case 4: exit(0);
        }
    }
}