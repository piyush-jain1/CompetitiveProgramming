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

ll a[500010];
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	ll sum = 0;
	FOR(i,1,n)
	{
		cin>>a[i];
		sum += a[i];
	}
	ll sum1 = 0;
	if(sum%3 != 0)
	{
		cout<<0<<endl;
		return 0;
	}
	ll count = 0;
	if(sum == 0)
	{
		FOR(i,1,n)
		{
			sum1 += a[i];
			if(sum1 == 0)	count++;
		}
		count-=2;
		// DEBUG(count);
		ll ans = count*(count+1);
		cout<<ans/2<<endl;
		return 0;

	}
	ll b[n+10];
	b[0] = 0;
	FOR(i,1,n)	b[i] = a[i]+b[i-1];
	ll target1 = sum/3;
	ll target2 = 2*target1;
	ll count1 = 0, count2 = 0;
	ll total = 0;
	FOR(i,1,n)
	{	
		// DEBUG(b[i]);
		if(b[i] == target1)	
		{
			if(count2 > 0)
			{
				total += count1*count2;
				count2 = 0;
			}
			count1++;
		}
		else if(b[i] == target2)	count2++;	
	}
	total += count1*count2;
	cout<<total<<endl;
	return 0;

	


	
}