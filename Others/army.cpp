#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size1,price1,size2,price2;
    cin>>size1>>price1;
    cin>>size2>>price2;
    double prod1 = (double)size1 / (double)price1;
    double prod2 = (double)size2 / (double)price2;
    if(prod1<prod2)
    {
        cout<<"second"<<endl;
    }
    if(prod1>prod2)
    {
        cout<<"first"<<endl;
    }
    else
    {
        cout<<"both"<<endl;
    }
    return 0;
}