#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
using namespace std;
///////////////////////////////////////////////////////
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

ll a[1010];
int main()
{	
	fast_io;
	ll n,k;	cin>>n>>k;
	REP(i,n)	cin>>a[i];
	sort(a,a+n);
	ll i = 0;
	ll range = 2*k;
	int ans = 0;
	ll maxm = k;
	while(i < n)
	{	
		// trace3(a[i],maxm, range);
		if(a[i] <= range)
		{
			maxm = max(maxm,a[i]);
			range = 2*maxm;
		}
		else
		{	
			while(a[i] > range)
			{
				maxm = range;
				range = 2*maxm;
				ans++;
				// trace2(maxm,range);
			}
			maxm = max(maxm,a[i]);
			range = 2*maxm;
		}
		i++;
	}	
	cout<<ans<<endl;
	return 0;
}