
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE ipos(NODE last,int ele,int pos)
{
    int n;
    NODE curr;
    NODE temp=getnode();
    temp->data=ele;
    temp->link=temp;
    if(last==NULL)
        return temp;
    if(pos==1)
    {
        temp->link=last->link;
        last->link=temp;
        return last;
    }
    curr=last->link;
    n=1;
    while(curr!=last && n<pos-1)
    {
        curr=curr->link;
        n++;
    }
    temp->link=curr->link;
    curr->link=temp;
    if(curr==last)
        return temp;
    return last;
}
NODE dpos(NODE last,int pos)
{
    NODE temp,curr,prev;
    int n=1;
    if(last==NULL)
       {
        printf("list empty\n");
        return 0;
       }
     if(pos==1)
     {
         temp=last->link;
         printf("deleted eleemnt is %d\n",temp->data);
         if(last->link==last)
            last=NULL;
         else
         last->link=temp->link;
         free(temp);
         return last;
     }
       curr=last->link;
       while(curr!=last && n<pos)
       {
           prev=curr;
           curr=curr->link;
           n++;
       }
       if(n!=pos)
       {
           printf("position out of range\n");
           return last;
       }
    prev->link=curr->link;
    printf("deleted element is %d\n",curr->data);
    if(curr==last)
        last=prev;
    free(curr);
    return last;
}
void display(NODE last)
{
    NODE curr;
    if(last==NULL)
        printf("list empty\n");
    else{

        curr=last->link;
        while(curr!=last)
        {
            printf("%d\t",curr->data);
            curr=curr->link;
        }
        printf("%d\n",curr->data);
    }
}
int main()
{
    NODE last;
    int i,ele,pos;
    last=NULL;
    for(;;)
    {
        printf("enter 1 to insert , 2 to del,3 to display\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element and pos\n");
            scanf("%d%d",&ele,&pos);
            last=ipos(last,ele,pos);
            break;
        case 2:
            printf("enter pos\n");
            scanf("%d",&pos);
            last=dpos(last,pos);
            break;
        case 3:
            display(last);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

