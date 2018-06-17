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

NODE del_pos(NODE root,int pos)
{
NODE curr,prev;
int i=1;
if(root==NULL)
{
    printf("list empty\n");
    return NULL;
}
if(pos==1)
{
    prev=root;
    root=root->link;
    printf("deleted element %d\n",prev->data);
    free(prev);
    return root;
}
prev=root;
while(i<pos-1)
{
    i++;
    prev=prev->link;
}
curr=prev->link;
prev->link=curr->link;
printf("deleted element %d\n",curr->data);
free(curr);
return root;
}
NODE i_pos(NODE root,int ele,int pos)
{
    NODE temp,curr;
    int i=1;
    temp=getnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    {
        return temp;
    }
    if(pos==1)
    {
        temp->link=root;
        return temp;
    }
    curr=root;
    while(i<pos-1)
    {
        i++;
        curr=curr->link;
    }
    temp->link=curr->link;
    curr->link=temp;
    return root;
}
void display(NODE root)
{
    NODE curr;
    if(root==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        for(curr=root; curr!=NULL; curr=curr->link)
        {
            printf("%d\t",curr->data);
        }
        printf("\n");
    }
}

int main()
{
    NODE root=NULL;
    int ele,c,pos;
    for(;;)
    {
        printf("enter 1 to insert element, 2 to delete at a given position, 3 to insert at a given pos, 4 to display");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=ifront(root,ele);
            break;
            case 2:
            printf("enter position\n");
            scanf("%d",&pos);
            root=del_pos(root,pos);
            break;
            case 3:
            printf("enter position\n");
            scanf("%d",&pos);
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=i_pos(root,ele,pos);
            break;
            case 4:
            display(root);
            break;
            default:
            exit(0);
        }
    }
    return 1;
}
