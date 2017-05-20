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

ll v[100010], lft[100010], ryt[100010];
std::map<ll, bool> M;
bool rot[100010] = {false};
void check(ll root, ll l, ll r)
{

	// DEBUG(root);
	ll lp_right_index,lp_left_index,rp_left_index,rp_right_index;
	bool rp = false, lp = false;
	if(l>r || root == -1)	return;
	if(l<=v[root] && r>=v[root])
	{	
		M[v[root]] = true;
		lp_left_index = l;
		lp_right_index = v[root]-1;
		rp_left_index = v[root]+1;
		rp_right_index = r;
		rp = true;
		lp = true;
	}
	else if(l > v[root])
	{
		rp = true;
		rp_left_index = l;
		rp_right_index = r;
	}
	else
	{
		lp = true;
		lp_left_index = l;
		lp_right_index = r;
	}
	if(lp)	check(lft[root],lp_left_index,lp_right_index);
	if(rp)	check(ryt[root],rp_left_index,rp_right_index);
	// return;
}
int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	ll root;
	FOR(i,1,n)
	{
		cin>>v[i]>>lft[i]>>ryt[i];
		if(lft[i] != -1)	rot[lft[i]] = true;
		if(ryt[i] != -1)	rot[ryt[i]] = true;
	}	
	FOR(i,1,n)
	{
		if(!rot[i])
		{
			root = i;
			break;
		}
	}
	// DEBUG(root);
	ll l = 0;
	ll r = 1e9;
	check(root,l,r);
	ll count = 0;
	FOR(i,1,n)
	{
		count += !M[v[i]];
	}
	cout<<count<<endl;
	return 0;
}