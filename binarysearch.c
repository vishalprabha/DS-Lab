#include<stdio.h>
int bsearch(int l,int h,int arr[],int ele)
{
    int mid;
    if(l>h)
    {
        return -1;
    }
    mid=(l+h)/2;
    if(arr[mid]==ele)
    {
        return (mid+1);
    }
    else if(arr[mid]<ele)
    {
        l=mid+1;
    }
    else
    {
        h=mid-1;
    }
    bsearch(l,h,arr,ele);
}
int main()
{
    int arr[5];
    int key,pos;
    int i;
    printf("enter 5 numbers\n");
    for(i=0; i<5; i++)
        scanf("%d",&arr[i]);
    printf("enter key number \n");
    scanf("%d",&key);
    pos=bsearch(0,4,arr,key);
    if(pos!=-1)
    printf("element found at position %d\n",pos);
    return 0;
}
