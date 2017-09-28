#include <stdio.h>



void merge(int a[],int l, int m,int r)
{    
    int i,j,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
     L[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
     R[j]=a[m+1+j];
    }
    i=0;
    j=0;
    int k=l;
    while(i<n1 && j<n2)
    {    
        if(L[i]<=R[j])
        {    
            a[k++]=L[i++];    
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }

}
void mergeSort(int a[],int l,int r)
{   if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);

    }
}
int main()
{    
    int i;
    int a[]={4,6,3,7,6,9,12,5,1};
    int n = sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}