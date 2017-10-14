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
	ll test;
	cin>>test;
	FOR(t,1,test)
	{	
		ll n;
		cin>>n;
		ll x[n+5],h[n+5],e[n+5];
		ll ax,bx,cx,ah,bh,ch;
		cin>>x[1]>>ax>>bx>>cx;
		cin>>h[1]>>ah>>bh>>ch;
		ll start = 0;
		ll end = 0;
		e[1] = x[1] + h[1];
		FOR(i,2,n)
		{
			x[i] = (((ax * x[i-1]) + bx)%cx)+1;
			h[i] = (((ah * h[i-1]) + bh)%ch)+1;
		}
		double area = h[1]*h[1];
		double prevarea = h[1]*h[1];
		double temparea;
		end = 2*h[1];
		FOR(i,2,n)
		{	
			
			if((x[i]-h[i]) < end && (x[i] + h[i]) > end)
			{	
				e[i] = x[i] + h[i];
				double k = abs(e[i]-end);
				temparea = prevarea +  k*((double)h[i] - k/4.0) ;
				end = x[i]+h[i];
			}
			else if((x[i]+h[i]) > start && (x[i]-h[i]) < start)
			{	
				e[i] = x[i] - h[i];
				double k = abs(start-e[i]);
				temparea = prevarea +  k*((double)h[i] - k/4.0) ;
				start = x[i]-h[i];
			}
			else if(x[i]-h[i] > end)
			{
				temparea = h[i]*h[i];
				end = x[i]+h[i];
			}  
			else if(x[i] + h[i] < start)
			{
				temparea = h[i]*h[i];
				start = x[i]-h[i];
			}
			// DEBUG(temparea);
			prevarea = temparea;
			area += temparea;
			// DEBUG(area);
		}

		cout<<area<<endl;



	}
	

	
}