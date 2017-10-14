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
	char s,e;	cin>>s>>e;
	int n;	cin>>n;

	if(n%4 == 1)
	{	
		if((s == 118 and e == 60) or (s == 60 and e == 94) or (s == 94 and e == 62) or (s == 62 and e == 118))
		{
			cout<<"cw"<<endl;
			return 0;
		}
		else if((s == 118 and e == 62) or (s == 62 and e == 94) or (s == 94 and e == 60) or (s == 60 and e == 118))
		{
			cout<<"ccw"<<endl;
			return 0;
		}
	}
	if(n%4 == 3)
	{
		if((s == 118 and e == 62) or (s == 60 and e == 118) or (s == 94 and e == 60) or (s == 62 and e == 94))
		{
			cout<<"cw"<<endl;
			return 0;
		}
		if((s == 118 and e == 60) or (s == 60 and e == 94) or (s == 94 and e == 62) or (s == 62 and e == 118))
		{
			cout<<"ccw"<<endl;
			return 0;
		}
	}
	cout<<"undefined"<<endl;
	return 0;
	
}