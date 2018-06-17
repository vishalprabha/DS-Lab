#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 20
struct stack
{
    int top;
    float items[size];
};
void push(float ele,struct stack *s)
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
float pop(struct stack *s)
{
    float x=0;
    if(s->top==-1)
    {
        printf("stack empty\n");
        return 0;
    }
    else
    {
        x=s->items[s->top];
        s->top--;
        return x;
    }
}
float cal(char ch,float n1, float n2)
{
    switch(ch)
    {
    case '+':return (n1+n2);
    case '-':return (n1-n2);
    case '*':return (n1*n2);
    case '/':return (n1/n2);
    case '^':
    case '$':return pow(n1,n2);
    }
}
int main()
{
    struct stack s;
    int i;
    int n;
    float op1,op2,result;
    char ch;
    char postfix[20];
    s.top=-1;
    printf("enter postfix expression\n");
    scanf("%s",postfix);
    for(i=0; i<strlen(postfix); i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0',&s);
        }
        else
        {
        op2=pop(&s);
        op1=pop(&s);
        result=cal(ch,op1,op2);
        push(result,&s);
        }
    }
    result=pop(&s);
    printf("result :%f\n",result);
    return 0;
}
