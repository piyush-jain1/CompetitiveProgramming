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
int n;
int a[100010];
std::vector<int> p;

void sieve(int n)
{
	bool prime[100010];
	memset(prime, true, sizeof(prime));
	for(int i = 3; i <= sqrt(n); i++)
	{
		if(prime[i])
		{
			for(int j = i*2; j <= n; j+= i)
				prime[j] = false;
		}
	}
	for(int i = 3; i <= n; i++)
	{	
		if(prime[i])	p.pb(i);
	}
}	



int main()
{	
	fast_io;
	cin>>n;
	int c = 0;
	REP(i,n)
	{
		cin>>a[i];
		c += a[i];
	}
	sieve(c);
	bool modi = false;
	for(auto v : p)
	{	
		// trace(v);
		if(n%v == 0)
		{	
			int len = n/v;
			// trace(len);
			for(int j = 0; j <= len; j++)
			{	
				int cnt = 0;
				bool ok = true;
				for(int k = j; k < n; k += len)
				{
					if(a[k] == 0)
					{
						ok = false;
						break;
					}
				}
				if(ok)
				{
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}