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
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll power10[1000010];
ll a,b;	
void pre()
{
	ll i = 1;
	power10[0] = 1;
	while(i < 1000005)
	{
		power10[i] = (power10[i-1]*10)%b;
		i++;
	}
}

int main()
{
	string s;	cin>>s;
	cin>>a>>b;
	pre();
	ll len = s.length();
	ll i = 0;
	ll j = len-1;
	ll n1 = 0;
	ll n2 = 0;
	ll check2 = len;
	bool flag = false;
	std::vector<ll> prefix,suffix;
	while(i < len-1)
	{	
		n1 = (n1*10+s[i]-'0')%a;
		if(n1 == 0)
		{
			while(i+1 < len and s[i+1] == '0')	i++;
			// DEBUG(i);
			prefix.pb(i);
		}
		i++;
	}
	while(j > 0)
	{	
		ll l = len-1-j;
		n2 = (n2+(s[j]-'0')*power10[l])%b;
		if(n2 == 0 and s[j] != '0')	suffix.pb(j);
		j--;
	}
	// for(auto u:prefix)	cout<<u<<" ";
	// cout<<endl;
	// for(auto u:suffix)	cout<<u<<" ";
	// cout<<endl;
	if(prefix.size() == 0 or suffix.size() == 0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	ll p1=0,p2=suffix.size()-1;

	while(p1 < prefix.size())
	{	
		// DEBUG(prefix[p1]);
		while(p2 > 0 and suffix[p2] < prefix[p1]+1)	p2--;
		// DEBUG(suffix[p2]);
		if(suffix[p2] == prefix[p1]+1)	break;
		p1++;
	}
	// DEBUG(suffix[p2]);
	
	if(p1 == prefix.size())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	REP(p,prefix[p1]+1)	cout<<s[p];
	cout<<endl;
	FOR(p,suffix[p2],len-1)	cout<<s[p];;
	cout<<endl;
	
	return 0;

}