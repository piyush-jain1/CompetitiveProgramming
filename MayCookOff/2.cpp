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
#define mod 1000000007

ll n;
ll a[5010];
set<ll> f, flast;
void factorize()
{
	REP(j,n-1)
	{
		ll num = a[j];
		ll sq = sqrt(num);
		while(num%2 == 0)
		{
			f.insert(2);
			num /= 2;
		}
		for(ll i = 3; i <= sq; i+=2)
		{
			while(num%i == 0)	
			{
				f.insert(i);
				num /= i;
			}
		}
		if(num > 2)	f.insert(num);
	}
}


ll getpow(ll a)
{	
	ll ans = 1;
	ll b = mod-2;
	while(b > 0)
	{
		if(b & 1)	ans = (ans*a)%mod;
		b = b/2;
		a = (a*a)%mod;
	}
	// DEBUG(ans);
	return ans%mod;
}
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,n)	cin>>a[i];
	sort(a,a+n);
	ll num = a[n-1];
	ll sq = sqrt(num);
	while(num%2 == 0)
	{
		flast.insert(2);
		num /= 2;
	}
	for(ll i = 3; i <= sq; i+=2)
	{
		while(num%i == 0)	
		{
			flast.insert(i);
			num /= i;
		}
	}
	if(num > 2)	flast.insert(num);
	factorize();
	// for(auto u:flast)	cout<<u<<" ";
	// cout<<endl;
	// for(auto u:f)	cout<<u<<" ";
	ll sizea = f.size();
	for(auto u:flast)	f.insert(u);
	// bool flag = true;
	if(sizea == f.size())
	{
		cout<<"justdoit"<<endl;
		return 0;
	}
	
	// for(auto u:f)	cout<<u<<" ";	
	ll newnum = 1;
	for(auto u:f)	newnum = (u*newnum)%mod;
	// DEBUG(target);
	ll target;
	if(newnum < a[n-1])	target = a[n-1];
	else target = newnum;
	ll x = target;
	REP(i,n)
	{
		x = (x*target)%mod;
	}
	REP(i,n)
	{	
		// DEBUG(getpow(a[i]));
		x = (x*getpow(a[i]))%mod;
	}
	x = (x*target)%mod;
	x = (x*getpow(newnum))%mod;
	// DEBUG(x);
	cout<<x%mod<<endl;
	return 0;

	
}