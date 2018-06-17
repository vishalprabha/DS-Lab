#include<stdio.h>
void toh(char source,char temp, char dest,int n)
{
    if(n==1)
    {
        printf("move ring %d from %c to %c\n",n,source,dest);
    }
    else
    {
        toh(source,dest,temp,n-1);
        printf("move ring %d from %c to %c\n",n,source,dest);
        toh(temp,source,dest,n-1);
    }
}
int main()
{
    int n;
    printf("enter no of rings\n");
    scanf("%d",&n);
    toh('A','B','C',n);
    return 0;
}
