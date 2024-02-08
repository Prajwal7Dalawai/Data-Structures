/* Write a C program to to remove dupliactes from given list of n elements.*/
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

int main() {
    int n, i, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    NODE root = NULL;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = construct_tree(root, data);
    }
    printf("\nUnique elements in the list: ");
    Inorder(root);
    return 0;
}
