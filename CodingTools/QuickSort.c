#include <stdio.h>

int partition(int a[],int n,int f, int l, int pivot)
{
    int i=f;
    int j=l;
    int temp;
    while(i<=j)
    {
        while(a[j]>=pivot && j>=f)
        {
            j--;
        }
        while(a[i]<pivot && i<=l)
        {
            i++;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    return j;
}

void quickSort(int a[], int n,int p, int r)
{    
    int j,temp;
    if(p<r)
    {
        j=partition(a, n, p+1,r,a[p]);
        temp=a[p];
        a[p]=a[j];
        a[j]=temp;            //pivot moved to right place
        quickSort(a,n,p,j-1);
        quickSort(a,n,j+1,r);

    }
}

int main()
{    
    int i;
    int a[]={4,6,3,7,6,9,12,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a,n,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}