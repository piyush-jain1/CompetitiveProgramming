#include <bits/stdc++.h>
#include <map>
#include <math.h>
#include <unordered_map>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
	int t;
	cin>>t;
	REP(i,t)
	{	
		int p,x,y;
		cin>>p>>x>>y;
		if ( p == 0 )
		{
			cout<< "Case #"<<i+1<<": white"<<endl;
			continue;
		}
		double distance = sqrt((x-50)*(x-50) + (y-50)*(y-50));
		if ( distance  > 50.0 )
		{
			cout<< "Case #"<<i+1<<": white"<<endl;
			continue;
		}
		if( x == 50 && y==50 )
		{
			if(p==0)
			{
				cout<< "Case #"<<i+1<<": white"<<endl;
			}
			else
			{
				cout<< "Case #"<<i+1<<": black"<<endl;
			}
			continue;
		}
		else if( x >= 50 && y >= 50 )
		{
			double mine = atan ((double)(x-50)/(double)(y-50));
			double filled = ((double)p*2.0*PI)/100.0;
			if( mine >= 0.0 && mine <= filled)
			{
				cout<< "Case #"<<i+1<<": black"<<endl;
			}
			else
			{
				cout<< "Case #"<<i+1<<": white"<<endl;
			}
		}
		else if( x >= 50 && y < 50 )
		{
			double mine = atan ((double)(x-50)/(double)(50-y));
			double filled = ((double)p*2.0*PI)/100.0;
			if ( (PI - mine) >= PI/2.0 && mine <= filled)
			{
				cout<< "Case #"<<i+1<<": black"<<endl;
			}
			else
			{
				cout<< "Case #"<<i+1<<": white"<<endl;
			}
		}
		else if( x <= 50 &&  y <= 50 )
		{
			double mine = atan ((double)(50-x)/(double)(50-y));
			double filled = ((double)p*2.0*PI)/100.0;
			if ( (PI + mine) >= PI && mine <= filled)
			{
				cout<< "Case #"<<i+1<<": black"<<endl;
			}
			else
			{
				cout<< "Case #"<<i+1<<": white"<<endl;
			}
		}
		else if( x <= 50 && y > 50 )
		{
			double mine = atan ((double)(50-x)/(double)(y-50));
			double filled = ((double)p*2.0*PI)/100.0;
			if ( (2.0*PI - mine) >= (3.0*PI)/2.0 && mine <= filled)
			{
				cout<< "Case #"<<i+1<<": black"<<endl;
			}
			else
			{
				cout<< "Case #"<<i+1<<": white"<<endl;
			}
		}
	}
	return 0;
}
