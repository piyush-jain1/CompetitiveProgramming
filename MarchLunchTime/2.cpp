#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

#define MOD 1000000007
char a[60][60];
bool visited[60][60];
std::vector<pair<ll,ll>> v[2510];

void dfs_visit(ll i, ll j, ll dis, ll n)
{	
	visited[i][j] = true;
	v[dis].pb(mp(i,j));
	if(i+1 <= n && visited[i+1][j] == false)
	{	
		if(a[i+1][j] == '?')	dfs_visit(i+1,j,dis,n);
	}
	if(i-1 >= 1 && visited[i-1][j] == false)
	{
		if(a[i-1][j] == '?')	dfs_visit(i-1,j,dis,n);
	}
	if(j+1 <= n && visited[i][j+1] == false)
	{
		if(a[i][j+1] == '?') dfs_visit(i,j+1,dis,n);
	}
	if(j-1 >= 1 && visited[i][j-1] == false)
	{
		if(a[i][j-1] == '?')	dfs_visit(i,j-1,dis,n);
	}
	return;
}

ll dfs(ll n)
{	
	ll dis = 0;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			if(!visited[i][j] && a[i][j] == '?')
			{
				dis++;
				// cout<<"("<<i<<","<<j<<")"<<endl;
				dfs_visit(i,j,dis,n);
			}
		}
	}
	return dis;
}

bool check(ll i,ll j,char c,ll n)
{
	if((i+1 <= n && a[i+1][j] == c) || (i-1 >= 0 && a[i-1][j] == c ) || (j+1 <= n && a[i][j+1] == c) || (j-1 >= 0 && a[i][j-1] == c))
	{
		return true;
	}
	return false;
}

int main()
{	
	std::ios::sync_with_stdio(false);
	ll t;	cin>>t;
	while(t--)
	{
		bool care = false;
		ll n;	cin>>n;
		FOR(i,1,n)
		{
			FOR(j,1,n)
			{
				cin>>a[i][j];
			
				if(i!=1)
				{
					if(a[i][j]+a[i-1][j] == 'B'+'P' || a[i][j]+a[i-1][j] == 'G'+'G')
					{
						care = true;
					}
				}
				if(j!=1)
				{
					if(a[i][j]+a[i][j-1] == 'B'+'P' || a[i][j]+a[i][j-1] == 'G'+'G')
					{
						care = true;
					}
				}
			}
		}
		if(care)
		{
			cout<<0<<endl;
		}
		if(!care)
		{	
			FOR(i,1,n)
			{
				FOR(j,1,n)
				{
					visited[i][j] = false;
				}
			}
			ll dis = dfs(n);
			ll ans = 1;
			ll b,p,g;
			FOR(k,1,dis)
			{	
				// DEBUG(k);
				b=0;
				p=0;
				g=0;
				// DEBUG(v[k].size());
				if(v[k].size() == 1)
				{	

					if(check(v[k][0].f,v[k][0].s,'B',n))
					{
						b++;
					}
					if(check(v[k][0].f,v[k][0].s,'P',n))
					{
						p++;
					}
					if(check(v[k][0].f,v[k][0].s,'G',n))
					{
						g++;
					}
					if(g > 0 || (b>0 && p>0))
					{
						cout<<0<<endl;
						care = true;
						break;
					}
					else if(p==0 && b ==0)
					{	
						// DEBUG(k);
						ans = (ans*3)%MOD;

					}
				}
				else
				{
					for(auto it = v[k].begin(); it != v[k].end() ; ++it)
					{
						if(check(it->f,it->s,'B',n))
						{
							b++;
						}
						if(check(it->f,it->s,'P',n))
						{
							p++;
						}
						if(check(it->f,it->s,'G',n))
						{
							g++;
						}

					}

					if(g > 0 || (b>0 && p>0))
					{
						cout<<0<<endl;
						care = true;
						break;
					}
					else if(p==0 && b ==0)
					{
						ans = (ans*2)%MOD;
						
					}
				}
			}
			REP(i,dis+1)
			{
				v[i].clear();
			}
			if(!care)	cout<<ans<<endl;
		}
		
		
	}
	return 0;
}