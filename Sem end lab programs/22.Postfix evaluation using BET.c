//WACP to construct binary tree expression tree for a given postfix expression and evaluate the expression and print the result

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char data;
    struct node *rlink, *llink;
};
typedef struct node *NODE;

NODE createnode(char ch)
{
    NODE ptr=(NODE)malloc(sizeof(struct node));     //Creation of the node
    ptr->data=ch;
    ptr->llink=ptr->rlink=NULL;
    return ptr;
}

NODE construct_bst(char postfix[])
{                                       // Construction of BST
    NODE stack[100];
    int top=-1,i=0;
    while (postfix[i]!='\0')
    {
        char ch=postfix[i];
        if(isalpha(ch))                 //Checking if an operand
        {
            NODE newnode=createnode(ch);
            stack[++top]=newnode;
        }
        else
        {
            NODE newnode=createnode(ch);
            newnode->rlink=stack[top--];       //Case for operator
            newnode->llink=stack[top--];
            stack[++top]=newnode;
        }
        i++;
    }
    return stack[top--];
}

float evaluate_bst(NODE root)
{                                   // Evaluation of BST
    float num;
    while (root!=NULL)
    {
        switch (root->data)
        {
        case '+': return evaluate_bst(root->rlink) + evaluate_bst(root->llink);
            break;
        case '-': return evaluate_bst(root->rlink) - evaluate_bst(root->llink);
            break;
        case '*': return evaluate_bst(root->rlink) * evaluate_bst(root->llink);
            break;
        case '/':return evaluate_bst(root->rlink) / evaluate_bst(root->llink);
            break;
        default: if(isalpha(root->data))
        {
            printf("%c=",root->data);
            scanf("%f",&num);
            return num;
        }
        else{
            return root->data -'0';
        }
            break;
        }
    } 
}

int main()
{
    NODE root=NULL;                  //Main Function
    char postfix[20];  
    printf("Enter the expression:\n");
    scanf("%s",postfix);
    root=construct_bst(postfix);
    printf("The result of the postfix expression is: %.2f\n",evaluate_bst(root));
    return 0;
}