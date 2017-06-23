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

ll powerx[100], powery[100];

int main()
{	
	fast_io;
	ll x,y,l,r;	cin>>x>>y>>l>>r;
	powerx[0] = 1;
	powery[0] = 1;
	ll i = 0;
	ll lenx = 0;
	ll leny = 0;
	while(powerx[i] <= r/x)
	{
		i++;
		powerx[i] = powerx[i-1]*x;
		lenx++;
	}
	i = 0;
	while(powery[i] <= r/y)
	{
		i++;
		powery[i] = powery[i-1]*y;
		leny++;
	}
	ll maxm = 0;
	ll prev = l-1;
	std::set<ll> v;
	FOR(i,0,lenx)
	{
		FOR(j,0,leny)
		{	
			// DEBUG(powerx[i]);
			// DEBUG(powery[j]);
			if(powerx[i] + powery[j] >= l and powerx[i] + powery[j] <= r)
			{	
				// DEBUG(powerx[i]);
				// DEBUG(powery[j]);
				// DEBUG(powerx[i] + powery[j]);
				v.insert(powerx[i] + powery[j]);
			}	
		}
	}
	for(auto u : v)
	{	
		// DEBUG(u);
		// DEBUG(u-prev-1);
		maxm = max(maxm,u-prev-1);
		prev = u;
	}
	maxm = max(maxm, r-prev);
	cout<<maxm<<endl;
	return 0;

}