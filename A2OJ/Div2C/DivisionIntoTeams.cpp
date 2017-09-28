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
#define MAX 100000
/////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<pair<ll,ll>> v;

int main()
{
	ll n;	cin>>n;
	FOR(i,1,n)	
	{
		ll str;	cin>>str;
		v.pb(mp(str,i));
	}
	sort(v.begin(),v.end());
	cout<<n-n/2<<endl;
	for(ll i=0;i<n;i+=2)
	{
		cout<<v[i].second<<" ";
	}
	cout<<endl;
	cout<<n/2<<endl;
	for(ll i=1;i<n;i+=2)
	{
		cout<<v[i].second<<" ";
	}
	cout<<endl;
	return 0;

}