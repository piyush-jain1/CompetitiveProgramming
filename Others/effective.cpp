#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
#include <string>
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{	
	int n ;
	cin >> n;
	int q[n+10];
	int index[n+10];
	fill(index, index+n+5,n);
	for(int i=1;i<=n;i++){
		cin >> q[i] ;
		index[q[i]] = i;
	}

	int x ;
	cin >> x ;
	int queue;
	ll first=0 ;
	ll last=0 ;
	for(int i=0;i<x;i++){
		cin >> queue ;
		first += index[queue];
		last += n-index[queue]+1;
	}

	
	cout << first << " " << last <<endl;
	return 0;
}











































