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
	std::ios::sync_with_stdio(false);
	string s;	cin>>s;
	ll len = s.length();
	if(len == 1)
	{
		cout<<0<<endl;
		return 0;
	}
	ll count = 0;
	bool flag[len+10];
	fill(flag, flag+len+5, false);
	bool one = false;
	REP(i,len-1)
	{
		if(s[i] == 'V' && s[i+1] == 'K')
		{
			flag[i] = true;
			flag[i+1] = true;
			count++;
		}	
	}
	REP(i,len-1)
	{
		if((s[i] == 'V' && s[i+1] == 'V' || s[i] == 'K' && s[i+1] == 'K') && flag[i] == false && flag[i+1] == false)
		{
			one = true;
			break;
		}
	}
	if(one)	cout<<count+1<<endl;
	else	cout<<count<<endl;
	return 0;

	
}