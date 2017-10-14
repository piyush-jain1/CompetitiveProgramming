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
	int n,a,b;	cin>>n>>a>>b;
	int x[n+10],y[n+10];
	REP(i,n)
	{
		cin>>x[i]>>y[i];
	}
	int area = 0;
	REP(i,n)
	{
		FOR(j,i+1,n-1)
		{	
			// trace4(x[i],y[i],x[j],y[j]);
			if((x[i]+x[j] <= a and y[i] <= b and y[j] <= b) or (x[i]+x[j] <= b and y[i] <= a and y[j] <= a) or (x[i]+y[j] <= a and y[i] <= b and x[j] <= b) or (x[i]+y[j] <= b and y[i] <= a and x[j] <= a) or (y[i]+y[j] <= a and x[i] <= b and x[j] <= b) or (y[i]+y[j] <= b and x[i] <= a and x[j] <= a) or (y[i]+x[j] <= a and x[i] <= b and y[j] <= b) or (y[i]+x[j] <= b and x[i] <= a and y[j] <= a))
			{
				area = max(area,(x[i]*y[i]+x[j]*y[j]));
			}
		}
	}
	cout<<area<<endl;
	return 0;
	
}