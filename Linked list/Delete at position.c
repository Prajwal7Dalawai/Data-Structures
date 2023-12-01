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

NODE delete_at_position(NODE first,int key)
{
    NODE prev=NULL,cur=first;
    int count=1;
    if(first->link==NULL && first->data==key)
    {
        printf("Deleted first element.\n");
        free(cur);
        return NULL;
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->data==key)
            {
                prev->link=cur->link;
                free(cur);
                return first;
            }
            prev=cur;
            cur=cur->link;
        }
    }
}
 int main()
{
    int ele,choice,key;
    NODE first=NULL;
    for(;;)
    {
        printf("LINKED LIST OPERATION MENU...\n");
        printf("1.INSERT\n2.DISPLAY\n3.INSERT BEFORE\n4.INSERT AFTER\n5.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first = insert_rear(first,ele);
        break;
        case 2: display(first); 
            break;
        case 3: 
        printf("Enter the key:\n");
        scanf("%d",&key);
        printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first = insert_before(first,key,ele);
        break;
        case 4:
        printf("Enter the key:\n");
        scanf("%d",&key);
        printf("Enter the element to be inserted:\n");
        scanf("%d",&ele);
        first = insert_after(first,key,ele);
        break;
        case 5: exit(0);
        }
    }
    return 0;
}