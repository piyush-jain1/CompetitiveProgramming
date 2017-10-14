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
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
/////////////////////////////////////////////////////////////////////

int main()
{	
	std::ios::sync_with_stdio(false);
	ll n,l;
	std::vector<ll> k,s;
	cin>>n>>l;
	REP(i,n)
	{	
		ll temp;
		cin>>temp;
		k.pb(temp);
	}
	REP(i,n)
	{
		ll temp;
		cin>>temp;
		s.pb(temp);
	}
	
	bool flag = true;
	sort(k.begin(),k.end());

	REP(j,n)
	{	
		ll diff  = s[0]-k[j];
		ll temp[60];
		flag = true;
		REP(i,n)
		{	
			temp[i] = s[i];
			temp[i] = (temp[i]-diff)%l;

			if(find(k.begin(),k.end(),temp[i]) == k.end())
			{	
				flag = false;
				break;
			}
		}

		if(flag)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;



	


	
}