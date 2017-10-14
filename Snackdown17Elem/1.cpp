#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll a[100010];
ll lt[100010], rt[100010];

int main()
{	
	fast_io;
	ll t;	cin>>t;
	while(t--)
	{	
		lt[0] = 1;
		rt[n+1] = 1; 
		ll n;	cin>>n;
		ll ans = 0;
		lt[1] = a[1];
		FOR(i,2,n)
		{
			cin>>a[i];
			lt[i] = (lt[i-1]*a[i])%mod;
			ans += 
		}
		FORD(i,n,1)
		{
			rt[i] = (rt[i+1]*a[i])%mod;
		}

	}
	
}