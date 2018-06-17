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
NODE ifront(NODE root,int ele)
{
    NODE temp=getnode();
    temp->data=ele;
    temp->left=NULL;
    temp->right=root;
    if(root!=NULL)
        root->left=temp;
    return temp;
}
NODE irear(NODE root,int ele)
{
    NODE temp,prev;
    temp=getnode();
    temp->data=ele;
    temp->left=temp->right=NULL;
    if(root==NULL)
        return temp;
    prev=root;
    while(prev->right!=NULL)
        prev=prev->right;
    temp->left=prev;
    prev->right=temp;
    return root;
}
NODE dfront(NODE root)
{
    NODE temp;
    if(root==NULL)
       {
        printf("list empty\n");
        return 0;
       }
    temp=root;
    printf("deleted element is %d \n",temp->data);
    free(temp);
    root=root->right;
    return root;
}
NODE drear(NODE root)
{
    NODE temp,curr;
    if(root==NULL)
    {
        printf("list empty\n");
        return root;
    }
    if(root->right==NULL)
    {
    printf("deleted element is %d \n",root->data);
    free(root);
    return NULL;
    }
    temp=NULL;
    curr=root;
    while(curr->right!=NULL)
    {
        temp=curr;
        curr=curr->right;
    }
    temp->right=NULL;
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
void palin(NODE root)
{
    NODE liststart,listend;
    int l=1,flag=1,i;
    if(root==NULL)
    {
        printf("list empty\n");
        return;
    }
    liststart=listend=root;
    while(listend->right!=NULL)
    {
     l++;
     listend=listend->right;
    }
    for(i=1; i<=l/2; i++)
    {
        if(listend->data!=liststart->data)
        {
            flag=0;
            break;
        }
        i++;
        liststart=liststart->right;
        listend=listend->right;
    }
    if(flag==1)
    {
        printf("list is palindrome\n " );
    }
    else
    {
        printf("list is not palindrome\n " );
    }

}
int main()
{
    NODE root;
    int i,ele;
    root=NULL;
    for(;;)
    {
        printf("enter 1 to insert front, 2 to insert rear,3 to delete front, 4 to del rear, 5 to display, 6 check palin\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element\n");
            scanf("%d",&ele);
            root=ifront(root,ele);
            break;
        case 2:
            printf("enter element\n");
            scanf("%d",&ele);
            root=irear(root,ele);
            break;
        case 3:
            root=dfront(root);
            break;
        case 4:
            root=drear(root);
            break;
        case 5:
            display(root);
            break;
        case 6:
            palin(root);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
