#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int number, data;
 struct node *next;
} nodetype ;
void insert( nodetype** , int, int );
void taskprocess(nodetype **, int, int );
void deletenode(nodetype **p);
void display(nodetype*);
int main(){
 nodetype *last=NULL;
 int time ,n,x ;
 printf("Enter the processing unit in nanosecond : ");
 scanf("%d", &time);
 printf("Enter the number of processes : ");
 scanf("%d", &n);
 printf("**Enter all the processes**\n");
 int i=0;
 while(i<n){
 printf("Enter the time of Process %d : ", i+1);
 scanf("%d", &x);
 insert(&last, x , i+1);
 i++;
 }
 taskprocess(&last, time, n);
 printf("\n**All processes completed successfully !!**");
 return 0;
}
void insert ( nodetype **last, int d, int n){
 nodetype *p=NULL;
 p=(nodetype*)malloc(sizeof(nodetype));
 if(p!=NULL){
 p->number=n;
 p->data=d;
 if(*last==NULL){
 *last = p;
 (*last)->next = p;
 return;
 }
 p->next=(*last)->next;
 (*last)->next=p;
 (*last)=p;
 }
}
void deletenode(nodetype **p){
 nodetype *q=*p , *r=NULL;
 if(q->next==q)
 {
 free(q);
 *p=NULL;
 return;
 }
 r=q->next;
 q->next=r->next;
 free(r);
 *p=q;
}
void taskprocess(nodetype **last, int time , int n){
 nodetype *p = *last;
 while(p!=NULL)
 {
 nodetype *f=p->next;
 f->data=f->data-time;
 if((f->data)<=0)
 {
 if(f==*last)
 *last=p;
 printf("\n***Process %d is Completed***", f->number );
 deletenode(&p);
 }
 else
 p=p->next;
 display((*last)->next);
 }
}
void display(nodetype *last)
{
 nodetype *temp;
 temp=last;
 if(last==NULL)
 printf("All processes are completed!!!");
 else
 {
 printf("\nthe elements in the linked list after scheduling are\n");
 printf("%d\t",last->data);
 temp=temp->next;
 while(temp!=last)
 {
 printf("%d\t",temp->data);
 temp=temp->next;
 }
 }
 printf("\n");
}