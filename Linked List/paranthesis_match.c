#include <stdio.h>
#include <string.h>

#define max 6

void push(char [],char ,int*);
char pop(char [],int*);
int paranthesis_match(char[]);
int match(char,char);

int main()
{
    char s[20];
    int x;
    printf("Enter the expression:\n");
    scanf("%s",s);
    x=paranthesis_match(s);
    if(x==1)
    printf("The expression in valid\n");
    else if(x==0)
    printf("The expression is invalid\n");


    return 0;
}

int paranthesis_match(char s[])
{
    char sp[20],pel;
    int top=-1;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i] =='(' || s[i]=='{' || s[i]=='[')
        push(sp,s[i],&top);
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(top == -1)
            return 0;
            
            pel = pop(sp,&top);
            if(!match(pel,s[i]))
            return 0;
        }
    }
    return 1;
}
void push(char sp[],char a,int* top)
{
    (*top)++;
    sp[*top] = a;

}

char pop(char sp[],int* top)
{
    char c;
    c=sp[*top];
    (*top)--;
    return c;
}

int match(char c,char sp)
{
    if(c == '(' && sp == ')')
    return 1;
    if(c == '{' && sp == '}')
    return 1;
    if(c == '[' && sp == ']')
    return 1;

    return 0;
}