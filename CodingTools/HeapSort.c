#include <stdio.h>


//assuming indexing is from zero

void heapify(int a[], int n, int i)
{    
    int largest= i;
    int l=2*i+1;
    int r=2*i+2;
    int temp;
    if(l<=n-1 && a[l]>a[largest])
    {
        largest = l;
    }
    if(r<=n-1 && a[r]>=a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        heapify(a,n,largest);
    }
}
void buildHeap(int a[], int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
}
void heapSort(int a[], int n)
{    
    int i;
    int  temp;
    buildHeap(a,n);
    for(i=n-1;i>=0;i--)
    {    
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);

    }
}

int main()
{    
    int i;
    int a[]={4,6,3,7,6,9,12,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    heapSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}