/*Write a c function search(l,x) that accepts a pointer ‘l’ to a list of integers and an integer x 
and returns a pointer to a node containing x, if it exists and the null pointer otherwise. Write 
another function srchinsrt(l,x), that adds ‘x’ to ‘l’ if it is not found and always returns a 
pointer to a node containing ‘x’. Develop C program for the same.*/
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
NODE insert(NODE root, int ele)
{
    NODE temp;
    temp=createnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    {

        return temp;
    }
    else
    {
        NODE cur=root;
        while(cur->link!=NULL)
        cur=cur->link;
        cur->link=temp;;
        return root;
    }
}
NODE search(NODE l, int x)
{
    if(l==NULL)
    return NULL;
    else
    {
        NODE cur=l;
        while(cur!=NULL)
        {
            if(x==cur->data)
            break;
            else
            cur=cur->link;
        }
        if(cur==NULL)
        return NULL;
        else
        return cur;
    }
}

NODE searchinst(NODE l, int x)
{
    if(l==NULL)
    return NULL;
    else
    {
        NODE cur=l,prev;
        while(cur!=NULL)
        {
            prev=cur;
            if(x==cur->data)
            break;
            else
            cur=cur->link;
        }
        if(cur==NULL)
        {
            NODE temp=createnode();
            temp->data=x;
            temp->link=prev->link;
            prev->link=temp;
            return temp;
        }
        else
        return cur;
}
}
void display(NODE root)
{
    if(root==NULL)
    {
        printf("List is empty.");
        return;
    }
    else
    {
        NODE cur=root;
        printf("DATA\tLINK\n");
        while(cur!=NULL)
        {
            printf("%d\t%p\n",cur->data,cur->link);
            cur=cur->link;
        }
        return;
    }
}
int main()
{
    NODE first=NULL;
    int ele,choice,key;
    for(;;)
    {
        printf("1.Insert\t2.Search(l,x)\t3.Searchinst(l,x)\t4.Display\t5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted.\n");
                    scanf("%d",&ele);
                    first=insert(first,ele);
                    break;
            case 2: printf("Enter the element to be searched.\n");
                    scanf("%d",&key);
                    printf("The pointer containing the %d is %p\n",key,search(first,key));
                    break;
            case 3:printf("Enter the element to be searched.\n");
                    scanf("%d",&key);
                    printf("The pointer containing the %d is %p\n",key,searchinst(first,key));
                    break;
            case 4: display(first);
            break;
            case 5: exit(0);
        }
    }
}