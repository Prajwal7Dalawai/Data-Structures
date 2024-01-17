//WACP to convert infix expression into infix expression.
#include<stdio.h>
#include<stdlib.h>
#define size 20
char stack[size],result[size];
int top=-1;

int precedence(char ch)
{
    switch (ch)
    {
    case '(': return 1;
    case '+': 
    case '-': return 2;
    case '*':
    case '/':
    case '%': return 3;
    case '^':return 4;
    }
}

void evaluate(char infix[])
{
    int i,j=0;
    char ch,c;
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(isalpha(ch) || isdigit(ch))
        result[j++]=ch;
        else
        {
            if(top==-1 || ch=='(')
            stack[++top]=ch;
        else if(ch==')')
        {
            while((c=stack[top--])!='(')
            result[j++]=c;
        }
        else
            if(precedence(ch)<=precedence(stack[top]))
            {
                result[j++]=stack[top--];
                stack[++top]=ch;
            }
        else
            if(precedence(ch)>precedence(stack[top]))
            stack[++top]=ch;
        }
    }
    while(top != -1)
        result[j++]=stack[top--];
        result[j]='\0';
        printf("The postfix expression of %s is %s\n",infix,result);
        return;
}

main()
{
    char infix[size];
    printf("Enter the postfix expression:\n");
    scanf("%s",infix);
    evaluate(infix);
}