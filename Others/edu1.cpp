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
	ll n,k;
	cin>>n>>k;
	if(k == 1)
	{
		cout<<1<<endl;
		return 0;
	}
	ll count = 1;
	ll upper = ceil((double)n/2.0);
	ll i;
	if(n%2 == 1)
	{	

		for( i = 3 ; i <= upper+1 ; i=i+2)
		{	
			if(n%i == 0)
			{
				count++;
				if(count == k)
				{
					cout<<i<<endl;	
					return 0;			
				}
			}
			
		}
	}
	else
	{	
		for( i = 2 ; i <= upper+1 ; i+= 1)
		{	
			if(n%i == 0)
			{
				count++;
				if(count == k)
				{
					cout<<i<<endl;
					return 0;
				}

			}
		}
	}
	
	if(count == k-1)
	{
		cout<<n<<endl;
		return 0;
	}
	if(count < k-1)
	{
		cout<<-1<<endl;
		return 0;
	}

	
}