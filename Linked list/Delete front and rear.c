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

NODE delete_front(NODE first)
{
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return NULL;
    }
    else if(first->link==NULL)
    {
        printf("The deleted element is %d\n",first->data);
        free(first);
        return NULL;
    }
    else
    {
    NODE cur=first;
    printf("The deleted element is %d\n",cur->data);
    first=cur->link;
    free(cur);
    return first;
    }
}

NODE delete_rear(NODE first)
{
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return NULL;
    }
    else if(first->link==NULL)
    {
        printf("The deleted element is %d\n",first->data);
        free(first);
        return NULL;
    }
    else
    {
        NODE cur=first, prev;
        while(cur->link!=NULL)
        {
        prev=cur;
        cur=cur->link;
        }
        printf("The deleted element is %d\n",cur->data);
        free(cur);
        prev->link=NULL;
        return first;
    }
}

int main()
{
    int ele,choice;
    NODE first=NULL;
    for(;;)
    {
        printf("LINKED LIST OPERATION MENU...\n");
        printf("1.INSERT\n2.DISPLAY\n3.DELETE FRONT\n4.DELETE REAR\n5.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first = insert_rear(first,ele);
        break;
        case 2: display(first); 
            break;
        case 3: first=delete_front(first);
        break;
        case 4: first=delete_rear(first);
        break;
        case 5: exit(0);
        }
    }
}