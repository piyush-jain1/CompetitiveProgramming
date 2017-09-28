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

int main()
{	
	ll n,m,x,y;	cin>>n>>m>>x>>y;
	y = min(m,y);
	string s[n+10];	
	FOR(i,1,n)	cin>>s[i];
	ll b[m+10];
	FOR(i,1,m)
	{	
		b[i] = 0;
		FOR(j,1,n)	b[i] += (s[j][i-1] == '#');
	}
	// FOR(i,1,m)
	// {
	// 	DEBUG(b[i]);
	// }
	ll black[m+10][m+10];
	ll white[m+10][m+10];
	FOR(j,0,m)
	{
		FOR(i,0,m)
		{
			black[j][i] = white[j][i] = INT_MAX;
		}
	}
	black[1][1] = b[1];
	white[1][1] = n-b[1];
	FOR(j,2,m)
	{	
		// First Black
		FOR(i,x,y)
		{
			if(i > j)	break;
			black[j][1] = min(black[j][1],b[j]+white[j-1][i]);
		}
		FOR(k,2,y)
		{
			if(k > j)	break;
			black[j][k] = min(black[j][k],b[j]+black[j-1][k-1]);
		}
		// First White
		FOR(i,x,y)
		{
			if(i > j)	break;
			white[j][1] = min(white[j][1],n-b[j]+black[j-1][i]);
		}
		FOR(k,2,y)
		{
			if(k > j)	break;
			white[j][k] = min(white[j][k],n-b[j]+white[j-1][k-1]);
		}
		// DEBUG(black[j][y]);
		// DEBUG(white[j][y]);
	}
	
	ll minm = INT_MAX;
	FOR(k,x,y)
	{	

		minm = min(minm,black[m][k]);
		minm = min(minm,white[m][k]);
	}
	cout<<minm<<endl;
	return 0;
	
	
}

