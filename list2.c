#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(NODE));
if(x==NULL)
    printf("no memory space left\n");
return x;
}
NODE ifront(NODE root,int ele)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    temp->link=root;
    return temp;
}
int searchele(NODE root,int ele)
{
    NODE curr;
    int i,pos;
    if(root==NULL)
    {
        pos=0;
        printf("list empty\n");
    }
    else
    {
        pos=0;
        i=0;
        curr=root;
    while(curr!=NULL)
    {
        pos++;
        if(curr->data==ele)
        {
          i++;
          break;
        }
        curr=curr->link;
    }
    if(i!=0)
        printf("element found at position %d\n",pos);
    else
        printf("element not found\n");
    }
    return pos;
}

int main()
{
    NODE root=NULL;
    int ele,c,pos;
    for(;;)
    {
        printf("enter 1 to insert element, 2 to search an element ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=ifront(root,ele);
            break;
            case 2:
            printf("enter element to be searched\n");
            scanf("%d",&ele);
            pos=searchele(root,ele);
            break;
            default:
            exit(0);
        }
    }
    return 1;
}
