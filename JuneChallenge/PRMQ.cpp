#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define int_64 uint64_t
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
// sorting vector of pairs
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{    return (a.first > b.first);	}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{   return (a.second < b.second);		}	
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int n,q;
int a[100010];
vector<int> v[100010];
vector<int> st[1000010];

void getFactors(int i)
{	
	int num = a[i];
	while(num%2 == 0)
	{
		v[i].pb(2);
		num /= 2;
	}
	for(int j = 3; j <= sqrt(num); j+=2)
	{
		while(num%j == 0)
		{
			v[i].pb(j);
			num /= j;
		}
	}
	if(num > 2)	v[i].pb(num);
}


vector<int> constructST(int ss, int se, int si)
{
	if(ss == se)
	{
		st[si] = v[ss];
		return v[ss];
	}
	int mid = ss + (se-ss)/2 ;
	int i = 0;
	int j = 0;
	std::vector<int> a = constructST(ss,mid,si*2+1);
	std::vector<int> b = constructST(mid+1,se,si*2+2);
	while(i < a.size() and j < b.size())
	{
		if(a[i] <= b[j])	st[si].pb(a[i++]);
		else	st[si].pb(b[j++]);
	}
	while(i < a.size())	st[si].pb(a[i++]);
	while(j < b.size())	st[si].pb(b[j++]);
	return st[si];
}


int getValue(int ss, int se, int qs, int qe, int si, int x, int y)
{
	if(qs <= ss and qe >= se)
	{	
		if(st[si][st[si].size()-1] < x)	return 0;
		if(st[si][0] > y)	return 0;
		int up = 0;
		int down = 0;
		int high = st[si].size()-1;
		int low = 0;	
		while(high-low > 1)
		{
			int mid	= (low+high)/2;
			if(st[si][mid] >= x)	high = mid;
			else low = mid;
		}
		if(st[si][low] >= x)	down = low;
		else if(st[si][high] >= x)	down = high;
		high = st[si].size()-1;
		low = 0;
		while(high-low > 1)
		{
			int mid	= (low+high)/2;
			if(st[si][mid] <= y)	low = mid;
			else high = mid;
		}
		if(st[si][high] <= y)	up = high;
		else if(st[si][low] <= y)	up = low;
		return up-down+1;
	}

	if(se < qs or ss > qe)	return 0;

	int mid = ss + (se-ss)/2;
	return getValue(ss, mid, qs, qe, 2*si+1, x, y)+getValue(mid+1, se, qs, qe, 2*si+2, x, y);
}
int main()
{	
	fast_io;
	cin>>n;
	REP(i,n)	cin>>a[i];
	REP(i,n)	getFactors(i);
	constructST(0,n-1,0);
	cin>>q;
	while(q--)
	{
		int l,r,x,y;	cin>>l>>r>>x>>y;
		cout<<getValue(0,n-1,l-1,r-1,0,x,y)<<endl;
	}
	// std::vector<int> p;
	// p.pb(2);
	// p.pb(6);
	// cout<<F(p,6,9)<<endl;
	
	return 0;
}