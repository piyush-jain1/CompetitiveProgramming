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

ll net_h,ht;
ll power[65];
void pre()
{
	power[0] = 1;
	FOR(i,1,59)	power[i] = power[i-1]*2;
}

ll h(ll x,ll n)
{	
	// DEBUG(x);

	if(x == (n+1)/2)	return 1;
	if(x < (n+1)/2)		return 1+h(x,(n-1)/2);
	if(x > (n+1)/2)		return 1+h(x-(n+1)/2 , (n-1)/2);
}
ll U(ll x, ll n)
{	
	if(x== (n+1)/2)		return x;
	ll r = x;
	while(!(r%2))	r/=2;

	if((r+1)%4 == 0)
	{	
		int ind = net_h - ht;
		ll temp = (x-power[ind]);
		if(temp >= 1 && temp <= n)	return temp;
		else return x;
	}
	if((r-1)%4 == 0)
	{	
		int ind = net_h - ht;
		ll temp = (x+power[ind]);
		if(temp >= 1 && temp <= n)	return temp;
		else return x;
	}
}

ll L(ll x, ll n)	
{	
	if(x%2)	return x;
	// DEBUG(net_h - ht-1);
	int ind = net_h - ht-1;
	ll temp = (x - power[ind]); 
	if(temp >= 1 && temp <= n)	return temp;
	else return x;
}


ll R(ll x, ll n)	
{	
	if(x%2)	return x;
	int ind = net_h - ht-1;
	ll temp = (x + power[ind]);	
	if(temp >= 1 && temp <= n)	return temp;
	else return x;
}

int main()
{	
	std::ios::sync_with_stdio(false);
	pre();
	ll n,q;		cin>>n>>q;
	net_h = log2(n+1);
	// DEBUG(net_h);
	while(q--)
	{
		ll x;	cin>>x;
		ht = h(x,n);
		string s;	cin>>s;
		ll len = s.length();

		// DEBUG(ht);
		ll newx;
		REP(i,len)
		{	
			// DEBUG(i);
			// DEBUG(x);
			// DEBUG(ht);
			if(s[i] == 'U')	
			{
				newx = U(x,n);
				if(x != newx)	ht -= 1;
			}
				

			if(s[i] == 'L')	
			{
				newx = L(x,n);
				if(x != newx) ht += 1;
			}	
			if(s[i] == 'R')
			{
				newx = R(x,n);
				if(x != newx)	ht += 1;
			}
			x = newx;
		}
		cout<<x<<endl;
	}
	return 0;
	
}