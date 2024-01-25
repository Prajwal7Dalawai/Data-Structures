//WAMCP to find the union of the list.
#include<stdio.h>
#include<stdlib.h>
int res[10],top=-1;
struct node{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE createnode()
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
    return ptr;
}
NODE insert(NODE root, int ele)
{
    NODE temp;
    temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    return temp;
    else
    {
        NODE cur=root;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=temp;;
        return root;
    }
}
void push(int ele)
{
    res[++top]=ele;
    return;
}
void Union(NODE first, NODE second)
{
    if(first==NULL)     //If first list is empty, then push all the elements of second list into the resultant set
    {
        NODE cur2=second;
        while(cur2!=NULL)
        {
            push(cur2->data);
            cur2=cur2->link;
        }
        return;
    }
    else
    if(second==NULL)        //If second list is empty, then push all the elements in the first list to the resultant set
    {
        NODE cur1=first;
        while(cur1!=NULL)
        {
            push(cur1->data);
            cur1=cur1->link;
        }
        return;
    }
    else
    {
        NODE cur1,cur2;
        int match,i;
        cur1=first;
         while(cur1!=NULL)      //Push all the elements of the first list into the resultant set
        {
            push(cur1->data);
            cur1=cur1->link;
        }
       int n=top;
       cur2=second;
       while(cur2!=NULL)          //Comparing each value of the second list with the resultant set.
       {
        match=0;
        for(i=0;i<n;i++)        //Comapring the individual element of the second set with all the elements in resultant set.
        {
            if(cur2->data==res[i])      //If match between anyone element is found, then inner for loop iteration will be stopped.
            match=1;                //and thst element is not pushed into the resultant set.
            if(match==1)
            break;
        }
        if(match==0)        //if no match is found in the iteration, then the element of the second list is pushed into the resultant set.
        push(cur2->data);
        cur2=cur2->link;
       }
       return;
    }
}
void display()
{                           //Displaying the resultant set
    int i;
    for(i=0;i<=top;i++)
    printf("%d\n",res[i]);
    return;
}
int main()
{
    int i,ele;
    NODE first=NULL,second=NULL;
    printf("Enter the elements of the first list.\n");
    for(i=0;i<5;i++)            //Inserting elements in the first list
    {
    scanf("%d",&ele);
    first=insert(first,ele);
    }
    printf("Enter the elements of second list:\n");
    for(i=0;i<5;i++)                //Inserting element in second list
    {
        scanf("%d",&ele);
        second=insert(second,ele);
   }
   Union(first,second);
   printf("The union of two list are:\n");
   display();
   return 0;
}