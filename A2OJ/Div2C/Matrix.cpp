#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define int_64 uint64_t
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
#define mod 1000000007
////////////////////////////////////////////////////////////////////////////////////////

int presum[4010];
map<int,int> present;
int main()
{	
	fast_io;
	int a;	cin>>a;
	string s;	cin>>s;
	presum[0] = 0;
	int n = s.length();
	FOR(i,1,n)
	{
		int temp =  s[i-1]-'0';
		presum[i] = presum[i-1]+temp;
	}
	int tot = 0;
	FOR(i,1,n)
	{
		FOR(j,i,n)
		{	
			int temp = presum[j]-presum[i-1];
			present[temp]++;
		}
	}
	ll count = 0;
	FOR(i,1,n)
	{
		FOR(j,i,n)
		{		
			if(presum[j]-presum[i-1] == 0)
			{
				if(a == 0)
				{
					count += (n*n + n)/2;
					continue;
				}
				else	continue;
			}
			if(a%(presum[j]-presum[i-1]) == 0)
			{
				count += present[a/(presum[j]-presum[i-1])];
			}
		}
	}
	cout<<count<<endl;
	return 0;
}