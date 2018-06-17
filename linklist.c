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
NODE dfront(NODE root)
{
    NODE temp;
    temp=root;
    if(root==NULL)
    {
        printf("list empty\n");
        return temp;
    }
    root=root->link;
    printf("deleted element is %d\n",temp->data);
    free(temp);
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
NODE irear(NODE root,int ele)
{
    NODE temp,curr;
    temp=getnode();
    temp->data=ele;
    temp->link=NULL;
    if(root==NULL)
    {return temp;}
    curr=root;
    while(curr->link!=NULL)
    {
        curr=curr->link;
    }
    curr->link=temp;
    return root;
}
NODE drear(NODE root)
{
    NODE temp,prev,curr;
    if(root==NULL)
    {
        printf("list empty\n");
        return root;
    }
    if(root->link==NULL)
    {
       printf("deleted element %d\n",root->data);
       free(root);
       return NULL;
    }
    curr=root;
    while(curr->link!=NULL)
    {
        prev=curr;
        curr=curr->link;
    }
    temp=curr;
    prev->link=curr->link;
    free(temp);
    return root;
}
int main()
{
    NODE root=NULL;
    int c,ele;
    for(;;)
    {
        printf("enter 1 to insert an element from front\n 2 to delete from front\n 3 to insert element from rear\n 4 to delete from rear and\n 5 to display\n");
        scanf("%d\n",&c);
        switch(c)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=ifront(root,ele);
            break;
        case 2:
            root=dfront(root);
            break;
        case 3:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=irear(root,ele);
            break;
        case 4:
            root=drear(root);
            break;
        case 5:
            display(root);
            break;
        default:
            exit(0);

        }
    }
    return 1;
}
