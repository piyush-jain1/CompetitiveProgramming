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

ll dig;


std::map<ll,ll> mapp;

ll modten ( ll dig , ll n , ll m)
{	
	ll power = 1;
	ll curr = dig%m;
	mapp[power] = curr;
	while((power*2) < n)
	{
		mapp[power*2] = (mapp[power]*mapp[power])%m;
		power *= 2;
	}
	ll i = 1;
	ll rest = n-1;
	ll total = 0;
	std::map<ll, ll> frame;
	mapp[0] = 1;
	while(i <= rest)
	{
		total = (total+(curr*mapp[i/2]))%m;
		//cout<<"Total : "<<total<<endl;
		frame[i] = total;
		curr = total;
		i *= 2;
	}
	rest -= i/2;
	while(rest != 0)
	{	
		ll index = floor(log(rest)/log(2));
		index = pow(2,index);
		total = (total*mapp[index])%m;
		total = (total+frame[index])%m;
		//cout<<"Total : "<<total<<endl;
		rest -= index;
	}
	total = (total+1)%m;
	return total;
}

int main()
{	
	std::ios::sync_with_stdio(false);

	ll t;
	cin>>t;
	while(t--)
	{
		ll a,n,m;
		cin>>a>>n>>m;
		dig = 1;
		ll p = a;
		if(p == 0)
		{
			cout<<0<<endl;
		}
		else
		{
			while(p>0)
			{
				p /= 10;
				dig *= 10;
			}

			cout<<((a%m)*modten(dig,n,m))%m<<endl;
		}
		mapp.clear();
	}
	return 0;
}
