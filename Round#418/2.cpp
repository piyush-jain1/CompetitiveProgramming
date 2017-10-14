#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
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
int a[1010], b[1010];
int s[1010];
std::vector<int> area;

int main()
{	
	fast_io;
	int n;	cin>>n;
	std::vector<int> repeata, repeatb;
	std::vector<int> checka[1010];
	FOR(i,1,n)
	{
		cin>>a[i];
		checka[a[i]].pb(i);
		if(checka[a[i]].size() > 1)
		{
			for(auto u : checka[a[i]])	repeata.pb(u);
		}
	}
	std::vector<int> checkb[1010];
	FOR(i,1,n)
	{
		cin>>b[i];
		checkb[b[i]].pb(i);
		if(checkb[b[i]].size() > 1)
		{
			for(auto u : checkb[b[i]])	repeatb.pb(u);
		}
	}
	bool gota[1010];
	bool gotb[1010];
	FOR(i,1,n)
	{
		gota[a[i]] = true;
		gotb[b[i]]	= true;
	}
	fill(s, s+n+5, 0);
	if(a[repeata[0]] != b[repeata[0]])
	{
		if(gota[b[repeata[0]]] == false)
		{
			s[repeata[0]] = b[repeata[0]];
			s[repeata[1]] = a[repeata[1]];
		}
		else if(gotb[a[repeata[0]]] == false)
		{
			s[repeata[0]] = a[repeata[0]];
			s[repeata[1]] = b[repeata[1]];
		}
	}
	else
	{
		int ans ;
		FOR(i,1,n)
		{
			if(gota[i] == false)
			{
				ans = i;
				break;
			}
		}
		// DEBUG(repeata[1]);

		s[repeata[1]] = ans;
	}
	FOR(i,1,n)
	{
		if(s[i] == 0)	cout<<a[i]<<" ";
		else cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}