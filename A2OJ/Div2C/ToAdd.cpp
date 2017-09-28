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
const int MAX = 200000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	ll n,k;	cin>>n>>k;
	ll a[n+10];
	FOR(i,1,n)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	// FOR(i,1,n)	cout<<a[i]<<" ";
	// cout<<endl;

	ll pre[n+10];
	pre[0] = 0;
	FOR(i,1,n)
	{
		pre[i] = pre[i-1]+a[i];
	}
	ll freq = 0;
	ll ans;
	FOR(i,1,n)
	{	
		ll cnt = 1;
		ll low = 1;
		ll high = i;
		// cout<<i<<"-------"<<a[i]<<endl;
		while(high-low>1)
		{
			ll mid = (low+high)>>1;
			if((pre[i]-pre[mid-1]+k) >= a[i]*(i-mid+1))	high = mid;
			else low = mid;
		}
		if((pre[i]-pre[low-1]+k) >= a[i]*(i-low+1))	cnt = i-low+1;
		else if((pre[i]-pre[high-1]+k) >= a[i]*(i-high+1))	cnt = i-high+1;
		
		if(cnt > freq)
		{
			freq = cnt;
			ans = a[i];
		}
	}
	cout<<freq<<" "<<ans<<endl;
	return 0;
}