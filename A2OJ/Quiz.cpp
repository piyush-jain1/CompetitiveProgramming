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
//  First number in array a which is greater than x
// ll * p = std::upper_bound( a, a+n, x );
// ll j = p - a;    // index

#define mod 1000000009
const int MAX = 1e9 + 5;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll n,m,k;

ll power2(ll i)
{	
	ll ans = 1;
	ll x = 2;
	while(i>0)
	{
		if(i%2)	ans = (ans*x)%mod;
		i /= 2;
		x = (x*x)%mod;
	}
	return ans%mod;
}

ll cost(ll x)
{
	ll c = 0;
	// DEBUG(power2(x));
	c = (2*(power2(x)-1+mod))%mod;
	c = (c*k)%mod;
	// DEBUG(c);
	m -= (x*k);
	c = (c + m)%mod;
	return c;
}

int main()
{
	cin>>n>>m>>k;
	ll t = n%k;
	n -= t;
	m -= t;
	ll x = m - (n - n/k);
	ll ans = 0;
	// DEBUG(x);
	if(x > 0)
	{
		ans += cost(x);
	}
	else
	{
		ans = (ans+m)%mod;
	}
	// DEBUG(ans);
	// DEBUG(t);
	cout<<(ans+t)%mod<<endl;
	return 0;
}
