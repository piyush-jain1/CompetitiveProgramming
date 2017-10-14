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

int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,c,d;	cin>>n>>c>>d;
	std::vector<pair<ll,ll>> coin, diam;

	REP(i,n)
	{
		ll b,p;
		char type;
		cin>>b>>p>>type;
		if(type == 'C' and p <= c)	coin.pb(mp(b,p));
		else if(type == 'D' and p<=d)	diam.pb(mp(b,p));	
	}
	sort(coin.begin(),coin.end(),sortbysecdesc);
	sort(diam.begin(),diam.end(),sortbysecdesc);
	ll csize = coin.size();
	ll dsize = diam.size();
	ll bt[n+10];
	bt[csize] = 0;
	FORD(i,csize-1,0)	bt[i] = max(bt[i+1],coin[i].first);
	ll b1=0,b2=0,b3=0;
	b3 += bt[0];
	REP(i,csize-1)
	{	
		ll res = c-coin[i].second;
		ll low = i+1;
		ll high = csize-1;
		while(abs(low - high) > 1)
		{	
			ll mid = (high+low)/2;
			// DEBUG(low);
			// DEBUG(high);
			if(coin[mid].second <= res)	high = mid;
			else	low = mid;	
		}
		// DEBUG(high);
		// DEBUG(low);
		// DEBUG(coin[high].first);
		// DEBUG(coin[low].first);
		// DEBUG(bt[high]);
		// DEBUG(bt[low]);
		if(low < csize and low > i and coin[low].second <= res)
		{
			b1 = max(b1,coin[i].first+bt[low]);
		}
		else if(high < csize and high > i and coin[high].second <= res)
		{
			b1 = max(b1,coin[i].first+bt[high]);
		}	
	}
	bt[dsize] = 0;
	FORD(i,dsize-1,0)	bt[i] = max(bt[i+1],diam[i].first);
	b3 += bt[0];
	REP(i,dsize-1)
	{	
		ll res = d-diam[i].second;
		ll low = i+1;
		ll high = dsize-1;
		while(abs(low - high) > 1)
		{	
			ll mid = (high+low)/2;
			// DEBUG(low);
			// DEBUG(high);
			if(diam[mid].second <= res)	high = mid;
			else	low = mid;	
		}
		if(low < dsize and low > i and diam[low].second <= res)
		{
			b2 = max(b2,diam[i].first+bt[low]);
		}
		else if(high < dsize and high > i and diam[high].second <= res)
		{
			b2 = max(b2,diam[i].first+bt[high]);
		}	
	}

	if(dsize == 0 or csize == 0)	b3 = 0;	
	// DEBUG(b1);
	// DEBUG(b2);
	// DEBUG(b3);
	cout<<max(max(b1,b2),b3)<<endl;
	return 0;
	
	
}