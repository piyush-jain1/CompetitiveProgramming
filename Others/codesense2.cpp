#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
/////////////////////////////////////////////////////////////////////



void DFS_Visit(vector<ll> adj[],ll i,ll d,bool * flag, ll * dist)
{
	flag[i] = true;
	for(auto it = adj[i].begin();it != adj[i].end(); ++it)
	{	
		if(flag[*it] == false)
		{
			dist[*it] = d;
			DFS_Visit(adj,*it,d+1,flag,dist);
		}
	}
}


int main()
{	
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--)
	{	
		ll n,m;
		cin>>n>>m;
		ll u[n+5],v[n+5];

		bool flag[n+10];
		ll dist[n+10];
		std::vector<ll> adj[n+10];

		FOR(i,1,n-1)
		{	
			cin>>u[i]>>v[i];
			adj[u[i]].pb(v[i]);
			adj[v[i]].pb(u[i]);
		}

		ll r[m];
		REP(i,m)
		{
			cin>>r[i];
		}
		FOR(i,1,n)
		{
			flag[i] = false;
			dist[i] = 0;
		}
		ll i = 1;
		ll d = 1;
		DFS_Visit(adj,i,d,flag,dist);
		double total = 0;
		REP(i,m)
		{
			total += (double)dist[r[i]]*2.0;
		}
		std::cout << std::setprecision(6) << std::fixed;
		std::cout<<total/(double)m<<endl;
	


	}
	return 0;
	
}