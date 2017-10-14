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


ll a[105][105];
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;	cin>>t;
	ll h=1;
	while(t--)
	{
		ll n,m,k;	cin>>n>>m>>k;
		FOR(i,1,n)
		{
			FOR(j,1,m)
			{
				cin>>a[i][j];
			}
		}
		bool flag = true;
		FOR(i,1,n)
		{
			FOR(j,2,m)
			{
				if(a[i][j-1] == a[i][j])	h++;
				else h = 1;
			}
			if(h > k)	
			{
				flag = false;
				break;
			}
			h = 1;
		}
		ll v =1;
		FOR(j,1,m)
		{
			FOR(i,2,n)
			{
				if(a[i-1][j] == a[i][j])	v++;
				else v = 1;
			}
			if(v > k)
			{
				flag = false;
				break;
			}
			v = 1;
		}
		if(flag)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;

	}



	
}