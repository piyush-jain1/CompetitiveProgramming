#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=(a);i<=(b);i++)
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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool is_integer(float k)
{
  return std::floor(k) == k;
}

int main()
{
	int a,b;	cin>>a>>b;
	FOR(x,1,a-1)
	{	
		if(is_integer(sqrt(a*a - x*x)))
		{
			int y = (int)sqrt(a*a - x*x);
			int g = gcd(x,y);
			int len = sqrt((y*y + x*x)/(g*g));
			if(b%len == 0)
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = x;
				int y2 = y;
				int x3 = (-y*b)/(g*len);
				int y3 = (x*b)/(g*len);
				if(x1 != x2 and x2 != x3 and x3 != x1 and y1 != y2 and y2 != y3 and y3 != y1)
				{
					cout<<"YES"<<endl;
					cout<<x1<<" "<<y1<<endl;
					cout<<x2<<" "<<y2<<endl;
					cout<<x3<<" "<<y3<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}