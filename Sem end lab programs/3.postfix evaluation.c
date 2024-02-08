//WACP to evaluate postfix expression.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define size 10
char stack[size];
int top=-1;

float evaluate(float a, float b,char op)
{
    switch(op)
    {
        case '+': return a+b;
        break;
        case '-': return a-b;
        break;
        case '*': return a*b;
        break;
        case '/': return a/b;
        break;
        case '^': return pow(a,b);
        break;
    }
}
float postfix_eval(char expression[])
{
    int i;
    char ch;
    float a,b,eval;
    for(i=0;expression[i]!='\0';i++)
    {
        ch=expression[i];
        if(isdigit(ch))
        stack[++top]=ch - '0';
        else
        {
            b=stack[top--];
            a=stack[top--];
            eval=evaluate(b,a,ch);
            stack[++top]=eval;
        }
    }
    return stack[top];
}

int main()
{
    char postfix[size];
    printf("Enter the postfix expression:\n");
    scanf("%s",postfix);
    printf("The postfix evaluation of %s is %.2f\n",postfix,postfix_eval(postfix));
    return 0;
}
