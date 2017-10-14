#include <iostream>

using namespace std;

int main()
{
    long long int n, temp=0,i,start,ends;
    
    cin>>n;
    long long int a[n+10];
    for(i=1;i<=n;i++){
        cin>>a[i];
    }

    start =1;
    ends = n;

    while (start <= n/2)
    {
        temp = a[start];
        a[start] = a[ends];
        a[ends] = temp;
        start+=2;
        ends-=2;
    }
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}