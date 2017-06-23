#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{	
	fast_io;
	string time;	cin>>time;
	int h1 = (time[0]-'0');
	int h2 = (time[1]-'0');
	int m1 = (time[3]-'0'); 
	int m2 = (time[4]-'0');
	int count = 0;
	while(m2 != h1 or m1 != h2)
	{	
		if(h1 == 2 and h2 == 3 and m1 == 5 and m2 == 9)
		{
			h1 = 0;
			h2 = 0;
			m1 = 0;
			m2 = 0;
		}
		else if(m1 == 5 and m2 == 9)
		{
			if(h2 == 9)
			{
				h2 = 0;
				h1++;
			}
			else
			{
				h2++;
			}
			m1 = 0;
			m2 = 0;
		}
		else if(m2 == 9)
		{
			m2 = 0;
			m1++;
		}
		else
		{
			m2++;
		}
		// cout<<h1<<h2<<":"<<m1<<m2<<endl;
		count++;
	}
	cout<<count<<endl;
	return 0;

	
}