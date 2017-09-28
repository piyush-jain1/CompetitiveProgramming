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

#define MOD 1000000007
ll s[100010];
ll dp[100010];
void pre(ll k)
{
	FOR(i,0,k-1)	dp[i] = 1;
	FOR(i,k,100000)
	{
		dp[i] = (dp[i-1] + dp[i-k])%MOD;
	}
	return;
}

int main()
{	
	fast_io;
	ll t,k;	cin>>t>>k;
	pre(k);
	s[0] = dp[0];
	FOR(i,1,100000)
	{
		s[i] = (s[i-1] + dp[i])%MOD;
	}
	while(t--)
	{
		ll a,b;	cin>>a>>b;
		cout<<(s[b]-s[a-1]+MOD)%MOD<<endl;
	}
	return 0;

}