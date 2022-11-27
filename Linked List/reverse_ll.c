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
        p->next = r;
        r=p;
        printf("Enter 1.continue 0.Exit\n");
        scanf("%d",&x);
        if(x==0)
        break;

    }
    p=r;
    while(p!=NULL)
    {
        printf("%d  ",p->info);
        p=p->next;

    }
    return 0;
}