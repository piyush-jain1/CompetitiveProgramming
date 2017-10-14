#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll modulo(ll i)
{	
	if(i == 0)	return 4;
	if(i == 4)	return 4;
	else return i%4;
}
int main()
{	
	fast_io;
	ll l[6],r[6],s[6],p[6];
	FOR(i,1,4)
	{
		cin>>l[i]>>s[i]>>r[i]>>p[i];
	}
	bool ok = true;
	FOR(i,1,4)
	{
		if(l[i] == 1)
		{
			if(p[modulo(i-1)] == 1 or p[i] == 1)
			{
				ok = false;
				break;
			}
		}
		if(r[i] == 1)
		{
			if(p[modulo(i+1)] == 1 or p[i] == 1)
			{
				ok = false;
				break;
			}
		}
		if(s[i] == 1)
		{
			if(p[modulo(i)] == 1 or p[modulo(i+2)] == 1)
			{
				ok = false;
				break;
			}
		}
	}
	if(ok)	cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
	
}