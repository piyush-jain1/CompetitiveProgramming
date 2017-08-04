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

int counts[30] = {0}, countt[30] = {0};
int main()
{	
	fast_io;
	string s,t;	cin>>s>>t;
	int ls = s.length();
	int lt = t.length();
	REP(i,ls)
	{
		if(s[i] != '?')	counts[s[i]-96]++;
	}
	REP(i,lt)
	{
		countt[t[i]-96]++;
	}

	FOR(i,1,26)
	{
		if(countt[i]>counts[i])
		{
			int c = countt[i]-counts[i];
			int j = 0;
			while(c>0 and j < ls)
			{
				if(s[j] == '?')
				{
					s[j] = i+96;
					c--;
				}
				j++;	
			}
			if(c > 0)
			{
				cout<<s<<endl;
				return 0;
			}
			counts[i] = countt[i];
		}
	}
	// trace(s);

	FOR(i,1,26)	counts[i] -= countt[i];
	int pointer = 0;
	while(pointer < ls)
	{
		REP(i,lt)
		{
			if(counts[t[i]-96] > 0)
			{
				counts[t[i]-96] -= 1;
			}
			else
			{	
				while(pointer < ls and s[pointer] != '?')
				{
					pointer++;
				}
				if(pointer < ls)
				{
					s[pointer] = t[i];
					pointer++;
				}
				else
				{
					cout<<s<<endl;
					return 0;
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;

}