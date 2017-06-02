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

char a[20][110];
ll lt[20];
ll rt[20];
bool empty[20];
int main()
{	
	fast_io;
	ll n,m;	cin>>n>>m;
	FORD(i,n,1)
	{		
		empty[i] = true;
		lt[i] = m+2;
		rt[i] = 1;
		FOR(j,1,m+2)
		{
			cin>>a[i][j];
			if(a[i][j] == '1')
			{	
				empty[i] = false;
				lt[i] = min(lt[i],j);
				rt[i] = max(rt[i],j);
			}

		}
		// DEBUG(lt[i]);
		// DEBUG(rt[i]);
	}
	bool right = false;
	ll ans = 0;
	ll total = pow(2,n);
	ll counter,j;
	ll ans = 0;
	for(counter = 0,counter < pow_set_size; counter++)
	{
		for(j=0;j<n;j++)
		{
			if(couonter & (1<<j))
				
		}
	}

	// FOR(i,1,n)
	// {	
	// 	// DEBUG(i);
	// 	// DEBUG(right);
	// 	if(!right)
	// 	{
	// 		if(!empty[i])	ans += rt[i]-1;
	// 		else
	// 		{
	// 			if(i == n)	break;
	// 			ll costr = m+2-(rt[i]) + (m+2)-rt[i+1] + 1;
	// 			ll costl = rt[i]-1 + lt[i+1];
	// 			// DEBUG(costl);
	// 			// DEBUG(costr);
	// 			if(costr < costl)
	// 			{
	// 				ans += m+2-(rt[i])+1;
	// 				right = true;
	// 			}	
	// 			else
	// 			{
	// 				ans += rt[i];
	// 			}
	// 			// DEBUG(rt[i]-1);		
	// 		}
			
	// 	}
	// 	else
	// 	{
	// 		ans += m+2-lt[i];
	// 		if(i == n)	break;	
	// 		ll costr = m+2-lt[i] + m+2 - rt[i+1] + 1;
	// 		ll costl = lt[i]-1+lt[i+1];
	// 		// DEBUG(costl);
	// 		// DEBUG(costr);
	// 		if(costr > costl)
	// 		{	
	// 			ans += lt[i];
	// 			right = false;
	// 		}
	// 		else
	// 		{
	// 			ans += m+2-lt[i]+1;
	// 		}
	// 		// DEBUG(m+2-lt[i]);
	// 	}
	// 	// DEBUG(ans);
	}
	cout<<ans<<endl;
	
}