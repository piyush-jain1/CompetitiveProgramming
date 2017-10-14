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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll a[1010];
int main()
{	
	fast_io;
	ll n;	cin>>n;
	ll sum = 0;
	FOR(i,1,n)
	{
		cin>>a[i];
		sum += a[i];
	}	
	ll m;	cin>>m;
	ll last = -1;
	ll  got = 100010;
	ll l[1010], r[1010];
	ll i = 0;
	while(i<m)
	{
		cin>>l[i]>>r[i];
		if(sum <= r[i])
		{
			cout<<max(sum,l[i])<<endl;
			return 0;
		}
		i++;
	}
	cout<<-1<<endl;
	return 0;
}