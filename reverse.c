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
NODE rev(NODE root)
{
    NODE curr1;
    NODE temp,newlist,curr2;
    int count=1;
    if(root==NULL)
    {
        printf("list empty\n");
        return root;
    }
    curr1=root;
    while(curr1!=NULL)/*to reverse link list*/
    {
        temp=getnode();
        temp->data=curr1->data;
        temp->link=NULL;
        if(count==1)
            curr2=temp;
        else
        {
            temp->link=curr2;
            curr2=temp;
        }
        count++;
        curr1=curr1->link;
    }
    newlist=curr2;
    return newlist;
}
int main()
{
   NODE root1,root2;
   root1=NULL;
   root1=ifront(root1,5);
   root1=ifront(root1,10);
   root1=ifront(root1,15);
   root1=ifront(root1,20);
   root1=ifront(root1,25);
   display(root1);
   root2=rev(root1);
   root2=rev(root1);
   display(root2);
   return 0;
}
