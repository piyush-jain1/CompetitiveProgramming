#include <stdio.h>


void insertionSort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {    
        key = a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{    
    int i;
    int a[]={4,6,3,7,6,9,12,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}