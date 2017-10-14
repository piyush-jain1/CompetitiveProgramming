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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll MOD  = 1e9 + 7;
ll dp[1005],dp2[1005],l=0;
int main()
{	
	std::ios::sync_with_stdio(false);
	ll n;	cin>>n;
	string s;	cin>>s;
	ll a[27];
	REP(i,26)	cin>>a[i];
	dp[0] = 1;
	dp2[0] = 0;
	FOR(i,1,n)
	{
		ll f = 0;
		dp2[i] = n;
		FORD(x,i-1,0)
		{
			f = max(f,i-a[s[x]-'a']);
			if(f > x)	continue;
			dp[i] = (dp[i]+dp[x])%MOD;
			dp2[i] = min(dp2[i],1+dp2[x]);
			l = max(l,i-x);
		}
	}
	cout<<dp[n]<<endl<<l<<endl<<dp2[n]<<endl;
	return 0;

	
}
