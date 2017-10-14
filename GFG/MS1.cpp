#include <bits/stdc++.h>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
#define trace(x) cout<<'>'<<#x<<':'<<x<<endl;
set<int> v[255];
void pre()
{
	for(int num = 2; num <= 250; num++)
	{	
		int n = num;
		while(n%2 == 0)
		{
			v[num].insert(2);
			n /= 2;
		}
		for(int i = 3; i <= sqrt(n); i+= 2)
		{
			while(n%i == 0)
			{
				v[num].insert(i);
				n /= i;
			}
		}
		if(n > 2)	v[num].insert(n);
	}
}
int main()
{
	fast_io;
	pre();
	int a[] = {23, 2 ,67, 43, 99, 142, 234, 249, 132, 250};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i < n ; i++)
	{	
		bool flag[255];
		fill(flag, flag+252, true);
		for(int j = 2; j <= 250; j++)
		{	
			for(int k : v[j])
			{	
				if(find(v[a[i]].begin(), v[a[i]].end(), k) != v[a[i]].end())
				{	
					flag[j] = false;
					break;
				}
			}
		}
		int front = 2;
		int back = 250;
		while(a[i] > front and !flag[front])
		{	
			// trace(front);
			front++;
		}
		while(a[i] < back and !flag[back])
		{
			// trace(back);
			back--;
		}
		cout<<((a[i]-front > back-a[i]) ? front:back)<<endl;
	}
	return 0;

}