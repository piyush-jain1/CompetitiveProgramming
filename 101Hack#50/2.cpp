#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
using namespace std;
///////////////////////////////////////////////////////
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
// sorting vector of pairs
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{    return (a.first > b.first);	}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{   return (a.second < b.second);		}	
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{	
	fast_io;
	int q;	cin>>q;
	while(q--)
	{
		int n;	cin>>n;
		int un = 0;
		int one = 0;
		int total = 0;
		int a[n+10];
		bool flag[n+10];
		fill(flag, flag+n+5, true);
		REP(i,n)
		{
			int temp;	cin>>temp;
			a[i] = temp;
			if(temp%2 != i%2)
			{
				if(temp == 1)	one++;
				else un++;
				flag[i] = false;
			}
			else	total += temp;
		}
		if((un+one)%2 == 1)	cout<<-1<<endl;
		else
		{
			if(one <= un)	cout<<(un+one)/2<<endl;
			else
			{
				int res = one-un;
				if(res%2 == 1)	cout<<-1<<endl;
				else
				{	
					int ans = un;
					int i = 0;
					while(res>0 and i < n)
					{
						if(flag[i] and a[i] > 2)
						{
							if((a[i]-1)/2 > res)
							{
								res = 0;
							}
							else
							{
								if(a[i]%2 == 1)	res -= (a[i]-1);
								else res -= (a[i]-2);
							}
						}
						i++;
					}
					if(res > 0)	cout<<-1<<endl;
					else cout<<ans+res<<endl;
				}
				
			}
		}
	}
	return 0;
}