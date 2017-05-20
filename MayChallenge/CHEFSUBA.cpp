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
#define MAX 200020


ll shift[MAX];
ll counter[MAX];
ll LR[MAX]; 
ll RL[MAX]; 
ll max_val[MAX]; 
ll a[100010];
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,k,p;	cin>>n>>k>>p;
	
	FOR(i,1,n)
	{
		cin>>a[i];
		if(i<=k and a[i] == 1)
		{
			counter[1]++;
		}
	}
	if(n > 1000)
	{
		a[0] = a[n];
		// cout<<count[0]<<" ";
		FOR(i,2,n)
		{
			if(a[i-1] == 0 and a[(i+k-1)%n] == 1)
			{	
				
				counter[i] = counter[i-1]+1;
			}	
			else if(a[i-1] == 1 and a[(i+k-1)%n] == 0)
			{
				counter[i] = counter[i-1]-1;
			}	
			else
			{	
				counter[i] = counter[i-1];
			}
			// cout<<count[r]<<" ";
		}
		// cout<<endl;
		FOR(i,1,n-k)	counter[n+i] = counter[i];
		// FOR(i,1,n+n-k)	cout<<counter[i]<<" ";
		// cout<<endl;
		ll rem = n;
		ll size = n-k+1;
		n = n+n-k;
		ll i;
		for(i = 1; i <= n; i++){
	        if(i % size == 1)
	            LR[i] = counter[i];
	        else
	            LR[i] = max(LR[i - 1], counter[i]);        
	    }

	    for(i = n; i >= 1; i--){
	        if(i == n) 
	            RL[i] = counter[i]; 
	        else if(i % size == 0) 
	            RL[i] = counter[i];
	        else
	            RL[i] = max(RL[i+1], counter[i]);
	    }
	    ll nw = n-size+1;
	    // DEBUG(nw);
	    for(i = 1; i <= nw; i++)   
	        max_val[i] = max(RL[i], LR[i + size - 1]);

	   	ll ind = nw-1;
	    for(i = 1; i <= nw ; i++)
	    {
	    	if(i==1)	shift[0] = max_val[i];
	    	else	shift[ind--] = max_val[i];
	    }
	    // REP(i,nw)	cout<<shift[i]<<" ";
	    // cout<<endl;

		string query;	cin>>query;
		// DEBUG(rem);
		ll shiftcount = 0;
		REP(i,p)
		{
			if(query[i] == '?')	cout<<shift[shiftcount%rem]<<endl;
			else	shiftcount++;
		}

	}
	// brute force hai bc
	else
	{
		string query;	cin>>query;
		ll curr = 0;
		ll prev = 0;
		ll maxm = 0;
		REP(i,p)
		{
			if(query[i] == '?')
			{	
				curr = 0;
				maxm = 0;
				FOR(i,1,k)	curr+=a[i];
				maxm = curr;
				prev = curr;
				FOR(i,2,n-k+1)
				{
					curr = prev-a[i-1]+a[i+k-1];
					maxm = max(maxm,curr);
					prev = curr;
				}
				cout<<maxm<<endl;
			}
			else
			{	
				ll temp = a[n];
				FORD(i,n-1,1)	a[i+1] = a[i];
				a[1] = temp;
			}
		}
	}

	return 0;
	
}