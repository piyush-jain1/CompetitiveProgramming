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
vector<pair<ll,ll>> adj[100010];
ll d[100010];
ll d1[100010];
std::priority_queue<pair<ll,ll>, std::vector<pair<ll,ll>>, std::greater<pair<ll,ll>> > Q;
int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;	cin>>t;
	while(t--)
	{
		ll n,k,x,m,s;	cin>>n>>k>>x>>m>>s;
		
		REP(i,m)
		{	
			// cout<<"Yo"<<endl;
			ll a,b,c;	cin>>a>>b>>c;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		Q.push(mp(0,s));
		fill(d,d+n+10,1e15);
		d[s] = 0;

		// source belongs to clique
		if(s <= k)
		{	
			FOR(i,1,k)	
			{
				if(i!=s)
				{
					adj[s].pb(mp(i,x));
					adj[i].pb(mp(s,x));
				}	
			}
			while(!Q.empty())
			{	
				
				ll u = Q.top().second;
				Q.pop();
				vector<pair<ll,ll>>::iterator iter;
				for(iter = adj[u].begin(); iter != adj[u].end(); ++iter)
				{
					ll v = (*iter).first;
					ll w = (*iter).second;

					if(d[v] > d[u] + w)
					{
						d[v] = d[u]+w;
						Q.push(mp(d[v],v));
					}
				}
			}
			FOR(i,1,n)
			{
				if(i <= k)	cout<<min(d[i],x)<<" ";
				else	cout<<d[i]<<" ";
			}
			
		}
		else
		{
			ll min_from_clique = 1e15;
			ll min_in_clique;
			while(!Q.empty())
			{	
				ll u = Q.top().second;
				Q.pop();
				vector<pair<ll,ll>>::iterator iter;
				for(iter = adj[u].begin(); iter != adj[u].end(); ++iter)
				{
					ll v = (*iter).first;
					ll w = (*iter).second;

					if(d[v] > d[u] + w)
					{
						d[v] = d[u]+w;
						if(v <= k && min_from_clique > d[v])
						{
							min_from_clique = d[v];
							min_in_clique = v;
						}
						Q.push(mp(d[v],v));
					}
				}
			}
			// DEBUG(Q.size());
			vector<pair<ll,ll>>::iterator iter;
			// DEBUG(min_from_clique);
			Q.push(mp(0,min_in_clique));
			fill(d1,d1+n+10,1e15);
			d1[min_in_clique] = 0;
			FOR(i,1,k)
			{
				if(i!=min_in_clique)
				{
					adj[min_in_clique].pb(mp(i,x));
					adj[i].pb(mp(min_in_clique,x));
				}	
			}	
			while(!Q.empty())
			{	
				ll u = Q.top().second;
				Q.pop();
				vector<pair<ll,ll>>::iterator iter;
				// DEBUG(u);
				for(iter = adj[u].begin(); iter != adj[u].end(); ++iter)
				{
					ll v = (*iter).first;
					ll w = (*iter).second;

					if(d1[v] > d1[u] + w)
					{
						d1[v] = d1[u]+w;
						Q.push(mp(d1[v],v));
					}
				}
			}
			FOR(i,1,n)
			{	
				// DEBUG(i);
				// DEBUG(d[i]);
				// DEBUG(d1[i]+min_from_clique);
				cout<<min(d[i],d1[i]+min_from_clique)<<" ";
			}
		}
		cout<<endl;
		FOR(i,0,n+1)	adj[i].clear();
		

	}
	return 0;
	
}