#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE createnode()
{
    NODE ptr;
    ptr=(NODE *)malloc(sizeof(struct node));
    return ptr;
}
NODE insertrear(NODE first, int ele)
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        printf("The first element has been inserted\n");
        return temp;
    }
    else
    {
        NODE cur=first;
        while(cur->link==NULL)
        cur=cur->link;
        cur->link=temp;
        return first;
    }
}
    main()
    {
        NODE first=NULL,rear;
        int ele,choice;
        for(;;)
        {
            printf("Do you want to insert element?\n");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1: printf("Enter the element to be insrted.\n");
            scanf("%d",&ele);
            rear=insertrear(first,ele);
            printf("The element inserted is %d and the link is %p\n",rear->data,rear->link);
            printf("%p\n",rear);
            break;
            case 2:exit(0);
            }
        }
    }