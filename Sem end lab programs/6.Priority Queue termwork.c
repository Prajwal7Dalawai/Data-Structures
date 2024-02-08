//WACP to implememnt priority queues using 3 queues.
#include<stdio.h>
#include<stdlib.h>
#define size 3
int q1[size], q2[size], q3[size], r1 = -1, r2 = -1, r3 = -1, f1 = 0, f2 =0, f3 = 0, count1 = 0, count2 = 0, count3 = 0,count;
insertq1 (int ele)
{
  q1[++r1] = ele;
  count1++;
  return;
}

insertq2 (int ele)
{
  q2[++r2] = ele;
  count2++;
  return;
}

insertq3 (int ele)
{
  q3[++r3] = ele;
  count3++;
  return;
}

void
insert (int ele)
{
  if (count==3*size)
    {
      printf ("Queue is full.\n");
      exit;
    }
  else
    {
      if (r1 < size)
        {
          insertq1 (ele);
          return;
        }
      else
        {
          if (r2 < size)
            {
              insertq2 (ele);
              return;
            }
          else
            {
              if (r3 < size)
                {
                 insertq3 (ele);
                  return;
                }
                }
            }
        }
}


int
delete ()
{
  if (count==0)
    {
      printf ("Nothing to delete.\n");
      return 0;
    }
  else
    {
      if (count1 > 0)
        {
          count1--;
          return (q1[f1++]);
        }
      else if (count1 == 0 && count2 > 0)
        {
          count2--;
          return (q2[f2++]);
        }
      else if (count1 == 0 && count2 == 0 && count3 > 0)
        {
          count3--;
          return (q3[f3++]);
        }
    }
}

void
display ()
{
  int i;
  if (r1 == -1 || count==0)
    {
      printf ("Queue is empty.\n");
      return;
    }
  else
    {
      if (count3 > 0)
{
          for (i = f1; i <= r1; i++)
            printf ("%d\n", q1[i]);
          for (i = f2; i <= r2; i++)
            printf ("%d\n", q2[i]);
          for (i = f3; i <= r3; i++)
            printf ("%d\n", q3[i]);
          return;
        }
      else if (count2 > 0 && count3 == 0)
        {
          for (i = f1; i <= r1; i++)
            printf ("%d\n", q1[i]);
          for (i = f2; i <= r2; i++)
            printf ("%d\n", q2[i]);
          return;
        }
      if (count1 > 0 && count2 == 0 && count3 == 0)
        {
          for (i = f1; i <= r1; i++)
            printf ("%d\n", q1[i]);
          return;
        }
    }
}

int main ()
{
  int choice, ele;
  printf ("Priority Queue menu..\n");
  for (;;)
    {
      count=count1+count2+count3;
      printf ("1.Insert\n2.Delete\n3.Display\n");
      scanf ("%d", &choice);
      switch (choice)
        {
        case 1:
          printf ("Enter the element to be inserted.\n");
          scanf ("%d", &ele);
          insert (ele);
          break;
        case 2:
          printf ("The deleted element is %d\n", delete ());
          break;

        case 3:
          display ();
          break;
        case 4: exit(0);  
        }
    }
    return 0;
}
