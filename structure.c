#include<stdio.h>
typedef struct
{
char empno[10];
char dept[10];
double sal;
struct doj
{
  int day;
  int month;
  int year;
}join;
}employee;
void salary_cal(employee e[])
{
    int d,m,y;
    int c,i;
    for(i=0; i<5;i++)
    {
    d=31-e[i].join.day;
    m=12-e[i].join.month;
    y=2014-e[i].join.year;
    if(d>=30)
    {
        m+=1;
    }
    if(m>=12)
    {
        y=y+1;
    }
    printf("years of experience %d\n",y);
    if(y>5)
    {
        e[i].sal=e[i].sal+(e[i].sal*.25);
    }
    printf("new salary of emp %s is %ld\n",e[i].empno,e[i].sal);
    }
}
int main()
{
    employee emp[5];
    int i;
    printf("enter details of 5 employee\n");
    for(i=0; i<5; i++)
    {
        printf("enter employee no, department, salary, joining day, month and year\n");
        scanf("%s %s %ld %d %d %d",emp[i].empno,emp[i].dept,&emp[i].sal,&emp[i].join.day,&emp[i].join.month,&emp[i].join.year);
    }
    salary_cal(emp);

}
