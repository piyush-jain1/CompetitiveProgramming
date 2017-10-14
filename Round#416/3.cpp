#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false);	cint.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll int
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

ll a[5010];
ll lt[5010], rt[5010];
bool flag[5010];
bool allow[5010] = {false};
// bool allowed(ll i)
// {
// 	ll c = lt[a[i]];
// 	ll b = rt[a[i]];
// 	FOR(j,c,b)
// 	{
// 		if(rt[a[j]] > b)	return false;
// 		// if(lt[a[j] < c])	c = lt[a[j]];
// 	}
// 	return true;
// }

int main()
{	
	// cout << std::setprecision(2)<<fixed;

	ll n;	cin>>n;
	fill(lt, lt+5005, n);
	fill(rt, rt+5005, 1);
	FOR(i,1,n)
	{
		cin>>a[i];
		lt[a[i]] = min(lt[a[i]], i);
		rt[a[i]] = max(rt[a[i]], i);
		// DEBUG(a[i]);
	}
	// FOR(i,1,n)
	// {
	// 	cout<<lt[a[i]]<<"  "<<rt[a[i]]<<endl;
	// }
	ll dp[n+10];
	fill(dp, dp+n+5, 0);
	FOR(i,1,n)
	{	
		// DEBUG(a[i]);
		if(rt[a[i]] == i)
		{	
			// DEBUG(a[i]);
			fill(flag, flag+5005, true);
			// cout<<"yes"<<endl;
			ll j = i;
			ll cur = 0;
			// ll found = 0;
			ll limit = lt[a[i]];
			bool ok = true;
			FORD(k,i,lt[a[i]])	limit = min(limit,lt[a[k]]);
			while(j >= limit and ok)
			{	
				if(rt[a[j]] > rt[a[i]])	ok = false; 
				limit = min(limit, lt[a[j]]);
				// DEBUG(a[j]);
				// DEBUG(flag[a[j]]);
				if(flag[a[j]])
				{
					cur ^= a[j];
					flag[a[j]] = false;
				}
				j--;
			}
			// DEBUG(limit);
			// DEBUG(cur);
			if(ok)	dp[i] = max(dp[j]+cur,dp[i-1]);
			else	dp[i] = dp[i-1];
			// DEBUG(dp[i]);
		}
		else	dp[i] = dp[i-1];
		// DEBUG(dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;

}