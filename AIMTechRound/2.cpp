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

int main()
{	
	fast_io;
	int n,m;	cin>>n>>m;
	int a[n+10][m+10];
	ll countr[n+10];
	ll countc[m+10];
	fill(countr, countr+n+5, 0);
	fill(countc, countc+m+5, 0);
	REP(i,n)
	{
		REP(j,m)
		{
			cin>>a[i][j];
			countr[i] += a[i][j];
		}
	}
	REP(i,m)
	{
		REP(j,n)
		{
			countc[i] += a[j][i];
		}
	}
	ll ans = 0;
	REP(i,n)
	{	
		ll p = countr[i];
		ans += (ll)pow(2,p)-1LL;
		p = m-countr[i];
		ans += (ll)pow(2,p)-1LL;
	}
	REP(i,m)
	{
		ll p = countc[i];
		ans += (ll)pow(2,p)-1LL-p;
		p = n-countc[i];
		ans += (ll)pow(2,p)-1LL-p;
	}
	cout<<ans<<endl;
	return 0;
}