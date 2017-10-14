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
#define MAX 100010


struct node 
{
	ll val;
	node* left, *right;
	node() {}
	node(node* l, node* r, ll v)
	{
		left = l;
		right = r;
		val = v;
	}
};

ll a[MAX],b[MAX],f[MAX]={0};
node* version[MAX];

void build(node* n, ll low, ll high)
{
	if(low == high)
	{
		n->val = f[low];
		return 0;
	}
	ll mid = (low+high)/2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid+1, high);
	n->val = n->left->val + n->right->val;
}

void upgrade(node* prev, node* cur, ll low, ll high, ll idx, ll value)
{
	if(idx > high or idx < low or low > high)	return;
	if(low == high)
	{
		cur->val = value;
		return;
	}
	ll mid = (low+high)/2;
	if(idx <= mid)
	{
		cur->right = prev->right;
		cur->left = new node(NULL,NULL,0);
		upgrade(prev->left,cur->left,low,mid,idx,value);
	}
	else
	{
		cur->left = prev->left;
		cur->right = new node(NULL, NULL, 0);
		upgrade(prev->right,cur->right,mid+1,high,idx, value);
	}
	cur->val = cur->left->val + cur->right->val;
}
ll query(node* n, ll low, ll high, ll l, ll r)
{
	if(l > high or r < low or low > high)	return 0;
	if(l <= low)
}


int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;	cin>>n>>m;
	REP(i,n)	cin>>a[i];
	sort(a,a+n);
	fill(f, f+n+5, 0);
	ll j = -1;
	FOR(i,1,n-1)
	{
		if(a[i] == a[i-1])
		{
			f[j]++;
		}	
		else
		{	
			j++;
			b[j] = a[i];
		}
	}

}
