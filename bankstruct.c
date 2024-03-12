#include<stdio.h>
#include<string.h>
struct adress
{
    char city[15];
    char area[15];
    char hname[15];
    int pin;
};
 typedef struct bank_details
 {
     char cname[15];
     long int accno;
     char acctype[10];
     float bal;
     struct adress A;
 }BK;
 void read(BK b[10],int n);
 void display(BK b[10],int n);
 void  display_balance(BK b[10],int n);
 void sal_ac(BK b[10],int n);
 void sort(BK b[10],int n);
 void highest_bal(BK b[10],int n);
 void update_adress(BK b[10],int n);
 int main()
 {
      BK b[10];
     int n;
     printf("enter the number of records\n");
     scanf("%d",&n);
     printf("enter the details of %d customers\n");
     printf("cname:\taccno:\tacctype:\tbal:\tcity:\tarea:\thname:\tpin\n");
     read(b,n);
     display(b,n);
     printf("customer with balance less than 1000rs\n");
     display_balance(b,n);
     sal_ac(b,n);
     sort(b,n);
     /*printf("sort the details based on customer name\n);sort(b,n);*/
     highest_bal(b,n);
     printf("after updating records for a particular customer\n");
     update_adress(b,n);
 }
 void read(BK b[10],int n)
 {
     int i;
     for(i=0;i<n;i++)
        scanf("%s%ld%s%f%s%s%s%d",b[i].cname,&b[i].accno,&b[i].acctype,&b[i].bal,b[i].A.city,b[i].A.area,b[i].A.hname,&b[i].A.pin);

 }
 void display(BK b[10],int n)
 {
     int i;
     for(i=0;i<n;i++)
    printf("%s\t%ld\t%s\t%f\t%s\t%s\t%s\t%d\n",b[i].cname,b[i].accno,b[i].acctype,b[i].bal,b[i].A.city,b[i].A.area,b[i].A.hname,&b[i].A.pin);

 }
 void display_balance(BK b[10],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         if(b[i].bal<1000)
             printf("%s\t%ld\t%s\t%f\t%s\t%s\t%s\t%d\n",b[i].cname,b[i].accno,b[i].acctype,b[i].bal,b[i].A.city,b[i].A.area,b[i].A.hname,&b[i].A.pin);
     }

 }
 void sal_ac(BK b[10],int n)
 {
     int i;
     for(i=0;i<n;i++)
     {
         if(strcmp(b[i].acctype,"salary")==0)
            printf("%s\t%ld\t%s\t%f\t%s\t%s\t%s\t%d\n",b[i].cname,b[i].accno,b[i].acctype,b[i].bal,b[i].A.city,b[i].A.area,b[i].A.hname,&b[i].A.pin);
     }
 }
  void sort(BK b[10],int n)
 {
  int i,j; BK swap;
  for (i=0;i<n-1;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(strcmp(b[i].cname,b[j+1].cname)>0)
          {
              swap=b[j];
              b[j]=b[j+1];
              b[j+1]=swap;
          }
      }
  }
  display(b,n);
 }
void highest_bal(BK b[10],int n)
{
    for (i=0;i<n;i++)
    int i,index ;float m=0;
    {
        if(b[i].bal>m)
        {
            m=b[i].bal;
            index=i;
        }
        printf("%s %ld %s %f %s %s %s %d\n",b[index].cname,b[index].accno,b[index].acctype,b[index].bal,b[index].A.city,b[index].A.area,b[index].A.hname,&b[index].A.pin);
     }
    }
   void update_adress(BK b[10],int n)
   {
       int i;
       char name[15];
       printf("enter customer name to which adress need to be updated");
       scanf("%s",name);
       for(i=0;i<n;i++)
       {
           if(strcmp(b[i].cname,name)==0)
           {
               strcpy(b[i].A.city,"dharwad");
               strcpy(b[i].A.area,"YSColony");
               strcpy(b[i].A.hname,"shivakrupa");
               b[i].A.pin=5901;
           }
           else
            printf("no customer found");
       }
       display(b,n);
   }

