/*WAC program to convert infix to postix expression.
1.If the character is left parenthesis, push to the stack.
2.If the character is an operand, add to the postfix expression.
3.If the character is an operator, Check whether the stack is empty.
 a. If empty stack, push the operator into the stack. 
 b. If not empty, then check for the precedence/ priority.
 c. If priority of the operator is greater than the operator on top of the stack, then push the operator into the stack.
 d. If priority of operator is less than or equal to the operator present at top of the stack, then pop the operator from the stack, and add it to the postfix expression.
4. If the character is right parenthesis, then pop all the operators of the stack until it reaches left parenthesis, and add it to the postfix expression.
5.After reading all the inputs if stack is not empty, then pop all the operators from the stack and add to postfix until stack becomes empty.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 30
struct infpost
{
    char stack[size];
    int top;
};
void push(struct infpost *s,char item)
{
    s->stack[++(s->top)]=item;
}
char pop(struct infpost *s)
{
    return s->stack[(s->top)--];
}
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
int main()
{
    struct infpost s;
    char exp[size],postfix[size],ch,c;
    int i,n,j=0;
    s.top= -1;
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        ch=exp[i];
        if (ch=='(')
        {
            push(&s,ch);
        }
        else
        if(isalpha(ch) || isdigit(ch))
        postfix[j++]=ch;
        else
        if(ch==')')
        {
            while(c=pop(&s)!='(')
            {
                postfix[j++]=c;
            }
        }
        else
        {
           if(s.top== -1)
           push(&s,ch);
           else
           {
            while(precedence(ch)<precedence(s.top) && s.top!= -1)
        
            {
                postfix[j++]=pop(&s);
            }
            push(&s,ch);
           }
        }
    }
        while (s.top!= -1)
        {
            postfix[j++]=pop(&s);
            postfix[j]='\0';
        }      
   printf("The postfix expression is : %s\n",postfix);    
   return 0;
}
