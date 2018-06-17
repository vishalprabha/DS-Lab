#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 20
typedef struct
{
    int top;
    char items[size];
}stack;
void push(stack *s,char ele)
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
char pop(stack *s)
{
    char x;
    if(s->top==-1)
    {
        printf("stack empty\n");
        return x;
    }
    else
    {
        x=s->items[s->top];
        s->top--;
        return x;
    }
}
int st_pre(char ch)
{
   switch(ch)
   {
   case '+':
   case '-': return 2;
   case '*':
   case '/': return 4;
   case '^':
   case '$': return 5;
   case '(': return 0;
   case '#': return -1;
   default: return 8;
   }
}
int ip_pre(char ch)
{
   switch(ch)
   {
   case '+':
   case '-': return 1;
   case '*':
   case '/': return 3;
   case '^':
   case '$': return 6;
   case '(': return 9;
   case ')': return 0;
   default: return 7;
   }
}
void infix_postfix(char infix[], char postfix[])
{
    stack s;
    int i,j;
    j=0;
    char ch;
    s.top=-1;
    push(&s,'#');
    for(i=0; i < strlen(infix); i++)
    {
        ch=infix[i];
        while(st_pre(s.items[s.top])>ip_pre(ch))
       {
        postfix[j++]=pop(&s);
       }
       if(st_pre(s.items[s.top])<ip_pre(ch))
       {
           push(&s,ch);
       }
       else
       {
           ch=pop(&s);
       }
    }
    while(s.top!=0)
    {
        postfix[j++]=pop(&s);
    }

    postfix[j]='\0';
}
int main()
{
    char infix[10];
    char postfix[10];
    printf("enter infix expression\n");
    scanf("%s",infix);
    infix_postfix(infix,postfix);
    printf("postfix expression is %s\n",postfix);
    return 0;
}
