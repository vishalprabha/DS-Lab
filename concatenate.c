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
NODE irear(NODE last,int ele)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    temp->link=temp;
    if(last==NULL)
        return temp;
    temp->link=last->link;
    last->link=temp;
    return temp;
}
void display(NODE last)
{
    NODE curr;
    if(last==NULL)
        printf("list empty\n");
    else
    {
        curr=last->link;
        while(curr!=last)
        {
            printf("%d\t",curr->data);
            curr=curr->link;
        }
        printf("%d\n",curr->data);
    }
}
NODE concaten(NODE last1,NODE last2)
{
    NODE first1,first2;
    if(last1==NULL)
        return last2;
    if(last2==NULL)
        return last1;
    first1=last1->link;
    first2=last2->link;
    last2->link=first1;
    last1->link=first2;
    return last2;
}
int main()
{
    NODE last1,last2;
    last1=NULL;
    last2=NULL;
    int i,ele;
    for(;;)
    {
        printf("enter 1 to insert in 1st list, 2 to insert in 2nd list, 3 concatenate 2 lists, 4 to display\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element\n");
            scanf("%d",&ele);
            last1=irear(last1,ele);
            break;
        case 2:
            printf("enter element\n");
            scanf("%d",&ele);
            last2=irear(last2,ele);
            break;
        case 3:
            last1=concaten(last1,last2);
            break;
        case 4:
            display(last1);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}


