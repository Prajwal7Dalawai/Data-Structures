/* Write a C program to construct a binary search tree and perform the following operations.
i. Search an element
ii. Inorder traversal
iii. postorder traversal
iv. preorder traversal*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rlink,*llink;
};
typedef struct node *NODE;
NODE createnode(int ele)
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
    ptr->data=ele;
    ptr->rlink=ptr->llink=NULL;
    return ptr;
}
NODE construct_tree(NODE root,int ele)
{
     NODE temp=createnode(ele);
    if(root==NULL)
        return temp;
    else
    {
       if(ele<root->data)
       root->llink=construct_tree(root->llink,ele);
       else
       if(ele>root->data)
       root->rlink=construct_tree(root->rlink,ele);
       return root;
}
}
void Inorder(NODE root)
{
    if(root==NULL)
    return;
    else
    {
        Inorder(root->llink);
        printf("%d\t",root->data);
        Inorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if(root==NULL)
    return;
    else
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->data);
    }
}
void preorder(NODE root)
{
    if(root==NULL)
    return;
    else
    {
        printf("%d\t",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
int main()
{
    NODE first=NULL;
    int ele,choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Inorder\t3.Preorder\t4.Postorder\t5.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter element; ");
        scanf("%d",&ele);
        first=construct_tree(first,ele);
            break;
        case 2: Inorder(first);
        break;
        case 3:preorder(first);
            break;
            case 4: postorder(first);
            break;
            case 5:exit(0);
        }
    }
}
