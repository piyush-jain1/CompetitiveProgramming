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
const int MAX = 100000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll a[MAX+10];


int main()
{
	ll n,d;	cin>>n>>d;
	FOR(i,1,n)	cin>>a[i];
	ll count = 0;
	FOR(i,1,n-2)
	{
		ll res = d+a[i];
		// DEBUG(res);
		ll low = i+2;
		ll high = n;
		while(high-low > 1)
		{
			ll mid = (low+high)/2;
			if(a[mid] <= res)	low = mid;
			else high = mid;
		}
		// DEBUG(high);
		// DEBUG(low);
		if(a[high] <= res)	count += ((high-i)*(high-i-1))/2;
		else if(a[low] <= res)	count += ((low-i)*(low-i-1))/2;
		// DEBUG(count);
	}
	cout<<count<<endl;
	return 0;
}