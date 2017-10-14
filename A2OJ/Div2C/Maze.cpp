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


char a[510][510];
bool visited[510][510] = {false};
ll tot = 0;
ll s,k;
void dfs(ll x, ll y)
{
	visited[x][y] = true;
	tot++;
	if(tot > s-k)	a[x][y] = 'X';
	if(!visited[x+1][y] and a[x+1][y] == '.')
	{
		dfs(x+1,y);
	}
	if(!visited[x-1][y] and a[x-1][y] == '.')
	{
		dfs(x-1,y);
	}
	if(!visited[x][y+1] and a[x][y+1] == '.')
	{
		dfs(x,y+1);
	}
	if(!visited[x][y-1] and a[x][y-1] == '.')
	{
		dfs(x,y-1);
	}

}
int main()
{
	ll n,m;	cin>>n>>m>>k;
	FOR(j,0,m+1)	
	{
		a[0][j] = '#';
		a[n+1][j] = '#';
	}
	FOR(i,0,n+1)
	{
		a[i][0] = '#';
		a[i][m+1] = '#';
	}	
	s = 0;
	ll x,y;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			cin>>a[i][j];
			if(a[i][j] == '.')
			{
				x = i;
				y = j;
				s++;
			}
		}
	}
	dfs(x,y);
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}