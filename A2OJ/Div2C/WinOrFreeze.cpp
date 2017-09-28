#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
	ll q;
	cin>>q;
	if(q == 1)
	{
		cout<<1<<endl<<0<<endl;
		return 0;
	}
	std::vector<ll> factor;
	while(q%2 == 0)
	{
		factor.pb(2);
		q /= 2;
	}
	for(ll i = 3; i <= sqrt(q); i+=2)
	{
		while(q%i == 0)
		{
			factor.pb(i);
			q /= i;
		}
	}
	if(q > 2)	factor.pb(q);
	// for(auto u : factor)	cout<<u<<" ";
	// cout<<endl;
	if(factor.size() == 1)
	{
		cout<<1<<endl<<0<<endl;
		return 0;
	}
	if(factor.size() == 2)
	{
		cout<<2<<endl;
		return 0;
	}
	cout<<1<<endl<<factor[0]*factor[1]<<endl;
	return 0;	

}