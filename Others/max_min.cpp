#include <iostream>
#include <stdlib.h>

using namespace std;

int maximum,minimum;
void getMaxMin(int arr[], int n)
{
  int diff = -1;
  int num1=arr[0],num2=arr[0];
  int i,j;
  for(i = 0; i < n; i++)
  {
    for(j=i+1; j < n; j++)
    {
      if(diff < abs(arr[i]-arr[j]))
      {
        diff = abs(arr[i]-arr[j]);
        num1 = arr[i];
        num2 = arr[j];
      }
    }
  }
  if(num1 >= num2)
  {
    maximum = num1;
    minimum = num2;
  }
  else
  {
    maximum = num2;
    minimum = num1;
  }
  return;
}

int main()
{
  int arr[] = {12,12,4,423,22,5646,76,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  getMaxMin(arr,n);
  cout<<maximum<<" "<<minimum<<endl;
  return 0;
}
