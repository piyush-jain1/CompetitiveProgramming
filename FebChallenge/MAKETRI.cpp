#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(uint64_t i=0;i<(n);i++)
#define FOR(i,a,b) for(uint64_t i=(a);i<=(b);i++)
#define FORD(i,a,b) for(uint64_t i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
/////////////////////////////////////////////////////////////////////

int main()
{
	uint64_t n,l,r;
	cin>>n>>l>>r;
	uint64_t a[n+10];
	std::vector<pair<ll,ll>> diff;
	FOR(i,0,n-1)
	{
		cin>>a[i];	
	}
	sort(a,a+n);
	FOR(i,1,n-1)
	{
		ll temp = abs(a[i]-a[i-1]);
		diff.pb(mp(i,temp));
	}
	sort(diff.begin(),diff.end(),sortbysec);
	// FOR(i,0,n-2)
	// {
	// 	cout<<diff[i].first<<" "<<diff[i].second<<endl;
	// }
	ll i = 0;
	ll range = 0;
	ll range_max = 0;
	ll range_min = (ll)1e18-1;
	std::vector<pair<ll,ll>> ranges;
	while(i < n-1)
	{
		ll temp_max = a[diff[i].first]+a[diff[i].first - 1]-1;
		ll temp_min = (diff[i].second) +1;
		ranges.pb(mp(temp_min,temp_max));
		i++;
	}
	sort(ranges.begin(),ranges.end());
	// REP(i,n-1)
	// {
	// 	cout<<ranges[i].first<<" "<<ranges[i].second<<endl;
	// }

	ll count = 0;
	REP(i,n-1)
	{	
		if(l < ranges[i].first)
		{
			if(r < ranges[i].first)
			{
				break;
			}
			else if(r <= ranges[i].second)
			{
				count += r-ranges[i].first + 1;
				break;
			}
			else
			{
				count += ranges[i].second - ranges[i].first + 1;
				l = ranges[i].second + 1;
			}
		}
		else if(l <= ranges[i].second)
		{
			if(r < ranges[i].first)
			{
				break;
			}
			else if(r <= ranges[i].second)
			{
				count += r-l + 1;
				break;
			}
			else
			{
				count += ranges[i].second - l + 1;
				l = ranges[i].second + 1;
			}
		}
		if(l > r)
		{
			break;
		}
	}
	cout<<count<<endl;
	return 0;


}
