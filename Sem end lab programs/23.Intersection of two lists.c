//WAMCP to do the intersection of two linked lists.
#include<stdio.h>
#include<stdlib.h>
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
NODE insert(NODE root,int ele)
{
    NODE temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    return temp;
    else
    {
        NODE cur=root;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=temp;
        return root;
    }
}
void intersect(NODE first, NODE second)
{
    if(first==NULL || second==NULL)
    {
        printf("No common elements.\n");
        return;
    }
    else
    {
        NODE cur1=first,cur2;
        printf("\nThe intersection of the two list is:\n");
        while(cur1!=NULL)
        {
            cur2=second;
            while(cur2!=NULL)
            {
                if(cur2->data==cur1->data)
                printf("%d\n",cur2->data);
                cur2=cur2->link;
            }
            cur1=cur1->link;
        }
        return;
    }
}
int main()
{
    NODE first=NULL,second=NULL;
    int i,ele;
    printf("Enter the elements of first list:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&ele);
        first=insert(first,ele);
    }
     printf("Enter the elements of second list:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&ele);
        second=insert(second,ele);
    }
    intersect(first,second);
    return 0;
}

