//Write a C program to concatenate two singly linked lists and display the result.
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE createnode()
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
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

NODE concatenate(NODE first, NODE second)
{
    if(first==NULL)
    return second;
    else
    if(second==NULL)
    return first;
    else
    {
        NODE cur=first;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=second;
        return first;
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
        while(cur->link!=NULL)
        {
            printf("%d\t%p\n",cur->data,cur->link);
            cur=cur->link;
        }
        printf("%d\t%p\n",cur->data,cur->link);
    }
}
int main()
{
    NODE first=NULL,second=NULL;
    int choice,ele;
    for(;;)
    {
    printf("1.Insert first  \t2.Insert Second  \t3.Concatenate  \t4.Display\t  5.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the element in the first list: ");
                scanf("%d",&ele);
                first=insert(first,ele);
                break;
        case 2: printf("Enter the element in the second list: ");
                scanf("%d",&ele);
                second=insert(second,ele);
                break;
        case 3: first=concatenate(first,second);
                break;
        case 4: display(first);
                break;
        case 5: exit(0);
    }
    }    
    return 0;   
}