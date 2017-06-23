#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define left true
#define right false
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
#define mod 1000000007
////////////////////////////////////////////////////////////////////////////////////////

int w[100010];

int main()
{
	int n,l,r,ql,qr;	cin>>n>>l>>r>>ql>>qr;
	FOR(i,1,n)	cin>>w[i];
	int i = 1;
	int j = n;
	ll cost = 1e15;
	bool side = left;
	ll leftsum[n+10], rightsum[n+10];
	leftsum[0] = 0;
	rightsum[n+1] = 0;
	FOR(i,1,n)
	{
		leftsum[i] = (leftsum[i-1]+w[i]);
	}
	FORD(i,n,1)
	{
		rightsum[i] = (rightsum[i+1]+w[i]);
	}
	// FOR(i,1,n)	cout<<leftsum[i]<<" "<<rightsum[i]<<endl;
	FOR(i,0,n)
	{
		ll temp = 0;
		// DEBUG(leftsum[i]);
		// DEBUG(rightsum[i+1]);
		temp = leftsum[i]*l+rightsum[i+1]*r;
		// DEBUG(temp);
		if(i > n-i+1)
		{	
			temp += ql*(i-n+i-1);
		}
		else if(i < n-i-1)
		{
			temp += qr*(n-i-i-1);
		}
		// DEBUG(temp);
		cost = min(cost,temp);
	}
	cout<<cost<<endl;
	return 0;

}