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
ll n;
std::vector<pair<ll,ll>> v;
bool flag[110] = {false};
ll counter = 0;

void dfsVisit(ll i)
{	
	flag[i] = true;
	std::vector<ll> got;
	ll x = v[i].first;
	ll y = v[i].second;
	REP(i,n)
	{
		if(((v[i].second == y and v[i].first != x) or (v[i].second != y and v[i].first == x)) and !flag[i])	got.pb(i);
	}
	// DEBUG(v[i].first);
	// DEBUG(v[i].second);
	// search(x,y);
	for(auto j : got)
	{
		dfsVisit(j);
	}
}
void dfs()
{
	REP(i,n)
	{
		if(!flag[i])
		{
			counter++;
			dfsVisit(i);
			// cout<<endl;
		}
	}
}

int main()
{
	cin>>n;
	REP(i,n)
	{	
		ll x,y;	cin>>x>>y;
		v.pb(mp(x,y));
	}
	// sort(v.begin(), v.end(), sortbysec);
	dfs();
	
	cout<<counter-1<<endl;
	return 0;
}