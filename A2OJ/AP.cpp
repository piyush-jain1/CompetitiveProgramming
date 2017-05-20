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


ll a[100010];
int main()
{
	ll n;	cin>>n;
	REP(i,n)	cin>>a[i];
	if(n == 1)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(a, a+n);
	bool equal = true;
	FOR(i,0,n-2)
	{
		if(a[i] != a[i+1])	
		{
			equal = false;
			break;
		}
	}
	if(equal)
	{
		cout<<1<<endl<<a[0]<<endl;
		return 0;
	}
	if(n == 2)
	{
		if((a[1]-a[0])%2 == 0)
		{
			cout<<3<<endl<<2*a[0]-a[1]<<" "<<a[0]+(a[1]-a[0])/2<<" "<<2*a[1]-a[0]<<endl;
		}
		else
		{
			cout<<2<<endl<<2*a[0]-a[1]<<" "<<2*a[1]-a[0]<<endl;
		}
		return 0;
	}
	set<ll> diff;
	FOR(i,1,n-1)	diff.insert(a[i]-a[i-1]);
	if(diff.size() == 1)
	{
		cout<<2<<endl<<a[0]-(a[1]-a[0])<<" "<<a[n-1]+(a[1]-a[0])<<endl;
		return 0;
	}
	else if(diff.size() == 2)
	{	
		ll d[3];
		ll i = 0;
		for(auto u:diff)	d[i++] = u;
		if(d[1] != 2*d[0])
		{	
			cout<<0<<endl;
			return 0;
		}
		else
		{
			std::vector<ll> v;
			ll count = 0;
			FOR(i,1,n-1)
			{					
				if(a[i]-a[i-1] == d[1])
				{	
					if(count < 1)
					{
						v.pb(a[i-1]+d[0]);
						count++;
					}	
					else	
					{
						cout<<0<<endl;
						return 0;
					}	
				}	
			}
			cout<<1<<endl<<v[0]<<endl;
			return 0;
		}	
		
	}
	cout<<0<<endl;
	return 0;
}