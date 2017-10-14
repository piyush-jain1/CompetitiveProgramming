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

ll n;
ll e[100010],s[100010],r[100010], parent[100010],dis[100010];
std::vector<ll> adj[100010];
ll dir;

void bfs(ll u)
{	
	memset(dis, -1, sizeof(dis));
	queue<ll> q;
	q.push(u);
	dis[u] = 0;
	while(!q.empty())
	{
		ll t = q.front(); 
		// r[t] = s[t];
		// DEBUG(t);
		q.pop();
		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{
			ll v = *it;
			if(dis[v] == -1)
			{
				q.push(v);
				// DEBUG(v);
				dis[v] = dis[t] + 1;
				parent[v] = t;
				// r[t] += s[v];
				// DEBUG(v);
			}
		}
	}
}

int main()
{
	ll q;	cin>>n>>q;
	bool flag[100010];
	fill(flag, flag+n,false);
	FOR(i,1,n)
	{
		cin>>e[i];
		if(e[i] == 0)	dir = i;
		flag[e[i]] = true;
		adj[e[i]].pb(i);
		r[i] = 0;
	}	
	// DEBUG(dir);
	parent[1] = 0;
	FOR(i,1,n)	cin>>s[i];

	bfs(dir);
	// FOR(i,1,n)
	// {
	// 	DEBUG(parent[i]);
	// }
	FOR(i,1,n)
	{
		if(!flag[i])
		{
	FOR(i,1,n)
	{
		if(!flag[i])
		{	
			r[i] = s[i];
			while(i!=0)
			{	
				r[parent[i]] += r[i];
				i = parent[i];
				DEBUG(i);
			}
		}
	}	
	FOR(i,1,n)	cout<<r[i]<<" ";
	cout<<endl;


}