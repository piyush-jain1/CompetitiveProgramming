#include <stdio.h>

int main()
{
    int a[]={3,4,2,45,5,6,8,67,98,7,98};
    int n=sizeof(a)/sizeof(a[0]);
    int key;
    int i,j;
    for(i=1;i<n;i++)
     {  
        key=a[i]; 
        j=i-1;
        while(j>=0 && a[j]>key)
            {    
                  a[j+1]=a[j];
                  j--;
            }
       a[j+1]=key;
    }

  for(i=0;i<n;i++)
    {   
          printf("%d\n",a[i]);
    }


  return 0;

}


