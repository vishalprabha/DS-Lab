#include<stdio.h>
#include<stdlib.h>
#define size 5
struct cqueue
{
    int front;
    int rear;
    int arr[size];
};
void push(struct cqueue*q,int ele)
{
    int temp=q->rear;
    q->rear=(q->rear+1)%size;
    if(q->rear==q->front)
    {
        q->rear=temp;
        printf("queue full\n");
    }
    else
    {
        q->arr[q->rear]=ele;
    }
}
int pop(struct cqueue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        q->front=size-1;
        q->rear=size-1;
        printf("queue empty\n");
    }
    else
    {
        q->front=(q->front+1)%size;
        x=q->arr[q->front];
    }
    return x;
}
void display(struct cqueue q)
{
    int i;
    if(q.front==q.rear)
        printf("queue empty\n");
    else
    {
        for(i=(q.front+1)%size; i!=q.rear; i=(i+1)%size)
        printf("%d\t",q.arr[i]);
        printf("%d\n",q.arr[i]);
    }
}
int main()
{
 struct cqueue q;
 int i=0; int ch;
 q.front=size-1;
 q.rear=size-1;
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
        if(ch!=-1)
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
