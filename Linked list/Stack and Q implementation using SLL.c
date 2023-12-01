//WACP to implement stacks and queue using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
typedef struct node *NODE;
NODE rear,front=NULL;
NODE createnode ()                   //NODE CREATION
{
  NODE ptr;
  ptr = (NODE) malloc (sizeof (struct node));
  return ptr;
}

NODE push (NODE top, int ele)        //PUSH OPERATION OF STACK
{
  NODE temp = createnode ();
  temp->data = ele;
  if (top == NULL)
    temp->link = NULL;
  else
    temp->link = top;
  top = temp;
  return top;
}

NODE pop (NODE top)                  //POP OPERATION OF STACK
{
  NODE temp = top;
  if (top == NULL)
    {
      printf ("Nothing to delete.\n");
      return top;
    }
  else
    {
      printf ("The deleted element is %d\n\n", top->data);
      top = temp->link;
      free (temp);
      return top;
    }
}

void
stack_display (NODE top)                //DISPLAY OPERATION OF STACK
{
  NODE temp;
  if (top == NULL)
      printf ("Nothing to display.\n");
      else
      {
        temp = top;
        printf ("DATA\tLINK\n");
        while (top!= NULL)
          {
            printf ("%d\t%p\n",top->data,top->link);
            top = top->link;
          }
        top=temp;
      }
    }
  void stack ()                     //STACK OPERATIONS MENU
  {
    NODE top = NULL;
    int ele, choice;
    printf ("STACK OPERATIONS\n");
    for (;;)
      {
        printf ("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        scanf ("%d", &choice);
        switch (choice)
          {
          case 1:
            printf ("Enter the element to be inserted.\n");
            scanf ("%d", &ele);
            top = push (top, ele);
            break;
          case 2:
            top = pop (top);
            break;
          case 3:
            printf ("The contents of stack are:\n");
            stack_display (top);
            break;
          case 4:
            exit (0);
          }
      }
  }
void qinsert(int ele)                //INSERT OPERATION OF QUEUE
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(front==NULL)
    {
        front=rear=temp;
        return;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }   
}
void qdelete()
{
    if (front==NULL)
    {
        printf("Nothing to delete.\n");
        return;
    }
    else
    {
        NODE temp=front;
        front=front->link;
        printf("Deleted element is %d\n",temp->data);
        free(temp);
    }
}
void qdisplay()
{
    if(front==NULL)
    {
        printf("No elements to display.\n");
        return;
    }
    else
    {
        NODE temp=front;
        printf("DATA\tLINK\n");
        while(front!=rear)
        {
            printf("%d\t%p\n",front->data,front->link);
            front=front->link;
        }
        printf("%d\t%p\n",front->data,front->link);
        front=temp;

    }
}
void queue()                                  //QUEUE OPERATIONS MENU
{
int choice,ele;
printf("QUEUE OPERATIONS\n\n");
for(;;)
    {
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted.\n");
            scanf("%d",&ele);
            qinsert(ele);
            break;
            case 2: qdelete();
            break;
            case 3:
            printf("The elements are:\n");
            qdisplay();
            break;
            case 4:exit(0);
        }
    }
}

int main ()
{
    int mchoice;
    printf ("1.STACK IMPLEMENTATION\n2.QUEUE IMPLEMENTATION\n3.EXIT\n");
    scanf ("%d", &mchoice);
    switch (mchoice)
      {
        case 1:stack ();
        break;
        case 2:
        queue();
        break;
        case 3:exit(0);

      }
      return 0;
}