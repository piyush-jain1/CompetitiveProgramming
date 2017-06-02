#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false);	cint.tie(NULL); cout.tie(NULL);
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
int p[10010];
int les[10010];
ll n,m;	
int main()
{	
	// cout << std::setprecision(2)<<fixed;
	// fast_io
	cin>>n>>m;
	FOR(i,1,n)	cin>>p[i];
	while(m--)
	{
		ll l,r,x;	cin>>l>>r>>x;
		ll a = x-1;
		ll b = x+1;
		les[x] = 0;
		while(a > 0 or b <= n)
		{
			if(a > 0)
			{
				if(p[a] < p[x])
				{
					les[a] = les[a+1]+1;
				}
				else	les[a] = les[a+1];
				a--;
			}
			if(b <= n)
			{
				if(p[b] < p[x])
				{
					les[b] = les[b-1]+1;
				}
				else	les[b] = les[b-1];
				b++;
			}
		}
		if(les[r]==x-l-les[l])	cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
	
}