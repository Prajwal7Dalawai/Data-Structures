/*Write a C program to implement stack operations using input Restricted Deque (double 
ended queue) works.
insertqfront(), remvleft(), remvright(), displayq()*/

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

void remvright()
{
    if(isempty())
    {
        printf("Nothing to delete.\n");
        return;
    }
    else
    if(f==r)
    {
        printf("The deleted element is %d\n",queue[r]);
        f=r=-1;
        return;
    }
    else
    if(r==0)
    {
        printf("The deleted element is %d\n",queue[r]);
        r=size-1;
        return;
    }
    else
    {
        printf("The deleted element is %d\n",queue[r--]);
        return;
    }
}

void display()
{
    if(isempty())
    {
        printf("Nothing to display.\n");
        return;
    }
    else
    {
        int i=f;
        while(i!=r)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%size;
        }
        printf("%d\n",queue[i]);
        return;
    }
}
int main()
{
    int choice,ele;
    printf("DOUBLE ENDED QUEUE AS A STACK IMPLEMENTATION.\n");
    for(;;)
    {
        printf("1.Insert\t2.Delete front\t3.Delete rear\t4.Display\t5.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                insertqfront(ele);
                printf("f=%d\nr=%d\n",f,r);
                break;
        case 2: remvleft();
                printf("The f=%d\nr=%d\n",f,r);
                break;
        case 3: remvright();
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