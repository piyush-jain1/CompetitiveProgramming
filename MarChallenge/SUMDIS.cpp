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

ll a[100010],b[100010],c[100010];
int main()
{
	ll t;		cin>>t;
 
	while(t--)
	{	
		// DEBUG(t);
		ll n;	cin>>n;
		ll dist,dist1,dist2,dist3;
		ll ans = 0;
		FOR(i,1,n-1)
		{
			cin>>a[i];
			ans += a[i];
		}
		FOR(i,1,n-2)
		{	
			cin>>b[i];
			b[i] = min(b[i],a[i]+a[i+1]);
			ans += b[i];
		}
		FOR(i,1,n-3)
		{
			cin>>c[i];
			c[i] = min(min(min(c[i],b[i]+a[i+2]),a[i]+b[i+1]),a[i]+a[i+1]+a[i+2]);
			ans += c[i];
		}
		if(n > 1000)
		{
			ll wans = 0;
			FOR(i,1,n-1)
			{
				wans += a[i]*(n-i)*i;
			}
			cout<<wans<<endl;
		}
		else
		{
			FOR(i,1,n-1)
			{	
				dist1 = c[i];
				dist2 = b[i];
				dist3 = a[i];
		
				FOR(v,i+4,n)
				{
					dist = min(min(dist1 + a[v-1], dist2+b[v-2]), dist3 + c[v-3]);
					dist3 = dist2;
					dist2 = dist1;
					dist1 = dist;
					ans += dist;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
 
} 