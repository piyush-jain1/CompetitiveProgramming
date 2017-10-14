#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define fast_io std::ios::sync_with_stdio(false);	cint.tie(NULL); cout.tie(NULL);
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
 
std::vector<pair<ll,ll>> h , v;
int main()
{	
	ll t;	cin>>t;
	while(t--)
	{
		ll n,k,m;	cin>>n>>k>>m;
		ll ln,rn,lk,rk;
		ln = 1;
		rn = n;
		lk = (n-k)/2 +1;
		rk = (n-k)/2 +k;
		REP(i,m)
		{
			ll hx,hy,tx,ty;	cin>>hx>>hy>>tx>>ty;
			v.pb(mp(min(hy,ty),max(hy,ty)));
			h.pb(mp(min(hx,tx),max(hx,tx)));
		}
		ll hsize = h.size();
		ll vsize = v.size();
		sort(h.begin(), h.end());
		sort(v.begin(), v.end());
		// REP(i,vsize)	cout<<v[i].first<<","<<v[i].second<<"  ";
		// cout<<endl;
 
 
		ll counth = 0;
		ll countv = 0;
		ll i,j;
		i = 0;
		ll coverage = lk-1;
		bool hflag = false;
		bool vflag = false;
		bool modi = true;
		bool ok = false;
		while(i < hsize and coverage < rk)
		{	
			j = i;
			ll index = -1; 
			ok  = false;
			ll newcover = coverage;
			while(j < hsize and h[j].first <= coverage+1)
			{
				if(h[j].second >= newcover)
				{	
					ok = true;
					newcover = h[j].second;
					index = j;
				}
				j++;
			}
			// DEBUG(newcover);
			// DEBUG(index);
			coverage = newcover;
			if(!ok )	break;
			counth++;
			i = j;
		}
		if(!ok)	modi = false;
		if(coverage >= rk)	hflag = true;
		
		i = 0;
		coverage = lk-1;
		while(i < vsize and coverage < rk)
		{	
			j = i;
			ll index = -1; 
			ok = false;
			ll newcover = coverage;
			while(j < vsize and v[j].first <= coverage+1)
			{
				if(v[j].second >= newcover)
				{	
					ok = true;
					newcover = v[j].second;
					index = j;
				}
				j++;
			}
			// DEBUG(newcover);
			// DEBUG(index);
			coverage = newcover;
			if(!ok) break;
			if(index > 0)	countv++;
			i = j;
		}
		if(!ok)	modi = false;
		if(coverage >= rk)	vflag = true;
		
		if(!hflag or !vflag or !modi)	cout<<-1<<endl;
		else	cout<<counth+countv<<endl;
		h.clear();
		v.clear();
	}
	return 0;
	
} 