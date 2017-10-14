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
#define all(v) v.begin(),v.end()
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
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string oleg,igor;	cin>>oleg>>igor;
	ll n = oleg.length();
	sort(all(oleg));
	sort(all(igor),wayToSort);
	ll len = 0;
	ll lastoleg = n/2 - 1;
	ll lastigor = n/2 - 1;
	ll firstoleg = 0;
	ll firstigor = 0;
	if(n%2)	lastoleg = n/2;
	char ans[n+10];
	ll last = n-1;
	ll first = 0;
	while(len < n)
	{
		if(oleg[firstoleg] >= igor[firstigor])
		{	
			// DEBUG(oleg[firstoleg]);
			// DEBUG(igor[firstigor]);
			ans[last--] = oleg[lastoleg--];
		}
		else
		{
			ans[first++] = oleg[firstoleg++];
		}

		len++;
		if(len == n)	break;
		if(oleg[firstoleg] >= igor[firstigor])
		{	
			ans[last--] = igor[lastigor--];
		}
		else
		{
			ans[first++] = igor[firstigor++];
		}

		len++;
	}
	REP(i,n)	cout<<ans[i];
	cout<<endl;
	return 0;
}