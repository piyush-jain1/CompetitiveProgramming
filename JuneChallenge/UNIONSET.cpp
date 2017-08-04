#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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

int check[2510] = {0};
int len[2510];
int theset[2510][2510];
int counter = 0;
int main()
{
	int test;	cin>>test;
	FOR(t,1,test)
	{
		int n,k;	cin>>n>>k;
		FOR(i,1,n)
		{
			cin>>len[i];
			FOR(j,1,len[i])	cin>>theset[i][j];
		}
		
		ll ans = 0;
		FOR(i,1,n)
		{
			FOR(j,i+1,n)	
			{
				if(len[i]+len[j] >= k)
				{	
					counter++;
					FOR(p,1,len[i])	check[theset[i][p]] = counter;
					FOR(p,1,len[j])	check[theset[j][p]] = counter;
					bool ok = true;
					FOR(p,1,k)	
					{
						if(check[p] != counter)
						{
							ok = false;
							break;
						}
					}
					if(ok)	ans++;
				}
			}

		}
		cout<<ans<<endl;
	}
}