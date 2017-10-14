#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define int_64 uint64_t
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
#define mod 1000000007
int a[100010], b[100010], c[100010];
int p,q,r;
int prea[100010], prec[100010];
 
int main()
{	
	fast_io;
	int t;	cin>>t;
	while(t--)
	{
		cin>>p>>q>>r;
		prea[0] = prec[0] = 0;
		a[0] = 0;
		c[0] = 0;
		FOR(i,1,p)	cin>>a[i];
		sort(a, a+p+1);
		FOR(i,1,p)	prea[i] = (0LL + prea[i-1] + a[i])%mod;;
		FOR(i,1,q)	cin>>b[i];
		FOR(i,1,r)	cin>>c[i];
		sort(c, c+r+1);
		FOR(i,1,r)	prec[i] = (0LL + prec[i-1] + c[i])%mod;
		ll ans = 0;
		FOR(i,1,q)
		{	
			ll y = 0;
			ll k1 = 0;
			if(a[1] > b[i])
			{
				k1 = 0;
				y = 0;
			}
			else
			{
				ll low = 1;
				ll high = p;
				while(high - low > 1)
				{	
					ll mid = (low+high)/2;
					if(a[mid] > b[i])	high = mid;
					else low = mid;
				}
				if(a[high] <= b[i])	
				{
					y = prea[high];
					k1 = high;
				}
				else 
				{
					y = prea[low];
					k1 = low;
				}
			}
			
			ll x = 0;
			ll k3 = 0;
			if(c[1] > b[i])
			{
				k3 = 0;
				x = 0;
			}
			else
			{
				ll low = 1;
				ll high = r;
				while(high - low > 1)
				{	
					ll mid = (low+high)/2;
					if(c[mid] > b[i])	high = mid;
					else low = mid;
				}
				if(c[high] <= b[i])	
				{
					x = prec[high];
					k3 = high;
				}
				else 
				{
					x = prec[low];
					k3 = low;
				}
			}
			
			if(k1 != 0 and k3!= 0)	ans = (ans+ (1LL * ((1LL * k1*x)%mod)*b[i])%mod + (1LL*((1LL*k1*k3)%mod)*((1LL*b[i]*b[i])%mod))%mod + (1LL*x*y)%mod + (1LL*((1LL*k3*y)%mod)*b[i])%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
} 