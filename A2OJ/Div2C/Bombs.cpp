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

bool sortmanhattan(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
	return abs(b.first)+abs(b.second) > abs(a.first)+abs(a.second) ; 
}

int main()
{	
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	ll n;	cin>>n;
	std::vector<pair<ll,ll>> v;
	ll count = 0;
	REP(i,n)
	{	
		ll a,b;	cin>>a>>b;
		v.pb(mp(a,b));
		ll temp = 0;
		if(a != 0)	temp++;
		if(b != 0)	temp++;
		temp *= 2;
		temp += 2;
		count += temp;
	}
	cout<<count<<endl;
	sort(v.begin(), v.end(), sortmanhattan);
	ll i = 0;
	while(i < n)
	{	
		ll h = v[i].first;
		ll t = v[i].second;
		if(h > 0)	printf("1 %lld R\n", h);
		else if(h < 0)	printf("1 %lld L\n", -1*h);
		if(t > 0)	printf("1 %lld U\n", t);
		else if(t < 0)	printf("1 %lld D\n", -1*t);
		printf("2\n");
		if(h > 0)	printf("1 %lld L\n", h);
		else if(h < 0)	printf("1 %lld R\n", -1*h);
		if(t > 0)	printf("1 %lld D\n", t);
		else if(t < 0)	printf("1 %lld U\n", -1*t);
		printf("3\n");
		i++;
	}
	return 0;
}