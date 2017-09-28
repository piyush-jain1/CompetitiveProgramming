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
const int MAX = 100000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll n;
std::vector<ll> adj[MAX+10];
ll init[MAX+10];
ll goal[MAX+10];
bool visited[MAX+10];
std::vector<ll> v;
void dfs(ll i, ll even, ll odd, ll level)
{
	visited[i] = true;
	for(auto j : adj[i])
	{
		if(!visited[j])
		{
			if(level%2)
			{
				if((init[j]+odd)%2 != goal[j])
				{	
					v.pb(j);
					dfs(j, even, odd+1, level+1);
				}
				else
				{
					dfs(j, even, odd, level+1);
				}
			}
			else
			{
				if((init[j]+even)%2 != goal[j])
				{	
					v.pb(j);
					dfs(j, even+1 , odd, level+1);
				}
				else
				{
					dfs(j, even, odd, level+1);
				}
			}
		}
	}
}

int main()
{
	cin>>n;
	REP(i,n-1)
	{
		ll u,v;	cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i,1,n)	cin>>init[i];
	FOR(i,1,n)	cin>>goal[i];
	fill(visited, visited+n+5, false);
	ll even = 0;
	ll odd = 0;
	ll level = 1;
	if(init[1] != goal[1])
	{
		v.pb(1);
		even++;
	}
	dfs(1,even,odd,level);
	cout<<v.size()<<endl;
	for(auto u : v)
	{
		cout<<u<<endl;
	}
	return 0;
}	