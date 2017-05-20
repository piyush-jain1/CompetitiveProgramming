#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
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
/////////////////////////////////////////////////////////////////////

int main()
{	
	std::ios::sync_with_stdio(false);
	string s;
	cin>>s;
	ll r = 5,b = 5,y = 5,g = 5;
	ll count[4] = {0};
	bool flag[4] = {false};
	ll n = s.length();
	REP(i,n)
	{
		if(s[i]!='!')
		{
			if(s[i] == 'R')
			{
				r = i%4;
				flag[i%4] = true;
			}
			if(s[i] == 'B')
			{
				b = i%4;
				flag[i%4] = true;
			}
			if(s[i] == 'Y')
			{
				y = i%4;
				flag[i%4] = true;
			}
			if(s[i] == 'G')
			{
				g = i%4;
				flag[i%4] = true;
			}
		}
	}
	ll neit;
	REP(i,4)
	{
		if(!flag[i])
		{
			neit = i;
		}
	}
	if(r == 5)
	{
		r = neit;
	}
	else if(g == 5)
	{
		g = neit;
	}
	else if(y == 5)
	{
		y = neit;
	}
	else if(b == 5)
	{
		b = neit;
	}

	REP(i,n)
	{
		if(s[i] == '!')
		{
			if(i%4 == r)
			{
				count[0]++;
			}
			else if(i%4 == b)
			{
				count[1]++;
			}
			else if(i%4 == y)
			{
				count[2]++;
			}
			else if(i%4 == g)
			{
				count[3]++;
			}
		}
	}
	cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<count[3]<<endl;
	return 0;

	
}