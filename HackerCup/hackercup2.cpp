#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#define pb push_back
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
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
	int test;
	cin>>test;
	REP(j,test)
	{
		int n;
		cin>>n;
		std::vector<int> weight;
		int temp;
		REP(i,n)
		{
			cin>>temp;
			weight.pb(temp);
		}
		sort(weight.begin(),weight.end(),wayToSort);
	
		int count = 0;
		while(!weight.empty())
		{
			int k = ceil(50.0/(double)weight[0]);
			if(weight.size()<k)
			{
				break;
			}
			weight.erase(weight.begin());
			weight.erase(weight.end()-k+1,weight.end());
			count++;
		}
		cout<<"Case #"<<j+1<<": "<<count<<endl;
	}
	return 0;
}