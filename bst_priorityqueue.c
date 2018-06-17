
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*right;
    struct node*left;
};
typedef struct node*NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)printf("memory full\n");
    return x;
}
NODE maketree(int ele)
{
    NODE root=getnode();
    root->data=ele;
    root->left=NULL;
    root->right=NULL;
    return root;
}
NODE setleft(NODE p,int ele)
{
    NODE c;
    if(p->left!=NULL)
    {
        printf("left child already exists\n");
        return p;
    }
    c=getnode();
    c->data=ele;
    c->left=NULL;
    c->right=NULL;
    p->left=c;
    return p;
}
NODE setright(NODE p,int ele)
{
    NODE c;
    if(p->right!=NULL)
    {
        printf("right child already exists\n");
        return p;
    }
    c=getnode();
    c->data=ele;
    c->left=NULL;
    c->right=NULL;
    p->right=c;
    return p;
}
NODE iele(NODE tree,int ele)
{
    NODE p,c;
    if(tree==NULL)
    {
        tree=maketree(ele);
        return tree;
    }
    p=tree;
    c=tree;
    while(c!=NULL)
    {
        p=c;
        if(ele<p->data)
            c=p->left;
        else
            c=p->right;
    }
    if(p->data>ele)
        p=setleft(p,ele);
    else
        p=setright(p,ele);
    return tree;
}
NODE del(NODE tree)
{
    NODE p,c,temp;
    if(tree==NULL)
    {
        printf("tree empty\n");
        return tree;
    }
    p=NULL;
    c=NULL;
    temp=tree;
    while(temp!=NULL)
    {
        p=c;
        c=temp;
        temp=temp->left;
    }
    if(p==NULL)
    {
       tree=c->right;
       printf("deleted element is %d\n",c->data);
       free(c);
       return tree;
    }
     p->left=c->right;
     printf("deleted element is %d\n",c->data);
     free(c);
    return tree;
}
void display(NODE tree)
{
    if(tree==NULL)
    return;

    display(tree->left);
    printf("%d\n",tree->data);
    display(tree->right);

}
int main()
{
    NODE tree;
    int ele,i;
    tree=NULL;
     printf("enter 1 to insert, 2 to delete, 3 to display elements\n");
    for(;;)
    {
        printf("enter your choice\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element\n"); scanf("%d",&ele);
            tree=iele(tree,ele);
            break;
        case 2:
            tree=del(tree);
            break;
        case 3:
            display(tree);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

