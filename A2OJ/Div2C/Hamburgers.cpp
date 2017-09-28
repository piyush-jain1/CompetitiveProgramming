#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
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
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	string sit;	cin>>sit;
	ll breq=0,sreq=0,creq=0;
	ll len = sit.length();
	REP(i,len)
	{
		if(sit[i] == 'B')	breq++;
		else if(sit[i] == 'S')	sreq++;
		else creq++;
	}
	ll b,s,c;
	cin>>b>>s>>c;
	
	ll mb,ms,mc;
	cin>>mb>>ms>>mc;
	ll r;	cin>>r;
	ll low = 0;
	ll high = 1e15;
	while(high-low > 1)
	{
		ll mid = (low+high)/2;
		if(((max((ll)0,breq*mid-b))*mb + (max((ll)0,sreq*mid-s))*ms + (max((ll)0,creq*mid-c))*mc) > r )	high = mid;
		else low = mid;
	}
	cout<<low<<endl;

	return 0;

}