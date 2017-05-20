#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
#define F first
#define S second
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



int main()
{
	ll n,m;
	cin>>n>>m;
	ll a[n+10];
	std::map<ll,pair<pair<ll,ll>,ll>> beauty;
	FOR(i,1,n)
	{
		cin>>a[i];
		beauty[i] = mp(mp(0,0),0);
	}
	ll j = 1;
	a[n+1] = -1;
	while(j <= n)
	{
		ll i = j;
		while(a[i+1] == a[i])
		{
			i++;
		}
		beauty[j] = mp(mp(j,i),a[i]);
		j = i+1;
	}
	FOR(j,1,n)
	{
		if(beauty[j].F.F == 0 && beauty[j].F.S == 0)
		{
			beauty[j] = beauty[j-1];
		}
	}
	// FOR(j,1,n)
	// {
	// 	cout<<beauty[j].F.F<<" "<<beauty[j].F.S<<" "<<beauty[j].S<<endl;
	// }
	
	REP(i,m)
	{
		ll l,r,k;
		cin>>l>>r>>k;
		ll mid = l + (r-l+1)/2;
		// DEBUG(mid);
		//cout<<beauty[mid].F.F<<" "<<beauty[mid].F.S<<" "<<beauty[mid].S<<endl;
		ll left = ((beauty[mid].F.F > l) ? beauty[mid].F.F : l);
		ll right = ((beauty[mid].F.S < r) ? beauty[mid].F.S : r);
		// DEBUG(left);
		// DEBUG(right);
		if((right-left+1) >= k)
		{
			cout<<beauty[mid].S<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
	
}