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
const int MAX = 1000000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ll xore[MAX+10];
ll p[MAX+10];
ll n;

void prexor()
{
	xore[1] = 1;
	FOR(i,1,n)	xore[i] = xore[i-1]^i;
}

int main()
{	
	cin>>n;
	prexor();
	FOR(i,1,n)	cin>>p[i];
	ll factor = p[1];
	FOR(i,2,n)
	{	
		// DEBUG(i);
		if(((n/i)%2) == 1)	factor ^= xore[i-1];
		ll res = n-(n/i)*i;
		factor ^= xore[res];
		factor ^= p[i];
		// DEBUG(factor);
	}
	cout<<factor<<endl;
	return 0;

}