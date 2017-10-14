#include <stdio.h>

void swapp(int* a, int* b)
{   
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
  int a[]={4,8,3,6,2,9,0,7,1};
  int n=sizeof(a)/sizeof(a[0]);
  int i,j=n;
  while(j!=0)
  {  
      for(i=0;i<j;i++)
        {   
            if(a[i]>a[i+1])
              { swapp(&a[i],&a[i+1]);  }
        }
     j--;
  }
  for(i=0;i<n;i++)
   {   printf("%d\n",a[i]);
   }


  return 0;

}


