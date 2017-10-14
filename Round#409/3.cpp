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
typedef long double ld;
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
bool sortbysec(const pair<ll,double> &a, const pair<ll,double> &b)	{   return (a.second < b.second);		}	
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define MAX 1e18
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll n,p;
ll a[100010], b[100010];
ld exhaust[100010];

bool check(ld mid)
{
	ld req = 0;
	REP(i,n)
	{
		ld need = max(0.0L, mid*(ld)a[i] - (ld)b[i]);
		req += need;
	}
	ld supply = mid*p;
	return supply>=req;
}

int main()
{	
	std::cout << std::setprecision(9);
  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	REP(i,n)	cin>>a[i]>>b[i];
	ll sum = 0;
	REP(i,n)	sum += a[i];
	if(p >= sum)	
	{
		cout<<-1<<endl;
		return 0;
	}
	ld minm = 0, maxm = MAX;
	REP(i,220)
	{
		ld mid = (minm+maxm)/2.0;
		if(check(mid))	minm = mid;
		else maxm = mid;
	}

	if(maxm > MAX-200)	cout<<-1<<endl;
	else cout<<(double)minm<<endl;

	return 0;
	
}