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
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{   return (a.second < b.second);		}	
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll a[1010][1010];

ll modulo(ll i, ll k)
{
	return (i%k == 0) ? i : i%k;
}
int main()
{
	ll n,k,d;	cin>>n>>k>>d;
	if(n > pow(k,d))
	{
		cout<<-1<<endl;
		return 0;
	}
	ll i = d;

	while(i >= 1)
	{	
		ll j = 1;
		ll freq = pow(k,d-i);
		// DEBUG(freq);
		ll curr = 1;
		while(j <= n)
		{
			a[i][j] = curr;
			// DEBUG(a[i][j]);
			if(j%freq == 0)
			{
				curr = modulo(curr+1,k);
			}
			j++;
		}
		i--;
	}
	FOR(i,1,d)
	{
		FOR(j,1,n)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
	return 0;

}