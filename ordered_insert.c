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
NODE insert(NODE root,int ele)
{
  NODE temp,curr,prev;
  temp=getnode();
  temp->data=ele;
  temp->link=NULL;
  if(root==NULL)
  {
      return temp;
  }
  if(root->data>ele)
  {
      temp->link=root;
      return temp;
  }
  curr=root;
  while(curr!=NULL)
  {
      if(curr->data>ele)
      {
        temp->link=curr;
        prev->link=temp;
        break;
      }
      prev=curr;
      curr=curr->link;
  }
  if(curr==NULL)
  {
      prev->link=temp;
  }
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
    int c,ele;
    for(;;)
    {
        printf("enter 1 to insert an element and 2 to display\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&ele);
            root=insert(root,ele);
            break;
        case 2:
            display(root);
            break;
        default:
            exit(0);

        }
    }
    return 1;
}


