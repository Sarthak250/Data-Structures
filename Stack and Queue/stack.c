#include <stdio.h>
#define max 5
int push(int[],int );
int pop(int[],int);
void peek(int [],int);
void display(int[],int);
int main()
{
    int s[max],top=-1,ch,x;
    while(1)
    {
        printf("Press 1.Push\t2.Pop\t3.Peek\t4.display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    if(top == max-1)
                    printf("The stack is full\n");
                    else
                    top=push(s,top);
                    break;
            case 2:
                    if(top == -1)
                    printf("The stack is underflow\n");
                    else
                    top=pop(s,top);
                    break;
            case 3:
                    peek(s,top);
                    break;
            case 4:
                    display(s,top);
                    break;
            default:
                    printf("Wrong Choice\n");
        }
        printf("Press 1 to cintinue else 0 to exit\n");
        scanf("%d",&x);
        if(x==0)
        break;
    }

    return 0;
}

int push(int s[],int top)
{
    top++;
    printf("enter the element\n");
    scanf("%d",&s[top]);
    return top;
}
int pop(int s[],int top)
{
   
    printf("the popped element is : %d",s[top]);
    top--;
    return top;
}
void display(int s[],int top)
{
    while(top <= max-1)
    {
        printf("%d  ",s[top]);
        top++;
    }
}
void peek(int s[],int top)
{
    printf("%d",s[top]);
}
