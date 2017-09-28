/// Given Length and Sum of Digits...
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
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll len;
ll m, s;
ll a[105];
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>s;
	ll over = m*9;
	bool flag = true;
	if(m == 1 && s== 0)
	{
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	if(s == 0 || s > over)	flag = false;

	ll total = 1;
	if(flag)
	{	
		a[0] = 1;
		FOR(i,1,m-1)	a[i] = 0;
		ll i = m-1;
		while(total<s)
		{
			a[i--] += min(9LL,s-total); 
			total += min(9LL,s-total); 
		}
		REP(i,m)	cout<<a[i];
		cout<<" ";
		REP(i,m)	a[i] = 9;
		i = m-1;
		while(over>s)
		{
			a[i--] -= min(over-s,9LL);
			over -= min(over-s,9LL);
		}
		REP(i,m)	cout<<a[i];	
	}
	else	cout<<-1<<" "<<-1;
	cout<<endl;
	return 0;
	
	

	
}