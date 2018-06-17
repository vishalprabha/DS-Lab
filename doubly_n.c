#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE ipos(NODE root,int ele,int pos)
{
    NODE temp,prev,curr;
    int n=1;
    temp=getnode();
    temp->data=ele;
    temp->left=temp->right=NULL;
    if(root==NULL)
        return temp;
    if(pos==1)
    {
      temp->right=root;
      root->left=temp;
      return temp;
    }
    curr=root;
    while(curr!=NULL && n<pos)
      {
       prev=curr;
       curr=curr->right;
       n++;
      }
    temp->left=prev;
    temp->right=curr;
    prev->right=temp;
    if(curr!=NULL)
        curr->left=temp;
    return root;
}

NODE dpos(NODE root,int pos)
{
    NODE temp,curr;
    int n=1;
    if(root==NULL)
    {
        printf("list empty\n");
        return root;
    }
    if(pos==1)
    {
        temp=root;
        root=root->right;
        if(root!=NULL)
            root->left=NULL;
        printf("deleted element is %d \n",temp->data);
        free(temp);
        return root;
    }
    curr=root;
    while(curr!=NULL && n<pos)
    {
        temp=curr;
        curr=curr->right;
        n++;
    }
    if(curr==NULL)
    {
        printf("position out of range\n");
        return root;
    }
    temp->right=curr->right;
    if(curr->right!=NULL)
    (curr->right)->left=temp;
    printf("deleted element is %d \n",curr->data);
    free(curr);
    return root;
}
void display(NODE root)
{
    NODE curr;
    if(root==NULL)
        printf("list empty\n");
    else{

        curr=root;
        while(curr!=NULL)
        {
            printf("%d\t",curr->data);
            curr=curr->right;
        }
    }
}
int main()
{
    NODE root;
    int i,pos,ele;
    root=NULL;
    for(;;)
    {
        printf("enter 1 to insert , 2 to delete, 3 to display\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element and position\n");
            scanf("%d%d",&ele,&pos);
            root=ipos(root,ele,pos);
            break;
        case 2:
            printf("enter position\n");
            scanf("%d",&pos);
            root=dpos(root,pos);
            break;
        case 3:
            display(root);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

