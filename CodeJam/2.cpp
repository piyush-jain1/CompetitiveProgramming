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

int main()
{	
	std::ios::sync_with_stdio(false);
	ll test;	cin>>test;
	FOR(t,1,test)
	{
		ll n;	cin>>n;
		ll a[20];
		ll i = 0;
		while(n!=0)
		{
			a[i] = n%10;
			n /= 10;
			i++;
		}
		cout<<"Case #"<<t<<": ";
		
		ll j = i-1;
		ll start = j;
		bool tidy = true;
		while(j > 0)
		{
			if(a[j-1] > a[j])	start = j-1;
			if(a[j-1] < a[j])	
			{
				tidy = false; 
				break;
			}
			j--;
		}
		if(!tidy)
		{
			ll k = i-1;
			
			while(k >= 0)
			{
				if(k > start)	cout<<a[k];
				else if(k == start)	
				{	
					if(k != i-1 || (k==i-1 && a[k]>1))	cout<<a[k]-1;
				}	
				else	cout<<9;
				k--;
			}
		}
		else
		{
			FORD(k,i-1,0)	cout<<a[k];
		}
		
		cout<<endl;
		
		
	}
	return 0;
}