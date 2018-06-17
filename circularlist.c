#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE ifront(NODE last,int ele)
{
    NODE temp=getnode();
    temp->data=ele;
    temp->link=temp;
    if(last==NULL)
        return temp;
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE irear(NODE last,int ele)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    temp->link=temp;
    if(last==NULL)
        return last;
    temp->link=last->link;
    last->link=temp;
    return temp;
}
NODE dfront(NODE last)
{
    NODE temp;
    if(last==NULL)
       {
        printf("list empty\n");
        return 0;
       }
       if(last->link==last)
       {
        printf("deleted element is %d\n",last->data);
        free(last);
        return NULL;
       }
    temp=last->link;
    last->link=temp->link;
    printf("deleted element is %d\n",temp->data);
    free(temp);
    return last;
}
NODE drear(NODE last)
{
    NODE temp,curr;
    if(last==NULL)
    {
        printf("list empty\n");
        return last;
    }
    if(last->link==last)
    {
    printf("deleted element is %d \n",last->data);
    free(last);
    return NULL;
    }
    temp=NULL;
    curr=last->link;
    while(curr!=last)
    {
        temp=curr;
        curr=curr->link;
    }
    temp->link=curr->link;
    printf("deleted element is %d \n",curr->data);
    free(curr);
    return temp;
}
void display(NODE last)
{
    NODE curr;
    if(last==NULL)
        printf("list empty\n");
    else{

        curr=last->link;
        while(curr!=last)
        {
            printf("%d\t",curr->data);
            curr=curr->link;
        }
        printf("%d\n",curr->data);
    }
}
int main()
{
    NODE last;
    int i,ele;
    last=NULL;
    for(;;)
    {
        printf("enter 1 to insert front, 2 to insert rear,3 to delete front, 4 to del rear, 5 to display\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element\n");
            scanf("%d",&ele);
            last=ifront(last,ele);
            break;
        case 2:
            printf("enter element\n");
            scanf("%d",&ele);
            last=irear(last,ele);
            break;
        case 3:
            last=dfront(last);
            break;
        case 4:
            last=drear(last);
            break;
        case 5:
            display(last);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

