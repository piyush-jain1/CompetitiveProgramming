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


int dis[100010];


const int MAX = 200005;
vector<int> adj[MAX];
int d[MAX], par[20][MAX], n;
void dfs(int p, int v)
{
	d[v] = d[p] + 1;
	par[0][v] = p;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u != p)
			dfs(v, u);
	}
}
void init()
{
	for (int h = 1; h < 20; h++)
		for (int v = 1; v <= n; v++)
			par[h][v] = par[h - 1][par[h - 1][v]];
}
int get_parent(int v, int k)
{
	for (int h = 0; h < 20; h++)
		if ((1 << h) & k)
			v = par[h][v];
	return v;
}
bool is_parent(int u, int v)
{
	if (d[u] > d[v])
		return false;
	return (get_parent(v, d[v] - d[u]) == u);
}
int lca(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	u = get_parent(u, d[u] - d[v]);
	if (u == v)
		return v;
	for (int h = 19; h >= 0; h--)
		if (par[h][u] != par[h][v])
		{
			u = par[h][u];
			v = par[h][v];
		}
	return par[0][v];
}
int dist(int u, int v)
{
	return d[u] + d[v] - 2 * d[lca(u, v)];
}
int solve(int r, int u, int v)
{
	if (is_parent(r, u) && is_parent(r, v))
		return lca(u, v);
	if (is_parent(r, u) || is_parent(r, v))
		return r;
	if (is_parent(u, r))
	{
		if (is_parent(v, r))
			return (d[u] > d[v] ? u : v);
		int p = lca(v, r);
		return (is_parent(u, p) ? p : u);
	}
	else if (is_parent(v, r))
	{
		int p = lca(u, r);
		return (is_parent(v, p) ? p : v);
	}
	int p1 = lca(r, u);
	int p2 = lca(r, v);
	int p3 = lca(u, v);
	if (p1 == p2)
		return p3;
	if (p1 == p3)
		return p2;
	return p1;
}
void bfs(ll u)
{
	memset(dis, -1, sizeof(dis));
	queue<ll> q;
	q.push(u);
	dis[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{
			ll v = *it;
			if(dis[v] == -1)
			{
				q.push(v);
				dis[v] = dis[t] + 1;
				// DEBUG(v);
			}
		}
	}
}
int main()
{	
	fast_io;
	int n,q;	cin>>n>>q;
	FOR(i,2,n)
	{
		int temp;	cin>>temp;
		adj[i].pb(temp);
		adj[temp].pb(i);
	}
	dfs(0, 1);
	init();
	bfs(1);
	int ans = 0;
	while(q--)
	{
		int a,b,c;	cin>>a>>b>>c;

		int x = dis[b]+dis[c]-2*dis[solve(1,b,c)];
		int y = dis[a]+dis[b]-2*dis[solve(1,a,b)];
		int z = dis[c]+dis[a]-2*dis[solve(1,c,a)];
		cout<<solve(1,b,c)<<endl;
		ans = max((x+y-z)/2, max((y+z-x)/2, (z+x-y)/2));
		cout<<ans+1<<endl;
	}
	return 0;
	
}