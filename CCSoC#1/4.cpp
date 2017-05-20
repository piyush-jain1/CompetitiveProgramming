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
#define PI 3.14159265
// sorting vector of pairs
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{    return (a.first > b.first);	}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{   return (a.second < b.second);		}	
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


std::vector<ll> adj[100010];
ll n;
ll dis[100010], dis1[100010];

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
void bfs1(ll u)
{
	memset(dis1, -1, sizeof(dis1));
	queue<ll> q;
	q.push(u);
	dis1[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{
			ll v = *it;
			if(dis1[v] == -1)
			{
				q.push(v);
				dis1[v] = dis1[t] + 1;
				// DEBUG(v);
			}
		}
	}
}
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll query;	cin>>n>>query;
	REP(i,n-1)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	bfs(1);
	ll maxm = 0;
	ll id;
	FOR(i,1,n)
	{
		if(dis[i] > maxm)
		{
			maxm = dis[i];
			id = i;
		}
	}
	// DEBUG(id);
	bfs(id);
	maxm = -1;
	FOR(i,1,n)
	{	
		// DEBUG(dis[i]);
		if(dis[i] > maxm)
		{
			maxm = dis[i];
			id = i;
		}
	}
	// DEBUG(id);
	bfs1(id);

	FOR(i,1,query)
	{	
		ll temp;
		cin>>temp;
		// DEBUG(temp);
		// DEBUG(dis[temp]);
		// DEBUG(dis1[temp]);
		cout<<max(dis[temp],dis1[temp])<<endl;
	}
	return 0;




	
}