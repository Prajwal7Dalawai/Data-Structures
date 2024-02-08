/* Write a C program to implement stack operations using Ouput Restricted Deque (double 
ended queue) works.
insertqfront(), insertqrear(), remvleft(), displayq() */

#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],f=-1,r=-1;
int isempty()
{
    if( f==-1 && r==-1 )
    return 1;   
    else
    return 0;
}
int isfull()
{
    if ( (f==0 && r==size-1) || (f==r+1) )
    return 1;
    else
    return 0;
}
void insertqfront(int ele)
{
    if(isfull())
    {
        printf("No more elements can fit in the queue.\n");
        return;
    }
    else
    if(isempty())
    {
        f=0;
        r=0;
        queue[f]=ele;
        return;
    }
    else
    if(f==0)
    {
        f=size-1;
        queue[f]=ele;
        return;
    }
    else
    {
        queue[--f]=ele;
        return;
    }
}

void insert_rear(int ele)
{
    if(isfull())
    {
        printf("No more elements can fit in the queue.\n");
        return;
    }
    if(isempty())
    {
        f=r=0;
        queue[r]=ele;
        return;
    }
    if(r==size-1)
    {
        r=0;
        queue[r]=ele;
        return;
    }
    else
    {
        queue[++r]=ele;
        return;
    }
}

void remvleft()
{
    if(isempty())
    {
        printf("Nothing to delete.\n");
        return;
    }
    else
    if(f==r)
    {
        printf("The deleted item is %d\n",queue[f]);
        f=r=-1;
    }
    else
    if(f==size-1)
    {
        printf("The deleted element is %d\n",queue[f]);
        f=0;
        return;
    }
    else
    {
        printf("The deleted element is %d\n",queue[f++]);
        return;
    }
}

int main()
{
    int choice,ele;
    printf("DOUBLE ENDED QUEUE AS A STACK IMPLEMENTATION.\n");
    for(;;)
    {
        printf("1.Insert front  \t2.Insert rear  \t3.Delete front  \t4.Display  \t5.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                insertqfront(ele);
                printf("f=%d\nr=%d\n",f,r);
                break;
        case 2: printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                insert_rear(ele);
                printf("f=%d\nr=%d\n",f,r);
                break;
        case 3: remvleft();
                printf("The f=%d\nr=%d\n",f,r);
                break;
        case 4: display();
                break;
        default: exit(0);
            break;
        }
    }
    return 0;
}