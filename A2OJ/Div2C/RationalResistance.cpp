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

int main()
{
	ll a,b;	cin>>a>>b;
	ll k = 0;
	while(a > 0 and b > 0)
	{	
		if(a == b)
		{
			cout<<a/b+k<<endl;
			return 0;
		}
		if(a > b)
		{
			k += (a/b);
			a -= (a/b)*b;
		}
		else
		{
			 k += (b/a);
			 b -= (b/a)*a;
		}

		// DEBUG(a);
		// DEBUG(b);
		// DEBUG(k);
	}
	cout<<k<<endl;
	return 0;
}