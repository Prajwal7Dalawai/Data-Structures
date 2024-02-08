//WACP to check whether the given expression is valid or not
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20
char stack[size];
int top=-1;

int match_parenthesis(char a, char b)
{
    if(a=='(' && b==')')
    return 1;
    else
    if(a=='[' && b==']')
    return 1;
    else
    if(a=='{' && b=='}')
    return 1;
    else
    return 0;
}
int check_parenthesis(char expression[])
{
    int i;
    char ch,temp;
    for(i=0;i<strlen(expression);i++)
    {
        ch=expression[i];
        if (ch=='(' || ch=='[' || ch=='{')
        stack[++top]=ch;
        if (ch==')' || ch=='}'|| ch==']')
        {
            if(top==-1)
            {
                printf("Right parenthesis is more than left parenthesis.\n");
                return 0;
            }
            else
            {
                temp=stack[top--];
                if(match_parenthesis(temp,ch)==0)
                {
                    printf("Equation has unbalanced parenthesis.\n");
                    return 0;
                    break;
                }
                else
                continue;
            }
        }
    }
    if(top==-1)
        {
            printf("The equation has balanced parenthesis.\n");
            return 1;
        }
        else
        {
            printf("Left parenthesis are more than right parenthesis.\n");
            return 0;
        }
}

main()
{
    int valid;
    char exp[size];
    printf("Enter the expression:\n");
    scanf("%s",exp);
    valid=check_parenthesis(exp);
    if(valid==1)
    printf("The expression is valid.\n");
    else
    printf("Expression is invalid\n");
}