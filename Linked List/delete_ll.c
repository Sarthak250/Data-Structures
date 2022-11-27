#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int info;
    struct node *prev,*next;

}nodetype;

nodetype* insert(nodetype*);
void dispfrd(nodetype*);
void displaybkd(nodetype*);
void delete(nodetype**,int);

int main()
{
    nodetype *head=NULL,*tail=NULL;
    int x,ch,num;
    do
    {
        printf("Enter  1.Insert  2.print Forward  3.Print backwards  4.Delete a node\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    tail=insert(tail);
                    if(head == NULL)
                    head=tail;
                    break;
            case 2:
                    if(tail==NULL)
                    printf("Empty\n");
                    else
                    dispfrd(head);
                    break;
            case 3:
                    if(tail==NULL)
                    printf("Empty\n");
                    else
                    displaybkd(tail);
                    break;
            case 4:
                    printf("Enter the number to delete: ");
                    scanf("%d",&num);
                    delete(&head,num);
                    break;

        }
        printf("Enter 1. Continue  0.Exit\n");
        scanf("%d",&x);
        if(x==0)
        break;
    }while(1);

    return 0;
}
nodetype* insert(nodetype* tail)
{
    nodetype *p=NULL;
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);
    p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
        p->info=x;
        p->next=NULL;
        if(tail==NULL)
        {
            p->prev=NULL;
            tail=p;
        }
        else
        {
            tail->next=p;
            p->prev=tail;
            tail=p;
        }
    }
    return tail;
}
void dispfrd(nodetype *head)
{
    while(head != NULL){
    printf("%d  ",head->info);
    head=head->next;
    }

}

void displaybkd(nodetype *tail)
{
    while(tail != NULL){
    printf("%d  ",tail->info);
    tail=tail->prev;
    }
}
void delete(nodetype** head,int num)
{
    nodetype* p=NULL;
    p=(nodetype*)malloc(sizeof(nodetype));
    while((*head)->info!=num)
    {
        *head=(*head)->next;
    }
    if((*head)->next == NULL)
    printf("Number not found\n");
    else
    {
        p=*head;
        ((*head)->prev)->next=(*head)->next;
        ((*head)->next)->prev=(*head)->prev;
        free(p);
    }
}