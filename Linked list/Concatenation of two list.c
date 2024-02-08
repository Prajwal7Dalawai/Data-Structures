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

NODE insert_front(NODE first,int ele)
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=first;
    printf("The element %d has been inserted and its link is %p\n\n",temp->data,temp->link);
    return temp;
}

NODE  insert_rear(NODE first,int ele)
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
NODE concatenate(NODE first, NODE second)
{
    if(first==NULL)
    return second;
    else if(second==NULL)
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
int main()
{
    int ele,choice;
    NODE first=NULL,second=NULL;
    for(;;)
    {
        printf("LINKED LIST OPERATION MENU...\n");
        printf("1.INSERT First\t2.Insert second\t3.Concatenate\t4.DISPLAY\t5.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted in first list:\n");
        scanf("%d",&ele);
        first=insert_rear(first,ele);
        break;
        case 2: printf("Enter the element to be inserted second list:\n");
        scanf("%d",&ele);
        second=insert_rear(second,ele);
        break;
        case 3: first=concatenate(first,second);break;
        case 4: display(first); 
            break;
        case 5:exit(0);
        }
    }
    return 0;
}
