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

ll a [50];

ll power2[80];
void cal2pow()
{
	power2[0] = 1;
	FOR(i,1,64)	power2[i] = power2[i-1]*2;
}
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,k;	cin>>n>>k;
	cal2pow();
	REP(i,n)	
	{
		cin>>a[i];
	}
	// DEBUG(k);

	// sort(a,a+n, wayToSort);
	ll set_size = n-n/2;
	ll pow_set_size1 = pow(2, set_size);
    ll counter, j;
    ll prod1[pow_set_size1+10];
    fill(prod1, prod1+pow_set_size1+5,0.0);
    ll ans = 0;
    ll prod = 1;
    ll index1 = 0;
    ll index2 = 0;
    bool flag;
    for(counter = 1; counter < pow_set_size1; counter++)
    {
    	prod = 1;
    	flag = true;
      for(j = 0; j < set_size; j++)
       {
          if(counter & power2[j])
          {
          	if(prod > k/a[j])
          	{
          		flag = false;
          	}	
          	prod *= a[j];
          }
            
       } 
       // cout<<endl; 

       if(flag	)
	   	{
	   		// cout<<prod<<endl;
	   		prod1[index1++] = prod;
	   		ans++;
	   	}
    }	
    // sort(sum1,sum1+pow_set_size1);
    // REP(i,index1)	
   	// {
   	// 	cout<<prod1[i]<<endl;
   	// }
    set_size = n/2;
    ll pow_set_size2 = pow(2, set_size);
    ll prod2[pow_set_size2+10];
    fill(prod2, prod2+pow_set_size2+5,0.0);
    for(counter = 1; counter < pow_set_size2; counter++)
    {
    	prod = 1;
    	flag = true;
      for(j = 0; j < set_size; j++)
       {
          if(counter & power2[j])
          {	
          	if(prod > k/a[j+(n-n/2)])	flag = false;
          	prod *= a[j+(n-n/2)];
          }
            
       }
       // cout<<endl;
       if(flag)
       {
       	// DEBUG(counter);
       	// cout<<prod<<endl;
        prod2[index2++] = prod;
       	ans++;
       }	   
    }
    sort(prod2,prod2+index2);
   	// REP(i,index2)	
   	// {
   	// 	cout<<prod2[i]<<endl;

   	// }
   	// DEBUG(index1);
   	// DEBUG(index2);
   	// cout<<"e48r"<<endl;
    for(ll i = 0 ; i < index1; i++)
    {	
    	// cout<<"sum1[i] : "<<pow(10,sum1[i])<<endl;
    	ll res = k/prod1[i];
    	// DEBUG(res);
    	ll low = 0;
    	ll high = index2-1;
    	if(low == high)
    	{
    		if(prod2[low] <= res)	ans += 1;
    	}
    	else
    	{
    		while(abs(high-low)>1)
	    	{
	    		ll mid = (high+low)/2;
	    		if(prod2[mid] > res)	high = mid;
	    		else low = mid;
	    	}
	    	
	    	if(prod2[high] <= res)	ans += high+1;
	    	else if(prod2[low] <= res) ans += low+1;
    	}
    	// DEBUG(ans);
    	

    }
    cout<<ans<<endl;
    return 0;

}