#include<stdio.h>
#include<stdlib.h>
#define size 5
struct pqueue
{
    int front;
    int rear;
    int arr[size];
};
void push(struct pqueue*q,int ele)
{
    int j;
    if(q->rear==size-1)
    {
        printf("queue full\n");
    }
    else
    {
        j=q->rear;
        while(j>=q->front && ele<q->arr[j])
        {
        q->arr[j+1]=q->arr[j];
        j--;
        }
        q->arr[j+1]=ele;
        q->rear++;
    }
}
int pop(struct pqueue *q)
{
    int x;
    if(q->front>q->rear)
    {
        printf("queue empty\n");
    }
    else
    {
        x=q->arr[q->front];
        q->front++;
    }
    return x;
}
void display(struct pqueue q)
{
    int i;
    if(q.front>q.rear)
        printf("queue empty\n");
    else
    {
        for(i=q.front; i<=q.rear; i++)
        printf("%d \t",q.arr[i]);
        printf("\n");
    }
}
int main()
{
 struct pqueue q;
 int i=0; int ch;
 q.front=0;
 q.rear=-1;
 for(;;)
 {
     printf("enter 1 to insert element, 2 to delete, 3 to display\n");
     scanf("%d",&i);
     switch(i)
     {
     case 1:
        printf("enter element\n");
        scanf("%d",&ch);
        push(&q,ch);
        break;
     case 2:
        ch=pop(&q);
        if(ch!=' ')
            printf("deleted element is %d \n",ch);
        break;
     case 3:
        display(q);
        break;
     default:
        exit(0);
     }
 }
 return 0;
}


