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
NODE mergelist(NODE root1,NODE root2)
{
    NODE curr1,curr2;
    int i=1;
    NODE newlist,temp,curr;
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    curr1=root1;
    curr2=root2;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data>curr2->data)
        {
                temp=getnode();
                temp->data=curr2->data;
                temp->link=NULL;
                curr2=curr2->link;
        }
        else if(curr1->data<curr2->data)
        {

                temp=getnode();
                temp->data=curr1->data;
                temp->link=NULL;
            curr1=curr1->link;
        }
        else
        {

                temp=getnode();
                temp->data=curr1->data;
                temp->link=NULL;
            curr1=curr1->link;
            curr2=curr2->link;
        }
         if(i==1)
            {
                i++;
                newlist=temp;
                curr=newlist;
            }
        else
            {
                curr->link=temp;
                curr=curr->link;
            }

    }
    while(curr1!=NULL)
    {
        temp=getnode();
        temp->data=curr1->data;
        temp->link=NULL;
        curr->link=temp;
        curr=curr->link;
        curr1=curr1->link;
    }
    while(curr2!=NULL)
    {
        temp=getnode();
        temp->data=curr2->data;
        temp->link=NULL;
        curr->link=temp;
        curr=curr->link;
        curr2=curr2->link;
    }
    return newlist;
}
int main()
{
    NODE root1=NULL;
    NODE root2=NULL;
    NODE root=NULL;
    int c,ele;
    for(;;)
    {
        printf("enter 1 to insert an element in 1st list\n 2 to insert element in second list\n 3 to merge 2 list\n 4 to display\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root1=ifront(root1,ele);
            break;
        case 2:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root2=ifront(root2,ele);
            break;
        case 3:
            root=mergelist(root1,root2);
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
