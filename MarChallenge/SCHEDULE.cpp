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
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define int_64 uint64_t
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(ll x,ll y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
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
	
bool poss(vector<ll> chunk ,ll mid, ll k)
{	
	ll size = chunk.size();
	ll count = 0;
	REP(i,size)
	{
		count += chunk[i]/(mid+1) ; 
	}
	if(count <= k)
	{
		return true;
	}
	return false;
}

int main()
{	
	std::ios::sync_with_stdio(false);
	
	ll t;		cin>>t;
	while(t--)
	{	
		ll n,k;		cin>>n>>k;
		string s;	cin>>s;
		ll count1 = 0;
		ll count2 = 0;
		REP(i,n)
		{
			if((i%2 == 0 && s[i] == '1') || (i%2 == 1 && s[i] == '0'))
			{
				count1++;
			}
			if((i%2 == 0 && s[i] == '0') || (i%2 == 1 && s[i] == '1'))
			{
				count2++;
			}

		}
		if(count1 <= k || count2 <= k)
		{
			cout<<1<<endl;
		}
		else
		{
			std::vector<ll> chunk;
			ll maxm = 0;
			REP(i,n)
			{		
				ll j = i;
				if(s[j] == '0')
				{	
					ll count = 0;
					while(s[j] == '0')
					{	
						count++;
						j++;
					}
					maxm = max(maxm,count);
					chunk.pb(count);
					i = j-1;
				}
				else if(s[j] == '1')
				{
					ll count = 0;
					while(s[j] == '1')
					{	
						count++;
						j++;
					}
					maxm = max(maxm,count);
					chunk.pb(count);
					i = j-1;
				}
			}
			ll low = 2;
			ll high = maxm;
			while(low <= high)
			{
				ll mid = low + (high-low)/2;
				if(poss(chunk,mid,k))
				{
					high = mid-1;
				}
				else
				{
					low = mid+1;
				}
			}
			cout<<low<<endl; 
		}
	}
	return 0;

	
	
}