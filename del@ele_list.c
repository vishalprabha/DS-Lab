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
NODE del(NODE root,int x)
{
    NODE curr,prev,temp;
    int pos=1;
    if(root==NULL)
    {
        printf("list empty\n");
        return root;
    }
    curr=root;
    prev=curr;
    while(curr!=NULL)
    {

        if(curr->data==x)
        {
            temp=curr;
            curr=curr->link;
           if(pos!=1)
           {
           prev->link=temp->link;
           }
           if(pos==1)
           {
               root=curr;
           }
           free(temp);
        }
        else
        {
            pos++;
            prev=curr;
            curr=curr->link;
        }
    }
    return root;
}
int main()
{
    NODE root=NULL;
    int c,ele;
    for(;;)
    {
        printf("enter 1 to insert an element from front\n 2 to delete all occurances of element\n 3 to display\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=ifront(root,ele);
            break;
        case 2:
            printf("enter element to be deleted\n");
            scanf("%d",&ele);
            root=del(root,ele);
            break;
        case 3:
            display(root);
            break;
        default:
            exit(0);

        }
    }
    return 1;
}

