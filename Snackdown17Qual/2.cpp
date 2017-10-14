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
/////////////////////////////////////////////////////////////////////////////////////////////////////////


ll a[110];
int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll s;	cin>>s;
	while(s--)
	{	
		ll n;	cin>>n;
		FOR(i,1,n)	cin>>a[i];
		bool valid = true;
		if(n%2 == 0 or a[1] != 1)	valid = false;	
		else
		{
			ll center = (n+1)/2;
			FOR(i,1,center-1)
			{
				if(a[i+1] != a[i]+1)
				{
					valid = false;
					break;
				}	
			}
			FOR(i,center,n-1)
			{
				if(a[i+1] != a[i]-1)
				{
					valid = false;
					break;
				}
			}
		}	
		if(valid)	cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;

	
}