// Write C program to implement an Descending Priority Queue accepting integers as an input and ensure priority at the time of insertion

#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],f=0,r=-1;
int isempty()
{
    if( f > r )
    return 1;   
    else
    return 0;
}
int isfull()
{
    if ( r == size-1 )
    return 1;
    else
    return 0;
}
void insert(int ele)
{
    int i;
    if(isfull())
    {
        printf("No space to insert.\n");
        return;
    }
    else if(isempty())
    {
        queue[++r]=ele;
        return;
        }
    else
    {
            i=r;
            while(i>=0 && ele>queue[i])
            {
            queue[i+1]=queue[i];
            i--;
            }
            queue[i+1]=ele;
            r=r+1;
            printf("The element %d has been entered.\n",queue[i+1]);
            return;
    }
}
void delete()
{
    if(isempty())
    {
        printf("Nothing to delete.\n");
        return;
    }
    else
    {
        printf("The deleted element is %d\n",queue[f++]);
        return;
    }
}
void display()
{
    int i;
    if(isempty())
    {
        printf("Nothing to display.\n");
        return;
    }
    else
    {
    for(i=f;i<=r;i++)
    {
        printf("%d\n",queue[i]);
    }
    return;
    }
}

int main()
{
    int choice,ele;
    printf("DESCENDED PRIORITY QUEUE OPERATIONS..\n");
    for(;;)
    {
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted.\n");
            scanf("%d",&ele);
            insert(ele);
            break;
        case 2: delete();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        }
    }
    return 0;
}