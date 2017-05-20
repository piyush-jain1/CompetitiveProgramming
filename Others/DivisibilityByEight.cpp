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

string s;	
ll len;
ll pos[10];
bool check(ll a, ll b, ll c)
{	
	ll count = 0;
	FORD(i,len-1,0)
	{
		if(count == 0 && s[i] == a+'0')
		{
			count++;
			pos[0] = i;
		}	
		else if(count == 1 && s[i] == b+'0')
		{
			count++;
			pos[1] = i;
		}
		else if(count == 2 && s[i] == c+'0')
		{
			count++;
			pos[2] = i;
		}
		if(count == 3)	break;
	}
	return count==3;
}
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len = s.length();
	if(len == 1)
	{
		if(s[0] == '0' || s[0] == '8')	cout<<"YES"<<endl<<s<<endl;	
		else cout<<"NO"<<endl;
		return 0;	
	}
	if(len == 2)
	{
		ll n = ((s[0]-'0')*10 + (s[1]-'0'));
		if(n%8 == 0)	cout<<"YES"<<endl<<s<<endl;
		else if(s[0] == '0' || s[0] == '8')	cout<<"YES"<<endl<<s[0]<<endl;
		else if(s[1] == '0' || s[1] == '8')	cout<<"YES"<<endl<<s[1]<<endl;
		else cout<<"NO"<<endl;
		return 0;	
	}
	REP(d,125)
	{
		ll n = d*8;
		ll digit = 0;
		ll a = n%10;	n/=10;
		ll b = n%10;	n/=10;
		ll c = n%10;
		if(c!=0)	digit = 3;
		else
		{
			if(b!=0)	digit = 2;
			else digit = 1;
		}
		// DEBUG(digit);
		// DEBUG(a);
		if(digit == 1)
		{
			REP(i,len)
			{
				if(s[i] == a+'0')	
				{
					cout<<"YES"<<endl<<a<<endl;
					return 0;
				}
			}
		}
		if(digit == 2)
		{	
			ll cnt = 0;
			FORD(i,len-1,0)
			{
				if(cnt == 0 && s[i] == a+'0')	cnt++;
				else if(cnt == 1 && s[i] == b+'0')	cnt++;
				if(cnt == 2)
				{
					cout<<"YES"<<endl<<b<<a<<endl;
					return 0;
				}
			}
		}
		if(check(a,b,c))
		{	
			// DEBUG(pos[0]);
			// DEBUG(pos[1]);
			// DEBUG(pos[2]);

			cout<<"YES"<<endl;
			REP(j,pos[2]+1)	cout<<s[j];
			cout<<s[pos[1]]<<s[pos[0]]<<endl;
			return 0;
		}	
	}
	cout<<"NO"<<endl;
	return 0;

	
}