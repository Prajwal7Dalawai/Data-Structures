#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE createnode()
{
    NODE ptr=(NODE *)malloc(sizeof(struct node));
    return ptr;
}
NODE insertfront(NODE first,int ele)
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=first;
    return temp;
}
int main()
{
    NODE first=NULL;
    int ele,i;
    int choice;
    printf("%d",sizeof(struct node));
    for(;;)
    {
        printf("Do you want to insert the element?\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter the element to be inserted.\n");
        scanf("%d",&ele);
        first=insertfront(first,ele);
        printf("element inserted is %d and link is %p\n",first->data,first->link);
         printf("%p\n",first);
        break;
        case 2: exit(0);
        }
    }
    return 0;
}
