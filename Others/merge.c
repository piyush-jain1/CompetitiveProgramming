#include<stdio.h>


void merge(int a[],int l,int m, int r);
void merge_sort(int a[],int l,int r);


int main()
{
    int a[]={5,7,4,6,8,3,9,2,0,1,6};
    int n=sizeof(a)/sizeof(a[0]);
    
    merge_sort(a,0,n-1);
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void merge(int a[],int l,int m, int r)
{
   
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
    {
      L[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {  
      R[j]=a[m+1+j];
    }
    
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    { 
       if(L[i]<R[j])
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

void merge_sort(int a[],int l,int r)
{   
   
    if(l<r)
    {
        int m=(r+l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

           
  
