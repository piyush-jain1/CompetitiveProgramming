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
	ll n,q;
	cin>>n>>q;
	ll a[100010];
	REP(i,n)
	{
		cin>>a[i];
	}
	ll qt,qs,qe;
	while(q--)
    {
        cin>>qt>>qs>>qe;
        ll count = 0;
        if(qt==1)
        {	
        	FOR(j,qs-1,qe-1)
			{	
				bool isPrime = true;
				for(ll i = 2; i <= a[j] / 2; ++i)
				{
					if(a[j] % i == 0)
					{
					  isPrime = false;
					  break;
					}
				}
				if(isPrime == true)
				{
					count++;
				}
			}
			cout<<count<<endl;
        }
        else if(qt==2)
        {
            a[qs-1] = qe;
        }
    }
    return 0;

}