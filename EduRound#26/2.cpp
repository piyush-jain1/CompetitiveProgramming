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
	int m,n;	cin>>n>>m;
	char a[n+10][m+10];
	bool same = true;
	REP(i,n)
	{
		REP(j,m)
		{
			cin>>a[i][j];
			if(j > 0 and a[i][j] != a[i][j-1])
			{
				same = false;
				// trace2(a[i][j-1],a[i][j]);
			}	
		}
	}

	
	int h1=0,h2=0,h3=0;
	bool r = false,g = false,b = false;
	bool modi = true;
	// trace(same);
	if(same)
	{
		if(1)
		{	
			char match = a[0][0];
			if(a[0][0] == 'R')	r = true;
			else if(a[0][0] == 'G')	g = true;
			else if(a[0][0] == 'B')	b = true;
			int i = 0;
			while(i < n and a[i][0] == match)
			{	
				h1++;
				i++;
			}
			if(i < n)	
			{	
				if(a[i][0] == 'R')	r = true;
				else if(a[i][0] == 'G')	g = true;
				else if(a[i][0] == 'B')	b = true;
				match = a[i][0];
				while(i < n and a[i][0] == match)
				{
					h2++;
					i++;
				}
			}
			if(i < n)	
			{	
				if(a[i][0] == 'R')	r = true;
				else if(a[i][0] == 'G')	g = true;
				else if(a[i][0] == 'B')	b = true;
				match = a[i][0];
				while(i < n and a[i][0] == match)
				{
					h3++;
					i++;
				}
			}
		}
		// trace3(h1,h2,h3);
		if(r and g and b and h1==h2 and h2==h3)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	bool same2 = true;
	REP(j,m)
	{
		REP(i,n)
		{
			if(i > 0 and a[i][j] != a[i-1][j])
			{
				same2 = false;
				break;
			}
		}
		if(!same2)	break;
	}
	if(same2)
	{	
		modi = true;
		REP(j,m)
		{	
			FOR(i,1,n-1)
			{
				if(a[i][j] != a[i-1][j])
				{
					modi = false;
					break;
				}
			}
		}
		int ha=0,hb=0,hc=0;
		bool ra=false,ga=false,ba=false;
		if(modi)
		{	
			char match = a[0][0];
			if(a[0][0] == 'R')	ra = true;
			else if(a[0][0] == 'G')	ga = true;
			else if(a[0][0] == 'B')	ba = true;
			int j = 0;
			while(j < m and a[0][j] == match)
			{	
				ha++;
				j++;
			}
			if(j < m)	
			{	
				if(a[0][j] == 'R')	ra = true;
				else if(a[0][j] == 'G')	ga = true;
				else if(a[0][j] == 'B')	ba = true;
				match = a[0][j];
				while(j < m and a[0][j] == match)
				{
					hb++;
					j++;
				}
			}
			if(j < m)	
			{	
				if(a[0][j] == 'R')	ra = true;
				else if(a[0][j] == 'G')	ga = true;
				else if(a[0][j] == 'B')	ba = true;
				match = a[0][j];
				while(j < m  and a[0][j] == match)
				{
					hc++;
					j++;
				}
			}
		}
		// trace3(ha,hb,hc);
		if(ra and ga and ba and ha==hb and hb==hc)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;

	
}