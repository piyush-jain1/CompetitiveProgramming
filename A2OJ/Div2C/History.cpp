#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
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
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	ll n;	cin>>n;
	std::vector<pair<ll,ll>> v;
	REP(i,n)
	{
		ll a,b;	cin>>a>>b;
		v.pb(mp(a,b));
	}
	sort(v.begin(),v.end());
	ll curr_max = v[0].second;
	ll count = 0;
	FOR(i,1,n-1)
	{
		if(v[i].second < curr_max)	count++;
		else curr_max = v[i].second;
	}
	cout<<count<<endl;
	return 0;
}