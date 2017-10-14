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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll constructTreeUtil(ll a[],ll s, ll e, ll * st, ll si)
{
	if(s==e)
	{
		st[si] = a[s];
		return a[s];
	}

	ll mid = s + (e-s)/2;
	st[si] = constructTreeUtil(a,s,mid,st,2*si + 1) + constructTreeUtil(a,mid+1,e,st,2*si + 2);

	return st[si];
}

ll * constructTree(ll a[], ll n)
{
	ll h = (ll)(ceil(log2(n)));

	ll max_size = 2*(ll)pow(2,h) - 1;

	ll *st = new ll[max_size];

	constructTreeUtil(a, 0, n-1, st, 0);

	return st;

}

ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    ll mid = ss + (se - ss)/2;
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
ll getSum(ll *st, ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if(qe < qs)
    {
    	return getSumUtil(st, 0, n-1, qs , n-1, 0) + getSumUtil(st, 0, n-1, 0, qe, 0);
    }
 	
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int main()
{	
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--)
	{
		ll o1,o2;
		cin>>o1>>o2;
		ll n = o1*o2;
		ll a[n+10];
		ll onecounter = 0;
		REP(i,n)
		{
			cin>>a[i];
			if(a[i] == 1)
			{
				onecounter++;
			}
		}
		
		if(onecounter < (o1/2 + 1)*(o2/2 + 1))
		{
			cout<<0<<endl;
		}
		else
		{	
			ll h = (ll)(ceil(log2(n)));
			ll max_size = 2*(ll)pow(2,h) - 1;
			ll *st = (ll *)malloc(max_size * sizeof(ll));
			st = constructTree(a,n);
			bool flag = false;
			REP(i,o2)
			{	
				ll state = 0;
				for(ll j = i; j < n + i; j+= o2)
				{
					ll temp = getSum(st,n,j%n,(j+o2-1)%n);
					if(temp > o2/2)
					{
						state++;
						if(state > o1/2)
						{
							flag = true;
							break;
						}
					}
				}
				if(flag)
				{
					cout<<1<<endl;
					break;
				}
			}
			if(!flag)
			{
				cout<<0<<endl;
			}
		}
		
	}
	return 0;
	
}
