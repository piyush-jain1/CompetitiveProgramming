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

int stmax[10000000], stmin[10000000];

int constructSTmax(int ss, int se, int si)
{
	if(ss == se)	stmax[si] = a[ss];
	int mid = ss + (se-ss)/2;
	stmax[si] = max(constructSTmax(ss, mid, si*2+1),constructSTmax(mid+1, se, si*2+2));
	return stmax[si];
}
int constructSTmin(int ss, int se, int si)
{
	if(ss == se)	stmin[si] = a[ss];
	int mid = ss + (se-ss)/2;
	stmin[si] = min(constructSTmin(ss, mid, si*2+1),constructSTmin(mid+1, se, si*2+2));
	return stmin[si];
}
int getMax(int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss and qe >= se)	return stmax[si];
	if(se < qs or ss > qe)	return 0;
	int mid = ss + (se-ss)/2;
	return max(getMax(ss, mid, qs, qe, 2*si+1), getMax(mid+1, se, qs, qe, 2*si+2));
}
int getMin(int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss and qe >= se)	return stmin[si];
	if(se < qs or ss > qe)	return 0;
	int mid = ss + (se-ss)/2;
	return min(getMin(ss, mid, qs, qe, 2*si+1), getMin(mid+1, se, qs, qe, 2*si+2));
}

int main()
{	
	fast_io;
	int n;	cin>>n;
	REP(i,n)	cin>>a[i];
	
	
}