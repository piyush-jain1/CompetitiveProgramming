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
std::vector<ll> adj[200010];
bool visited[200010];
ll pred[200010]; 
ll disa[200010], disb[200010];
bool flag[200010];
void dfs(ll i)
{
	visited[i] = true;
	for(auto u : adj[i])
	{
		if(!visited[u])
		{	
			pred[u] = i;
			dfs(u);
		}
	}
}
ll maxdist = 0;
void bfsa(ll u)
{
	memset(disa, -1, sizeof(disa));
	queue<ll> q;
	q.push(u);
	disa[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{	
			ll v = *it;
			if(flag[v])
			{
				if(disa[v] == -1)
				{
					q.push(v);
					disa[v] = disa[t] + 1;
					// DEBUG(v);
				}
			}	
		}
	}
}
void bfsb(ll u)
{
	memset(disb, -1, sizeof(disb));
	queue<ll> q;
	q.push(u);
	disb[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{	
			ll v = *it;
			if(flag[v])
			{
				if(disb[v] == -1)
				{
					q.push(v);
					disb[v] = disb[t] + 1;
					// DEBUG(v);
				}
			}	
		}
	}
}
int main()
{	
	fast_io;
	ll n,x;	cin>>n>>x;
	REP(i,n-1)
	{
		ll a,b;	cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	fill(visited, visited+n+5, false);
	dfs(1);
	fill(flag, flag+n+5, true);
	ll p = x;
	while(pred[p]!=1)	p = pred[p];
	for(auto u : adj[1])
	{
		if(u != p)	flag[u] = false;
	}
	// for(auto u : adj[1])
	// {
	// 	if(flag[u])	cout<<u<<endl;
	// }
	bfsa(1);
	bfsb(x);
	ll maxm = 0;
	FOR(i,1,n)
	{
		if(disb[i] < disa[i])	maxm = max(maxm,2*disa[i]);
	}
	cout<<maxm<<endl;
	return 0;

}	