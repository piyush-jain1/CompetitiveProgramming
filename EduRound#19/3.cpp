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
		cout<<s<<endl;
		return 0;
	}
	ll minm[len+10];
	minm[len-1] = s[len-1];
	FORD(i,len-2,0)
	{	
		if(s[i] <= minm[i+1])	minm[i] = s[i];
		else minm[i] = minm[i+1];
	}
	// FOR(i,0,len-1)	cout<<minm[i];
	char t[len+10],u[len+10];
	ll curr_t = 0, curr_u = 0;
	REP(i,len)
	{	
		if(curr_t == 0)	t[curr_t++] = s[i];
		else
		{
			if(t[curr_t-1] <= minm[i])
			{	
				u[curr_u++] = t[--curr_t];
				i--;
			}	
			else	t[curr_t++] = s[i];
		}
		
	}
	
	for(ll j = 0; j < curr_u; j++)	cout<<u[j];
	for(ll j = (curr_t - 1); j >= 0; j--)	cout<<t[j];	
	cout<<endl;
	return 0; 
}