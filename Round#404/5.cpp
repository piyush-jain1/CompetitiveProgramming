#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define int_64 uint64_t
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(ll x,ll y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
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

// count the no. of inversions while merging the subarrays
ll merge(ll a[],ll l,ll m,ll r)
{
    static ll inversion=0;
    ll n1=m-l+1;
    ll n2=r-m;
    ll L[n1],R[n2];
    ll i,j;
    for(i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[m+1+j];
    }
    i=j=0;
    ll k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];
        }
        else
        {
            a[k++]=R[j++];
            inversion+=n1-i;    //whenever element in left subarray in greater than that in right subarray, inversion will increase by the no of elements remaining in the left subarray
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }
    return inversion;
}

ll mergesort(ll a[], ll l, ll r)
{   ll output;
    if(l<r)
    {
        ll m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        output=merge(a,l,m,r);
    }
    return output;

}


int main()
{	
	std::ios::sync_with_stdio(false);
	ll n,q;	cin>>n>>q;
	ll value[n+10];
	ll aux[n+10];
	FOR(i,1,n)
	{
		value[i] = i;
		aux[i] = i;
	}
	while(q--)
	{
		ll l,r;
		// DEBUG(q);
		cin>>l>>r;
		ll temp = value[l];
		value[l] = value[r];
		value[r] = temp;
		cout<<mergesort(value,1,n)<<endl;
	}

	
}