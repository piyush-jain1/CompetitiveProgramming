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

ll lower = 0;
ll upper = 0;
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    ll mid = ss + (se - ss)/2;
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

ll *constructST(ll arr[], ll l, ll r)
{	
	ll n = r-l+1;
    ll x = (ll)(ceil(log2(n))); 
    ll max_size = 2*(ll)pow(2, x) - 1; 
    ll *st = new ll[max_size];
    constructSTUtil(arr, l, r, st, 0);
    return st;
}

ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)
{	
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    ll mid = ss + (se - ss)/2;
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

ll getSum(ll *st, ll l, ll r, ll size)
{	
	ll sum = -1;
	ll temp_lower,temp_upper;
	FOR(i,lower,upper-size+1)
	{
		ll qs = i;
		ll qe = i+size-1;
   		ll temp = getSumUtil(st, l, r, qs, qe, 0);
		if(temp > sum)
		{
			sum = temp;
			temp_lower = qs;
			temp_upper = qe;
		}
	}
	lower = temp_lower+1;
	upper = temp_upper-1;
    return sum;
}
int main()
{	
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll a[n+10],b[m+10];
		lower = 0;
		upper = 0;
		FOR(i,1,n)
		{
			cin>>a[i];
		}
		FOR(i,1,m)
		{
			cin>>b[i];
		}
		ll limit = n-b[1]+1;
		ll maxsum = 0;
		ll maxind = 0;
		FOR(i,1,b[1])
		{	
			maxsum += a[i];
		}
		maxind = b[1];
		FOR(i,b[1]+1,n)
		{
			ll j = i-b[1];
			if(a[i] > a[j])
			{
				maxsum = maxsum - a[j] + a[i];
				maxind = i;
			}
		}
		lower = maxind-b[1]+1;
		upper = maxind;
		ll p = b[1]-2;
	    ll x = (ll)(ceil(log2(p))); 
	    ll max_size = 2*(ll)pow(2, x) - 1; 
		ll *st = new ll[max_size];
		lower += 1;
		upper -= 1;
		st = constructST(a,lower,upper);
		ll fac = -1;
		ll l = lower;
		ll r = upper;
		ll score = maxsum;
		//DEBUG(score);
		FOR(i,2,m)
		{	
			if(lower > upper)
			{
				break;
			}
			ll size = b[i];
			score += fac*getSum(st,l,r,size);
			fac *= -1;
		}
		cout<<score<<endl;
	}
	return 0;
	
}