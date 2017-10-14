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
#define ll long long
#define int_64 uint64_t
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
// sorting vector of pairs
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{    return (a.first > b.first);	}
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define mod 1000000007
const int MAX = 1000005;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll fact[MAX];
ll ifact[MAX];

void pre()
{
	fact[0] = 1;
	FOR(i,1,MAX)	fact[i] = (1LL * fact[i-1] * i)%mod;
	ifact[MAX] = 81818608;
	FORD(i,MAX-1,0)	ifact[i] = (1LL * ifact[i+1] * (i + 1LL))%mod;
}

ll nCr(ll n, ll r)
{
	if(r >= 0 and r <= n)
	{
		ll res = fact[n];
		res = (1LL * res * ifact[r])%mod;
		res = (1LL * res * ifact[n-r])%mod;
		return res;
	}
	else return 0;
}
int main()
{	
	pre();
	ll a,b,n;	cin>>a>>b>>n;
	ll ans = 0;
	FOR(i,0,n)
	{
		ll num = a*i + b*(n-i);
		bool ok = true;
		while(num != 0)
		{
			ll dig = num%10;
			num /= 10;
			if(dig != a and dig != b)
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{	
			// DEBUG(nCr(n,i));
			ans = (ans+ nCr(n,i))%mod;
		}
	}
	cout<<ans<<endl;
	return 0;



}