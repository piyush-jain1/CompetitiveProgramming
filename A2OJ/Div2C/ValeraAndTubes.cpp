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
	ll n,m,k;	cin>>n>>m>>k;
	ll p = 1, q = 1;
	ll moder = 0;
	FOR(i,1,k-1)
	{
		cout<<"2 "<<p<<" "<<q<<" ";
		if(moder%2 == 0)	q++;
		else q--;
		if(q == m+1)	moder++;
		else if(q == 0)	moder--;
		if(moder%2 and q==m+1) 
		{
			p++;
			q--;
		}
		else if(moder%2 == 0 and q == 0)
		{
			p++;
			q++;
		}
		cout<<p<<" "<<q<<endl;
		if(moder%2 == 0)	q++;
		else q--;
		if(q == m+1)	moder++;
		else if(q == 0)	moder--;
		if(moder%2 and q==m+1) 
		{
			p++;
			q--;
		}
		else if(moder%2 == 0 and q == 0)
		{
			p++;
			q++;
		}
	}

	cout<<n*m-2*(k-1)<<" ";
	FOR(i,1,n*m-2*(k-1))
	{
		cout<<p<<" "<<q<<" ";
		if(moder%2 == 0)	q++;
		else q--;
		if(q == m+1)	moder++;
		else if(q == 0)	moder--;
		if(moder%2 and q==m+1) 
		{
			p++;
			q--;
		}
		else if(moder%2 == 0 and q == 0)
		{
			p++;
			q++;
		}
	}
	cout<<endl;
	return 0;

}