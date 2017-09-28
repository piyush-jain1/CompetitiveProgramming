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

int w[110][110];
ll righta[110][110][110] = {0};
ll lefta[110][110][110] = {0};
int main()
{	
	fast_io;
	int t;	cin>>t;
	
	while(t--)
	{
		int m,n;	cin>>m>>n;
		REP(i,m)
		{
			REP(j,n)
			{
				cin>>w[i][j];
			}
		}
		REP(i,m)
		{
			REP(j,n)
			{	
				int a = 1;
				righta[i][j][0] = w[i][j];
				while(i-a >= 0 and  j+a< n)
				{
					righta[i][j][a] = righta[i][j][a-1]+w[i-a][j+a];
					// trace4(i,j,a,righta[i][j][a]);
					a++;
				}
				a = 1;
				lefta[i][j][0] = w[i][j];
				while(i-a >= 0 and  j-a >= 0)
				{
					lefta[i][j][a] = lefta[i][j][a-1]+w[i-a][j-a];
					// trace4(i,j,a,lefta[i][j][a]);
					a++;
				}
			}
		}
		

		ll ans = INT_MIN;
		ll point = 0;
		REP(i,m)
		{
			REP(j,n)
			{
				int a = 1;
				while(i-a >= 0 and j >= 0 and j+a < n)
				{	
					// trace3(i,j,a);
					point = righta[i][j][a]+lefta[i][j+a][a];
					if(a%2 == 0) point -= w[i-a/2][j+a/2];
					// trace2(righta[i][j][a],lefta[i][j+a][a]);
					// trace(point);
					ans = max(ans,point);
					a++;
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}