#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[10];
char usn[10];
int m1,m2,m3;
};
typedef struct student std;
void write_file(FILE *fp)
{
    std s;
    printf("enter student name, usn and marks in 3 subjects\n");
    scanf("%s%s%d%d%d",s.name,s.usn,&s.m1,&s.m2,&s.m3);
    if(!feof(fp))
    {
    fprintf(fp,"%s\t%s\t%d\t%d\t%d\n",s.name,s.usn,s.m1,s.m2,s.m3);
    }
}
int search_file(FILE *fp, char key[])
{
    std s;
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d%d%d",s.name,s.usn,&s.m1,&s.m2,&s.m3);
        if(strcmp(s.usn,key)==0)
            return 1;
    }
    return 0;
}
void display_file(FILE *fp)
{
    std s;
    printf("name    usn    marks1 marks2 marks3\n");
    for(;!feof(fp);)
    {
     fscanf(fp,"%s%s%d%d%d",s.name,s.usn,&s.m1,&s.m2,&s.m3);
     if(!feof(fp))
     printf("%s\t%s\t%d\t%d\t%d\n",s.name,s.usn,s.m1,s.m2,s.m3);
     else
        break;
    }
}
int main()
{
    FILE *fp; char key[10];
    char fname[10]="sample";
    int i,flag;
    for(;;)
    {
        printf("1 write in file, 2 search in file, 3 display\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:fp=fopen(fname,"a");
               if(fp==NULL)
               {
                   printf("file open failed\n");
               }
               else
                {
                write_file(fp);
                fclose(fp);
                }break;
        case 2:fp=fopen(fname,"r");
               if(fp==NULL)
               {
                   printf("file open failed\n");
               }
               else
               {
                   printf("enter usn 2 be searched\n"); scanf("%s",key);
                   flag=search_file(fp,key);
                   if(flag==0)
                    printf("unsuccessful search\n");
                   else
                    printf("successful search\n"); fclose(fp);
               }break;
        case 3:fp=fopen(fname,"r");
               if(fp==NULL)
               {
                   printf("file open failed\n");
               }
               else
               {display_file(fp);
               fclose(fp);
               }break;
        default:exit(0);
        }
    }
    return 0;
}
