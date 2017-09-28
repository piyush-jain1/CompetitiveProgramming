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
ll p[2010][2010];
ll a[2010][2010];
ll b[2010][2010];

int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	FOR(i,1,n)
	{
		FOR(j,1,n)	
		{
			a[i][j] = 0;
			b[i][j] = 0;
			cin>>p[i][j];
		}
	}
	FOR(i,1,n)
	{
		FOR(j,1,n)	
		{
			if(i+j < n+1)	a[1][i+j-1] += p[i][j];
			else	a[i+j-n][n] += p[i][j];
			if(i >= j)	b[n][n-i+j] += p[i][j];
			else	b[n-j+i][n] += p[i][j];
		}
	}
	ll x1,x2,y1,y2;
	ll maxm1 = INT_MIN;
	ll maxm2 = INT_MIN;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{	
			if(i+j < n+1)
			{
				if(i >= j)	p[i][j] = a[1][i+j-1] + b[n][n-i+j] - p[i][j];
				else	p[i][j] = a[1][i+j-1] + b[n-j+i][n] - p[i][j];
			}
			else
			{
				if(i >= j)	p[i][j] = a[i+j-n][n] + b[n][n-i+j] - p[i][j];
				else	p[i][j] = a[i+j-n][n] + b[n-j+i][n] - p[i][j];
			}
			if( ((i%2 == 1 and j%2 == 1) or (i%2 == 0 and j%2 == 0)) and p[i][j] > maxm1)
			{
				maxm1 = p[i][j];
				x1 = i;
				y1 = j;
			}
			else if(((i%2 == 1 and j%2 == 0) or (i%2 == 0 and j%2 == 1)) and p[i][j] > maxm2)
			{
				maxm2 = p[i][j];
				x2 = i;
				y2 = j;
			}
			// cout<<p[i][j]<<" ";
		}
		// cout<<endl;
	}
	cout<<maxm1+maxm2<<endl;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	return 0;

}