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

std::vector<int> adj[3010];
int main()
{	
	fast_io;
	int n,m;	cin>>n>>m;
	bool flag[n+5][n+5];
	FOR(i,1,n)
	{
		FOR(j,1,n)	flag[i][j] = false;
	}
	REP(i,m)
	{	
		int u,v;	cin>>u>>v;
		adj[u].pb(v);
		flag[u][v] = true;
	}
	ll ans = 0;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{	
			if(i != j)
			{
				ll cnt = 0;
				for(auto p : adj[i])
				{
					if(p != i and p != j and flag[p][j])
						cnt++;
				}
				// trace2(i,j);
				// trace(cnt);
				ans += ((cnt)*(cnt-1))/2;
			}
		}
	}	
	cout<<ans<<endl;
	return 0;
	
}