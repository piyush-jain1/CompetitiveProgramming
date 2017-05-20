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

int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	ll p[n+10],a[n+10],b[n+10];
	FOR(i,1,n)	cin>>p[i];
	FOR(i,1,n)	cin>>a[i];
	FOR(i,1,n)	cin>>b[i];
	vector<pair<ll,ll>> fir, sec, third;
	ll index1=0, index2=0, index3=0;
	bool flag[n+10] = {false};
	FOR(i,1,n)
	{
		if(a[i] == 1 || b[i] == 1)	fir.pb(mp(p[i],i));
		if(a[i] == 2 || b[i] == 2)	sec.pb(mp(p[i],i));
		if(a[i] == 3 || b[i] == 3)	third.pb(mp(p[i],i));
	}
	index1 = fir.size();
	index2 = sec.size();
	index3 = third.size();
	sort(fir.begin(),fir.end());
	sort(sec.begin(), sec.end());
	sort(third.begin(), third.end());
	ll i1=0,i2=0,i3=0;
	ll m;	cin>>m;
	// DEBUG(index1);
	// DEBUG(index2);
	// DEBUG(index3);
	REP(i,m)
	{	
		ll q;
		cin>>q;
		// DEBUG(q);
		if(q == 1)
		{	
			if(i1 == index1)
			{
				cout<<"-1"<<" ";
			}
			else
			{
				while(i1 < index1)
				{
					if(!flag[fir[i1].second])	break;
					i1++;
				}	
				if(i1 < index1)
				{
					cout<<fir[i1].first<<" ";
					flag[fir[i1].second] = true;
					i1++;
				}
				else	cout<<-1<<" ";
			}
			
		}
		else if(q == 2)
		{	
			if(i2 == index2)
			{
				cout<<-1<<" ";
			}
			else
			{
				while(i2 < index2)
				{
					if(!flag[sec[i2].second])	break;
					i2++;
				}	
				if(i2 < index2)
				{
					cout<<sec[i2].first<<" ";
					flag[sec[i2].second] = true;
					i2++;
				}
				else	cout<<-1<<" ";
			}
			
		}
		else if(q == 3)
		{	
			// cout<<"dfhdf"<<endl;
			if(i3 == index3)
			{
				cout<<-1<<" ";
			}
			else
			{
				while(i3 < index3)	
				{
					if(!flag[third[i3].second]) break;
					i3++;
				}
				if(i3 < index3)
				{
					cout<<third[i3].first<<" ";
					flag[third[i3].second] = true;
					i3++;
				}
				else	cout<<-1<<" ";
			}	
		}
	}
	cout<<endl;
	return 0;
	
}