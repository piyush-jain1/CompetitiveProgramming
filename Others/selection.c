#include<stdio.h>


int main()
{
   int a[]={4,2,5,6,9,2,1,8,0};
   int n=sizeof(a)/sizeof(a[0]);
   int i,j;
   for(i=0;i<n;i++)
   {
      int minm=i;
      for(j=i;j<n;j++)
       {    
            if(a[j]<a[minm])
               {
                   minm=j;
               }
      }
      int temp=a[minm];
          a[minm]=a[i];
          a[i]=temp;
  }

 for(i=0;i<n;i++)
   {
     printf("%d\n",a[i]);
   }

  return 0;

}


