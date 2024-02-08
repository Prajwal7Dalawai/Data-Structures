//WACP to implement circular queue
#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size],f=0,r=-1,count=0;
int isempty()
{
    if(count==0)
    return 1;   
    else
    return 0;
}
int isfull()
{
    if(count==size-1)
    return 1;
    else
    return 0;
}
void insert(int ele)
{
    if(isfull())
    {
        printf("No space to insert.\n");
        return;
    }
    else
    {
        r=(r+1)%size;
        queue[r]=ele;
        count++;
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
        count--;
        printf("The deleted element is %d\n",queue[f]);
        f=(f+1)%size;
        return queue[f];
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
       for(i=0;i<=count;i++)
        {
            printf("%d\n",queue[f]);
            f=(f+1)%size;
        }
        }
    }

main()
{
    int choice,ele;
    printf("CIRCULAR QUEUE OPERATIONS..\n");
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
}