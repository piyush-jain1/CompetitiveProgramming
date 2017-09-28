#include <stdio.h>


void bubbleSort(int a[], int n)
{
    int i,k,temp,pos;
    pos=n-1;
    while(pos!=0)
    {    
        k=0;
        for(i=0;i<pos;i++)
        {
            if(a[i]>a[i+1])
            {    
                temp = a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
                k=i;
            }
        }
        pos=k;
        
    }
    

}
int main()
{    
    int i;
    int a[]={4,6,3,7,6,9,12,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}