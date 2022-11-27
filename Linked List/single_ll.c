#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;

}nt;

int main()
{
    nt *p=NULL,*l=NULL,*r=NULL;
    int x,v;
    while(1)
    {
        printf("Enter the value\n");
        scanf("%d",&v);
        p= (nt*)malloc(sizeof(nt));
        p->info=v;
        if(l==NULL && r==NULL)
        l=r=p;
        else
        {
            r->next=p;
            r=p;
        }
        printf("Press 1.Continue 2.Exit\n");
        scanf("%d",&x);
        if(x==0)
        break;

    }
    r->next=NULL;
    p=l;
    while(p!=NULL)
    {
        printf("%d  ",p->info);
        p=p->next;

    }
    return 0;
}