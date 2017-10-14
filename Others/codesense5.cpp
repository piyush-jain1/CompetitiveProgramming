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
	ll t;
	cin>>t;
	while(t--)
	{	
		ll n,a,b;
		cin>>n>>a>>b;
		ll cash = 0;
		ll digital = 0;
		REP(i,n)
		{	
			// ll temp;
			// cin>>temp;
			// if((temp%b) % gcd(a,b) == 0)
			// {
			// 	cash++;
			// }
			// else
			// {
			// 	digital++;
			// }
			ll temp;
			cin>>temp;
			if(a < b)
			{
				ll surge = a;
				a = b;
				b = surge;
			}
			
			ll stop = (temp/a) + 6;
			REP(j,stop)
			{	
				if((temp - j*a) < 0)
				{
					digital++;
					break;
				}
				else
				{
					if((temp - j*a)%b == 0)
					{
						cash++;
						break;
					}
				}
			}

		}
		cout<<cash<<" "<<digital<<endl;

	}
	return 0;
}
