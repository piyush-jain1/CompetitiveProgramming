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

ll n,s;
ll eff[100010];
std::vector<pair<ll,ll>> v;

ll cost(ll k)
{	
	fill(eff, eff+k+8, 0);
	FOR(i,0,n-1)
	{
		eff[i] = (v[i].first + (k*v[i].second));
	}
	sort(eff,eff+n);
	ll c = 0;
	FOR(i,0,k-1)
	{
		c += eff[i];
	}
	return c;
}
int main()
{	
	fast_io;
	cin>>n>>s;
	FOR(i,1,n)
	{
		ll temp;
		cin>>temp;
		v.pb(mp(temp,i));
	}
	// sort(v.begin(), v.end());
	ll high = n;
	ll low = 0;
	while(high-low > 1)
	{	
		ll mid = (low+high)/2;
		if(cost(mid) > s)	high = mid;
		else low = mid;
	}
	if(cost(high) <= s)	cout<<high<<" "<<cost(high)<<endl;
	else cout<<low<<" "<<cost(low)<<endl;
	return 0;
	
}