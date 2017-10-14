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


int main()
{
	ll n,p;	cin>>n>>p;
	vector<char> s;
	s.pb('q');
	char temp ;
	FOR(i,1,n)	
	{
		cin>>temp;
		s.pb(temp);
	}
	ll count = 0;
	ll maxm = 0, minm  = 0;
	if(n%2)
	{	
		ll l = ceil((double)n/2.0);
		if(p < l) p = 2*l-p;
		FOR(i,l+1,n)
		{
			if(s[2*l - i] != s[i])
			{
				count += (abs(s[2*l - i] - s[i]) > 13)	? 26-abs(s[2*l - i] - s[i]) : abs(s[2*l - i] - s[i]);
				if(p > i)	maxm = max(p-i,maxm);
				else if(p < i)	minm = min(p-i,minm);
			}
		}
		count += (abs(maxm) >= abs(minm)) ? 2*abs(minm)+abs(maxm) : 2*abs(maxm)+abs(minm);	
	}
	else
	{
		ll l = ceil((double)n/2.0);
		if(p < l)	p = 2*l-p+1;
		FOR(i,l+1,n)
		{
			if(s[2*l - i + 1] != s[i])
			{
				count += (abs(s[2*l - i + 1] - s[i]) > 13)	? 26-abs(s[2*l - i + 1] - s[i]) : abs(s[2*l - i + 1] - s[i]);
				if(p > i)	maxm = max(p-i,maxm);
				else if(p < i)	minm = min(p-i,minm);
			}
		}
		count += (abs(maxm) >= abs(minm)) ? 2*abs(minm)+abs(maxm) : 2*abs(maxm)+abs(minm);	
	}
	cout<<count<<endl;
	return 0;
}