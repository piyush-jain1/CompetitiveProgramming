#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
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

int a[110];
int sum[10000000] = {0};
int main()
{	
	fast_io;
	int t;	cin>>t;
	FOR(test,1,t)
	{
		int n;	cin>>n;
		FOR(i,1,n)
		{
			cin>>a[i];
		}
		bool modi = false;
		FOR(i,1,n)
		{
			FOR(j,i+1,n)
			{	
				if(sum[a[i]+a[j]] == test)
				{   
				    // trace2(a[i],a[j]);
					modi = true;
					break;
				}
				else	sum[a[i]+a[j]] = test;		
			}
			if(modi)    break;
		}
		if(modi)	cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
	
}