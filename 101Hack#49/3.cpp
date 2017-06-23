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
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define int_64 uint64_t
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(ll x,ll y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
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
#define MAX 100000
ll c[MAX+10];
std::vector<ll> adj[MAX+10];
std::vector<pair<ll,ll>> edge;
ll charge[MAX+10] = {0};
// map<pair<ll,ll>,ll> w;
bool visited[MAX+10];
ll red[MAX+10] = {0}, black[MAX+10] = {0};
ll pred[MAX+10];
ll w[MAX+10];
ll total_red = 0;
ll total_black = 0;

void dfs(ll i)
{	
	ll r = 0;
	ll b = 0;
	visited[i] = true;
	// DEBUG(i);
	for(auto j : adj[i])
	{
		if(!visited[j])
		{
			// DEBUG(j);
			dfs(j);
			r+=red[j];
			b+=black[j];
			pred[j] = i;
		}
	}
	if(c[i] == 0)
	{
		red[i] = r+1;
		black[i] = b;
	}
	else
	{
		red[i] = r;
		black[i] = b+1;
	}
	// DEBUG(red[i]);
	// DEBUG(black[i]);
}


ll contribution(ll i)
{	
	ll ans = 0;
	ll a = edge[i].first;
	ll b = edge[i].second;
	if(a == 1 or pred[b] == a)
	{	
		// DEBUG(red[b]);
		// DEBUG(black[b]);
		ans += w[i]*red[b]*(total_black-black[b]);
		ans += w[i]*black[b]*(total_red-red[b]);
	}
	else
	{	
		ans += w[i]*red[a]*(total_black-black[a]);
		ans += w[i]*black[a]*(total_red-red[a]);
	}
	// DEBUG(ans);
	return ans;
}
int main()
{
	ll n;	cin>>n;
	FOR(i,1,n)
	{
		cin>>c[i];
		if(c[i] == 0)	total_red++;
		else total_black++;
	}
	REP(i,n-1)
	{
		ll u,v,wgt;	cin>>u>>v>>wgt;
		adj[u].pb(v);
		adj[v].pb(u);
		edge.pb(mp(u,v));
		w[i] = wgt;
	}
	// cout<<"yo"<<endl;
	fill(visited, visited+MAX+5, false);
	pred[1] = INT_MAX;
	dfs(1);
	ll total = 0;
	// FOR(i,1,n)	cout<<red[i]<<" "<<black[i]<<endl;
	REP(i,n-1)
	{
		total += contribution(i);
	}
	cout<<total<<endl;
	return 0;
	

}
