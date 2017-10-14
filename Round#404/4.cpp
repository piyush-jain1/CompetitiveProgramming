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


const ll N = 4e5 + 5;
const ll mod = 1e9 + 7;
ll n;
string s;
ll x , y;
ll ans;
ll ifact[N];
ll fact[N];
void pre()
{
    fact[0] = 1;
    for(ll i = 1 ; i < N ; ++i)
    {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = 977041169;
    for(ll i = N - 2 ; i >= 0 ; --i)
    {
        ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
    }
}

ll ncr(ll n , ll r)
{
    if(r >= 0 && r <= n)
    {
        ll res = fact[n];
        res = (1LL * res * ifact[r]) % mod;
        res = (1LL * res * ifact[n - r]) % mod;
        return res;
    }
    else
    {
        return 0;
    }
}

int main()
{	
	std::ios::sync_with_stdio(false);
	pre();
	cin>>s;
	n = s.length();
	x = 0;
	y = 0;
	ans = 0;
	REP(i,n)
	{
		y += (s[i] == ')');
	}
	REP(i,n)
	{
		y -= (s[i] == ')');
		if(s[i] == '(')
		{
			ans += ncr(x+y, y-1);
			if(ans >= mod)
			{
				ans -= mod;
			}
		}
		x += (s[i] == '(');
	}
	cout<<ans<<endl;
	return 0;

		
}