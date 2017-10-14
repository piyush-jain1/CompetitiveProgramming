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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll cnt[10000010] = {0};
ll pre[10000010] = {0};	
ll prefix[10000010];
void sieve(ll n)
{	
	bool prime[n+10];
	memset(prime, true, sizeof(prime));
	for(ll p = 2; p <= n; p++)
	{	
		if(prime[p])
		{	
			pre[p] = cnt[p];
			for(ll i = p*2; i<=n; i+=p)
			{
				pre[p] += cnt[i];
				prime[i] = false;
			}
		}
	}
	// for (int p=2; p<=n; p++)
 //       if (prime[p])
 //          cout << p << " ";
}


int main()
{	
	ll n;	cin>>n;
	ll maxm = 0;
	REP(i,n)
	{	
		ll temp;
		scanf("%lld",&temp);
		cnt[temp]++;
		maxm = max(maxm,temp);
	}
	sieve(maxm);
	// DEBUG(maxm);
	ll m;	cin>>m;
	prefix[0] = pre[0];
	FOR(i,1,10000000)
	{
		prefix[i] = prefix[i-1]+pre[i];
	}
	while(m--)
	{
		ll l,r;	cin>>l>>r;
		r = min(r,(ll)10000000);
		if(l <= 10000000)	printf("%lld\n",prefix[r]-prefix[l-1]);
		else cout<<0<<endl;
	}
	return 0;

}