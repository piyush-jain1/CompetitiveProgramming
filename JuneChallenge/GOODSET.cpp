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
map<int,bool> flag;
std::vector<ll> ans;

int main()
{	
	fast_io;
	int t;	cin>>t;
	while(t--)
	{	
		int n;	cin>>n;
		if(n == 1)	cout<<1<<endl;
		else if(n == 2)	cout<<1<<" "<<2<<endl;
		else
		{
			// DEBUG(n);
			ans.pb(1);
			ans.pb(2);
			flag[3] = true;
			ll i = 4;
			n -= 2;
			// DEBUG(ans.size());
			while(n!=0)
			{
				if(!flag[i])
				{
					ans.pb(i);
					n--;
				}
				FOR(i,0,ans.size()-1)
				{
					FOR(j,i+1,ans.size()-1)
					{
						flag[ans[i]+ans[j]] = true;
					}
				}
				i++;
			}
			for(auto i : ans)	cout<<i<<" ";
			cout<<endl;	
		}	
		ans.clear();
	}
	return 0;
}