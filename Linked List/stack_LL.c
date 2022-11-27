#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int info;
    struct node *next;

}nodetype;

nodetype* pop(nodetype*);
nodetype* push(nodetype*);
void display(nodetype*);

int main()
{
    nodetype *top=NULL;
    int x,ch;  

    do
    {
        printf("Enter  1.push   2.Pop   3.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    top = push(top);
                    break;
            case 2:
                    if(top!=NULL)
                    top = pop(top);
                    else
                    printf("Stack is empty\n");
                    break;
            case 3:
                    if(top!=NULL)
                    display(top);
                    else
                    printf("The stack is empty\n");
                    break;
            default:
                    printf("Wrong Choice\n");

        }
        printf("Enter  1.continue or 0.exit\n");
        scanf("%d",&x);
        if(x==0)
        break;

    }while(1);
    return 0;
}
nodetype* push(nodetype* top)
{
    nodetype *p=NULL;
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    p=(nodetype*)malloc(sizeof(nodetype));
    if(p!= NULL)
    {
        p->info=x;
        p->next=top;
        top=p;

    }
    return top;
}
nodetype* pop(nodetype* top)
{
    nodetype* temp;
    temp=top;
    printf("The popped element is: %d \n",top->info); 
    top = top->next;
    free(temp);
    return top;
}
void display(nodetype* top)
{
    while(top!=NULL)
    {
        printf("%d  ",top->info);
        top=top->next;
    }
}