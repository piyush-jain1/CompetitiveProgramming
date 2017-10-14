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
#define MAX 100000
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll n;
ll cost[MAX+10];
ll m;
std::vector<ll> adj1[MAX+10], adj2[MAX+10];
bool visited[MAX+10] = {false};
std::vector<ll> topological;
ll minm[MAX+10] = {0};
ll mincnt[MAX+10] = {0};
void dfs_visit(ll i)
{
	visited[i] = true;
	for(auto j: adj1[i])
	{
		if(!visited[j])
		{
			dfs_visit(j);
		}
	}
	topological.pb(i);
}
void dfs_visit_tr(ll i, ll index)
{

	visited[i] = true;
	minm[index] = min(minm[index], cost[i]);
	for(auto j:adj2[i])
	{
		if(!visited[j])
		{
			dfs_visit_tr(j,index);
		}
	}
}
void dfs_visit_tr1(ll i, ll index)
{

	visited[i] = true;
	// DEBUG(cost[i]);
	if(cost[i] == minm[index])	mincnt[index]++;
	for(auto j:adj2[i])
	{	
		// DEBUG(j);
		// DEBUG(visited[j]);
		if(!visited[j])
		{
			dfs_visit_tr1(j,index);
		}
	}
}
int main()
{	
	cin>>n;
	FOR(i,1,n)	cin>>cost[i];
	cin>>m;
	REP(i,m)
	{
		ll u,v;	cin>>u>>v;
		adj1[u].pb(v);
		adj2[v].pb(u);
	}
	FOR(i,1,n)
	{
		if(!visited[i])
		{
			dfs_visit(i);
		}	
	}
	ll total = 0;
	reverse(topological.begin(), topological.end());
	// for(auto u : topological)	cout<<u<<" ";
	// 	cout<<endl;
	fill(visited, visited+n+5, false);
	ll index = 0;
	FOR(i,1,n)
	{
		if(!visited[topological[i-1]])
		{	
			minm[index] = INT_MAX;
			dfs_visit_tr(topological[i-1], index);
			// DEBUG(minm[index]);
			total += minm[index];
			index++;
		}
	}
	fill(visited, visited+n+5, false);
	index = 0;
	ll ans = 1;
	FOR(i,1,n)
	{
		if(!visited[topological[i-1]])
		{	
			dfs_visit_tr1(topological[i-1], index);
			// DEBUG(mincnt[index]);
			ans = (ans*mincnt[index])%mod;
			index++;
		}	
	}
	cout<<total<<" "<<ans<<endl;
	return 0;
}