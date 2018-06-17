#include<stdio.h>
#include<stdlib.h>
#define size 5
typedef struct
{
    int top;
    int items[size];
}stack;
void push(stack *s,int ele)
{
    if(s->top==size-1)
    {
        printf("stack full\n");
    }
    else
    {
        s->top++;
        s->items[s->top]=ele;
    }
}
int pop(stack *s)
{
    int x=-999;
    if(s->top==-1)
    {
        printf("stack empty\n");
        return;
    }
    else
    {
        x=s->items[s->top];
        s->top--;
        return x;
    }
}
void display(stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("stack empty\n");
    }
    else
    {
        printf("\n");
        for(i=0; i<=s->top; i++)
        {
            printf("%d\n",s->items[i]);
        }
    }
}
int main()
{
stack s;
int i,ele,del;
s.top=-1;
for(;;)
{
    printf("enter 1 to push 2 to pop and 3 to display\n");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        printf("enter element\n");
        scanf("%d",&ele);
        push(&s,ele);
        break;
    case 2:
        del=pop(&s);
        printf("element deleted : %d\n",del);
        break;
    case 3:
        display(&s);
        break;
    default:
        exit(0);
    }
}
}
