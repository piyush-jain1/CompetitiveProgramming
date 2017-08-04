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

ll a[100010];

int main()
{	
	fast_io;
	int t;	cin>>t;
	while(t--)
	{
		int n;	cin>>n;
		ll ans = 0;
		FOR(i,1,n)	cin>>a[i];
		sort(a+1, a+n+1, wayToSort);
		ll pos = 0;
		ll sumpos = 0;
		FOR(i,1,n)
		{
			if(a[i] < 0)	break;
			sumpos += a[i];
			pos = i;
		}
		ll backsum = 0;
		ll back = 0;
		ll prev = sumpos*pos;
		// DEBUG(prev);
		FOR(i,pos+1,n)
		{
			backsum += a[i];
			back++;
			// DEBUG((sumpos+backsum)*(pos+back));
			// DEBUG(prev+a[i]);
			if((sumpos+backsum)*(pos+back) < prev+a[i])	break;
			else prev = (sumpos+backsum)*(pos+back);
		}
		ans  = prev;
		// DEBUG(ans);
		// DEBUG(back);
		// DEBUG(pos);
		FOR(i,pos+back,n)
		{
			if(a[i] < 0)	ans += a[i];
		}
		cout<<ans<<endl;
	}
	
}