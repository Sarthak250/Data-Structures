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
void deleteNode(nodetype** , int);
int main()
{
    nodetype *head=NULL,*tail=NULL;
    int x,ch,n;
    do
    {
        printf("Enter 1.Insert  2.print Forward  3.Print backwards  4.Delete a node\n");
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
                    deleteNode(&head,3);
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
void deleteNode(nodetype** head_ref, int position)
{
 

    // If linked list is empty

    if (*head_ref == NULL)

        return;
 

    // Store head node

    nodetype* temp = *head_ref;
 

    // If head needs to be removed

    if (position == 0) {
 

        // Change head

        *head_ref = temp->next;
 

        // Free old head

        free(temp);

        return;

    }
 

    // Find previous node of the node to be deleted

    for (int i = 0; temp != NULL && i < position - 1; i++)

        temp = temp->next;
 

    // If position is more than number of nodes

    if (temp == NULL || temp->next == NULL)

        return;
 

    // Node temp->next is the node to be deleted

    // Store pointer to the next of node to be deleted

    nodetype* next = (temp->next)->next;
 

    // Unlink the node from linked list

    free(temp->next); // Free memory
 

    // Unlink the deleted node from list

    temp->next = next;
}