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

ll gcd(ll a, ll b)
{
	while(b!=0)
	{	
		ll temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	ll n;	cin>>n;
	if(n < 3)	cout<<n<<endl;
	else
	{
		if(n%2)	cout<<(n)*(n-1)*(n-2)<<endl;
		else
		{	
			ll maxm = (n-1)*(n-2)*(n-3);
			FOR(i,max(1LL,n-50),n)
			{
				FOR(j,max(1LL,n-50),n)
				{
					FOR(k,max(1LL,n-50),n)
					{	
						// DEBUG(i);
						// DEBUG(j);
						// DEBUG(k);
						// DEBUG(lcm(k,lcm(i,j)));
						maxm = max(maxm, lcm(k,lcm(i,j)));
					}
				}
			}	
			cout<<maxm<<endl;
		}

		
	}
	
	return 0;
}