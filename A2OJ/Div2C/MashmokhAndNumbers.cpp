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
bool prime[100000010];
ll cnt = 0;
void sieve(ll n)
{
	memset(prime,true, sizeof(prime));
	for(ll p = 2; p <= 1299827; p++)
	{
		if(prime[p])
		{	
			cnt++;
			if(cnt == n+1)	break;
			for(ll i = p*2; i <= 1299827; i+=p)
			{
				prime[i] = false;
			}
		}
	}
}

int main()
{	
	ll n,k;	cin>>n>>k;
	sieve(n);
	if(n == 1)
	{
		if(k != 0)	cout<<-1<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if(k < n/2)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(k == n/2)
	{
		ll count = 0;
		ll i = 2;
		while(count < n)
		{
			if(prime[i])
			{
				printf("%lld ",i);
				count++;
			}
			i++;
		}
		cout<<endl;
		return 0;
	}
	ll point = k- n/2 + 1;
	prime[point] = false;
	printf("%lld ",point);
	printf("%lld ",2*point);
	ll count = 2;
	ll i = 2;
	while(count < n)
	{
		if(prime[i])
		{
			printf("%lld ",i);
			count++;
		}
		i++;
	}
	cout<<endl;
	return 0;

}