#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <string>
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

	ll a,b,c;
	cin>>a>>b>>c;
	ll m;
	cin>>m;
	unordered_map<ll,string> type;
	unordered_map<ll,bool> flag;
	ll arr[m+5];
	ll countusb = 0;
	ll countps2 = 0;
	REP(i,m)
	{	
		string s;
		cin>>arr[i]>>s;
		type[arr[i]] = s;
		flag[arr[i]] = false;
		if( s == "USB")
		{
			countusb++;
		}
		else
		{
			countps2++;
		}
	}
	sort(arr,arr+m);
	ll limitusb = countusb;
	ll limitps2 = countps2;
	ll counting = 0;
	ll price = 0;
	ll i = 0;
	while(limitusb>0 && a>0)
	{	
		if(type[arr[i]] == "USB")
		{
			counting++;
			price += arr[i];
			flag[arr[i]] = true;
			limitusb--;
			a--;
		}
		i++;
		
	}
	i = 0;
	while(limitps2>0 && b>0)
	{
		if(type[arr[i]] == "PS/2")
		{
			counting++;
			price += arr[i];
			flag[arr[i]] = true;
			limitps2--;
			b--;
		}
		i++;
	}
		
	ll limit = (countusb+countps2-counting);
	i = 0;
	while(c>0 && limit>0)
	{
		if(!flag[arr[i]])
		{
			counting++;
			price += arr[i];
			flag[arr[i]] = true;
			c--;
			limit--;
		}
		i++;
	}
	
	cout<<counting<<" "<<price<<endl;
	return 0;

	
}