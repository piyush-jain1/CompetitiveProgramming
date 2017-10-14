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

ll a[110],c[110],b[110];
int main()
{	
	// std::cout << std::setprecision(2);
 	// std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,w;	cin>>n>>w;
	std::vector<pair<ll,ll>> cap;
	FOR(i,1,n)
	{
		cin>>a[i];
		cap.pb(mp(a[i],i));
	}
	sort(cap.begin(),cap.end(),sortinrev);
	FOR(i,1,n)
	{
		c[i] = (ll)(ceil((double)a[i]/2.0));
		if(w < c[i])
		{
			cout<<-1<<endl;
			return 0;
		}
		b[i] = c[i];
		w -= c[i];
	}
	ll i = 0;
	while(i < n)
	{	
		if(w <= a[cap[i].second]-b[cap[i].second])
		{
			b[cap[i].second] += w;
			w = 0;
			break;
		}
		else
		{
			w -= (a[cap[i].second]-b[cap[i].second]);
			b[cap[i].second] = a[cap[i].second];
		}
		i++;
	}
	if(w != 0)
	{
		cout<<-1<<endl;
		return 0;
	}
	// FOR(i,1,n)
	// {	
	// 	FOR(j,1,n)
	// 	{
	// 		if(i != j and a[i] > a[j] and b[i] < b[j])
	// 		{
	// 			cout<<-1<<endl;
	// 			return 0;
	// 		}
	// 	}
	// }
	FOR(i,1,n)	cout<<b[i]<<" ";
	cout<<endl;
	return 0;


	
}