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
	int n;	cin>>n;
	string s;	cin>>s;
	int q;	cin>>q;
	while(q--)
	{	
		DEBUG(q);
		int m;	cin>>m;
		char c; cin>>c;
		int a[n+10];
		int gap[n+10];
		int cnt = 0;
		int k = 0;
		REP(i,n)
		{	
			if(s[i] != c)	cnt++;
			else
			{	
				a[k] = i; 
				gap[k] = cnt;
				k++;
				cnt = 0;
			}
		}
		gap[k] = cnt;
		if(k == 0)	
		{
			cout<<m<<endl;
			return 0;
		}
		// DEBUG(gap[k]);
		// FOR(i,0,k-1)	cout<<a[i]<<" "<<gap[i]<<endl;
		int i = 0;
		int maxm = 0;
		while(i < k and a[i] <= n-m+1-(k-i-1))
		{
			int ans = 0;
			int j = i;
			while(j < k and m > 0)
			{	
				ans += min(m,gap[j+1]) + a[j];
				DEBUG(ans);
				m -= min(m,gap[j+1]);
				j++;
			}
			
			DEBUG(ans);
			maxm = max(maxm, ans);
			i++;
		}
		if(i < k)
		{
			int ans = 0;
			if(a[i] > n-m+1-(k-i-1))
			{
				ans += min(m,a[i]-(n-m+1));
				m -= min(m,a[i]-n-m+1);
			}
			int j = i;
			while(j < k and m > 0)
			{
				ans += a[j] + min(m,gap[j+1]);
				m -= min(m,gap[j+1]);
				j++;
			}
			DEBUG(ans);
			maxm = max(maxm, ans);
		}
		
		cout<<maxm<<endl;

	}
	return 0;
}