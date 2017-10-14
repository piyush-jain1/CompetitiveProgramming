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
	char s[15][25];
	FOR(i,1,10)
	{
		FOR(j,1,5)	s[i][j] = '*';
		FOR(j,16,20)	s[i][j] = '*';
		FOR(j,6,15)	cin>>s[i][j];
	}
	// FOR(i,1,10)
	// {
	// 	FOR(j,1,20)	cout<<s[i][j];
	// 	cout<<endl;
	// }
	int check = '.'+'X'+'X'+'X'+'X';
	FOR(i,1,10)
	{
		FOR(j,6,11)
		{
			if(s[i][j]+s[i][j+1]+s[i][j+2]+s[i][j+3]+s[i][j+4] == check)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	FOR(j,6,15)
	{
		FOR(i,1,6)
		{
			if(s[i][j]+s[i+1][j]+s[i+2][j]+s[i+3][j]+s[i+4][j] == check)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	FOR(i,1,6)
	{
		FOR(j,6,15)
		{
			if(s[i][j]+s[i+1][j-1]+s[i+2][j-2]+s[i+3][j-3]+s[i+4][j-4] == check)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
		FORD(j,15,6)
		{
			if(s[i][j]+s[i+1][j+1]+s[i+2][j+2]+s[i+3][j+3]+s[i+4][j+4] == check)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;

	
}