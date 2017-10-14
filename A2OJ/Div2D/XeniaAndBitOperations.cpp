#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
using namespace std;
///////////////////////////////////////////////////////
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
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll constructSTOR(ll ss, ll se, ll si);
ll constructSTXOR(ll ss, ll se, ll si);
void updateValueOR(ll ss, ll se, ll i, ll b, ll si);
void updateValueXOR(ll ss, ll se, ll i, ll b, ll si);
ll size,p;
ll st[6000000];
ll a[150000];

ll constructSTOR(ll ss, ll se, ll si)
{
	if(ss == se)
	{	
		// trace(ss);
		st[si] = a[ss];
		return a[ss];
	}

	ll mid = ss + (se-ss)/2;
	// trace(si);
	return st[si] = constructSTXOR(ss, mid, si*2+1) | constructSTXOR(mid+1, se, si*2+2);
	// trace2(si,st[si]);
}
ll constructSTXOR(ll ss, ll se, ll si)
{
	if(ss == se)
	{	
		st[si] = a[ss];
		return a[ss];
	}

	ll mid = ss + (se-ss)/2;
	// trace(si);
	return st[si] = constructSTOR(ss, mid, si*2+1) ^ constructSTOR(mid+1, se, si*2+2);
	// trace2(si,st[si]);
}

void updateValueOR(ll ss, ll se, ll i, ll b, ll si)
{
	if(i < ss or i > se)	return;
	if(ss == se)
	{	
		if(2*size-1-si == size-p+1)
		{	
			// trace(si);
			st[si] = b;
		}
		return;	
	}
	// else
	// {
	// 	st[si] = st[si*2+1] | st[si*2+2];
	// 	// trace(st[si]);
	// }
	ll mid = ss + (se-ss)/2;
	updateValueXOR(ss, mid, i, b, 2*si+1);
	updateValueXOR(mid+1, se, i, b, 2*si+2);
	if(si < size-1) st[si] = st[si*2+1] | st[si*2+2];
	return;
}
void updateValueXOR(ll ss, ll se, ll i, ll b, ll si)
{
	if(i < ss or i > se)	return;
	if(ss == se)
	{	
		if(2*size-1-si == size-p+1)
		{	
			// trace(si);
			st[si] = b;
		}
		return;
	}
	// else
	// {
	// 	st[si] = st[si*2+1] | st[si*2+2];
	// 	// trace(st[si]);
	// }
	ll mid = ss + (se-ss)/2;
	updateValueOR(ss, mid, i, b, 2*si+1);
	updateValueOR(mid+1, se, i, b, 2*si+2);
	if(si < size-1) st[si] = st[si*2+1] ^ st[si*2+2];
	return;
}

int main()
{	
	fast_io;
	ll n,m;	cin>>n>>m;
	size = pow(2,n);
	ll s = size;
	REP(i,size)	cin>>a[i];
	if(n%2 == 0)	constructSTXOR(0,size-1,0);
	else	constructSTOR(0,size-1,0);
	// debug_array(st, 2*s-1);
	// cout<<"--------------------------------"<<endl;
	while(m--)
	{
		ll b;	cin>>p>>b;
		a[p] = b;
		if(n%2 == 0)	updateValueXOR(0,s-1,p-1,b,0);
		else	updateValueOR(0,s-1,p-1,b,0);
		// debug_array(st, 2*s-1);
		cout<<st[0]<<endl;
	}
	return 0;
	
}