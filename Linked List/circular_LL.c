#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}nt;


nt* insert(nt*);
nt* delete(nt*);
void display(nt*);
int main()
{
    nt *p=NULL,*q=NULL;
    int ch,x;
    do
    {
        printf("Enter choice: 1.Insert   2.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                    if(p==NULL)
                    p=insert(p);
                    else
                    q=insert(p);
                    break;
            case 2:
                    display(p);
                    break;
            default:
                    printf("Wrong choice\n");

        }
        printf("Enter: 1.Continue   0.Exit\n");
        scanf("%d",&x);
        if(x==0)
        break;

    }while(1);
    return 0;
}
nt* insert(nt *p){
    nt *q=NULL;
    int x;
    printf("Enter a number:  ");
    scanf("%d",&x);
    q=(nt*)malloc(sizeof(nt));

    if(q!=NULL)
    {
        q->info=x;
        if(p==NULL)
        {
            p=q;
            p->next=p;
        }
        else
        {
            q->next=p->next;
            p->next=q;
        }
        
        return p;
    }
}
void display(nt* p)
{
    
    nt* qm=p;
    

    do
    {
        printf("%d  ",qm->next);
        qm=qm->next;
    } while (qm != p->next);
    printf("\n");
}
