#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
# define locked true
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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

bool isChar(char c)
{
	if(c >= 97 && c <= 122)
	{
		return true;
	}
	return false;
}
bool isSym(char c)
{
	if(c == '#' || c == '*' || c == '&')
	{
		return true;
	}
	return false;
}
bool isDigit(char c)
{
	if(c >= 48 && c <= 57)
	{
		return true;
	}
	return false;
}
bool flag_digit = false;
bool flag_char = false;
bool flag_sym = false;

bool allSet()
{
	if(flag_digit == true && flag_sym == true && flag_char == true)
	{
		return true;
	}
	return false;
}




int main()
{	
	std::ios::sync_with_stdio(false);

	ll n,m;
	cin>>n>>m;
	std::vector<string> pass;
	bool stat[60] = {false};
	
	ll index[60] = {0};
	REP(i,n)
	{	
		string s;
		cin>>s;
		pass.pb(s);
	}
	ll limit = n*(m-1);
	ll curr;
	ll i = 0;
	ll count = 0;
	while(i<limit)
	{	
		if(!flag_digit)
		{
			for(curr = 0; curr < n ; curr++)
			{	
				if(!stat[curr])
				{
					if(isDigit(pass[curr][index[curr]]))
					{
						flag_digit = true;
						stat[curr] = locked;
						break;
					}
				}
			}
		}
		if(!flag_sym)
		{
			for(curr = 0; curr < n ; curr++)
			{	
				if(!stat[curr])
				{
					if(isSym(pass[curr][index[curr]]))
					{
						flag_sym = true;
						stat[curr] = locked;
						break;
					}
				}
			}
		}
		if(!flag_char)
		{
			for(curr = 0; curr < n ; curr++)
			{	
				if(!stat[curr])
				{
					if(isChar(pass[curr][index[curr]]))
					{
						flag_char = true;
						stat[curr] = locked;
						break;
					}
				}
			}
		}
		if(allSet)
		{
			for(i)
			return 0;
		}
		
	}


	
}