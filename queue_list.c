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
NODE insert(NODE root,int ele)
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
NODE del(NODE root)
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
int main()
{
    NODE root=NULL;
    int c,ele;
    for(;;)
    {
        printf("enter 1 to insert an element \n 2 to delete \n 3 to display\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=insert(root,ele);
            break;
        case 2:
            root=del(root);
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

