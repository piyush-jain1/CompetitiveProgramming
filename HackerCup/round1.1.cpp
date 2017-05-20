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
	ll c[310][310],cost[310][310] ;
	FOR(r,1,t)
	{
		ll n,m;
		cin>>n>>m;
		FOR(j,1,n)
		{	
			FOR(k,1,m)
			{	
				cin>>c[j][k];
			}
			sort(c[j]+1,c[j]+m+1);
		}
		FOR(j,1,n)
		{	
			cost[j][0] = 0;
			FOR(k,1,m)
			{	
				cost[j][k] = c[j][k] + cost[j][k-1] - (k-1)*(k-1) + (k*k);
			}
		}
		
		ll current[310] = {0};
		ll mincost = cost[1][1];
		current[1] = 1;
		ll count = 1;
		ll minimum;
		ll minindex;
		while(count < n)
		{	
			minimum = cost[count+1][current[count+1]+1] - cost[count+1][current[count+1]];
			minindex = count+1;
			FOR(i,1,count)
			{	
				if(current[i] < m)
				{
					if((cost[i][current[i]+1] - cost[i][current[i]]) < minimum)
					{	
						minimum = (cost[i][current[i]+1] - cost[i][current[i]]);
						minindex = i;
					} 
				}
			}
			current[minindex] += 1;
			mincost += minimum;
			count++;	
		}
		cout<<"Case #"<<r<<": "<<mincost<<endl;
	}
	return 0;
}