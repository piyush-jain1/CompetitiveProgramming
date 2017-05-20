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
	std::ios::sync_with_stdio(false);
	ll b1,q,l,m;		cin>>b1>>q>>l>>m;
	ll a[m+10],c[m+10];
	bool zero = false;
	bool start = false;
	bool neg_start = false;
	REP(i,m)
	{
		cin>>a[i];
		c[i] = a[i];
		if(a[i] == 0)	zero = true;
		if(a[i] == b1)	start = true;
		if(a[i] == (-1)*b1) neg_start = true;
	}
	if(abs(b1) > l)
	{
		cout<<0<<endl;
		return 0;
	}
	if(l < 0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(l == 0)
	{
		if(b1 == 0)
		{
			if(!start)
			{
				cout<<"inf"<<endl;
				return 0;
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		else
		{
			cout<<0<<endl;
			return 0;
		}
	}
	if(q == 0)
	{
		if(!start)
		{
			if(abs(b1) <= l && zero==false)
			{
				cout<<"inf"<<endl;
				return 0;
			}

			else if(abs(b1) <= l && zero==true)
			{
				cout<<1<<endl;
				return 0;
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		else
		{
			if(zero == false)
			{
				cout<<"inf"<<endl;
				return 0;
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
			
		}
	}
	if(q == 1)
	{	
		if(b1 != 0)
		{	
			// DEBUG(b1);
			if(!start)
			{	
				if(l >= abs(b1))
				{	
					// DEBUG(l);
					cout<<"inf"<<endl;
					return 0;
				}
				else
				{
					cout<<0<<endl;
					return 0;
				}
				
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
	}
	if(q == -1)
	{	
		if(b1 != 0)
		{	
			// DEBUG(b1);
			if(!start || !neg_start)
			{	
				if(l >= abs(b1))
				{	
					// DEBUG(l);
					cout<<"inf"<<endl;
					return 0;
				}
				else
				{
					cout<<0<<endl;
					return 0;
				}
				
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
	}
	if(b1 == 0)
	{
		if(zero== true)
		{
			cout<<0<<endl;
			return 0;
		}
		else
		{	
			if(l >= 0)
			{
				cout<<"inf"<<endl;
				return 0;
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
			
		}
	}
	sort(a,a+m);
	ll count = 0;
	if(!start)	
	{	
		if(abs(b1) <= l)
		{
			count = 1; 
		}
		else
		{	
			// cout<<"gsg"<<endl;
			count = 0;
		}
	}

	ll  i = 0;	
	ll b = b1;
	
	if(q > 0 && b1 > 0)
	{	
		while(b*q <= l)
		{	
			while(b*q > a[i] && i<m)
			{
				i++;
			}
			if(i==m)	i-=1;
			if(b*q != a[i])	count++;
			b *= q;
		} 
		cout<<count<<endl;
		return 0;
	}
	sort(c,c+m,wayToSort);
	b = b1;
	i = 0;
	if(q > 0 && b1 < 0)
	{
		while(abs(b*q) <= l)
		{	
			while(b*q < c[i] && i<m)
			{
				i++;
			}
			if(i==m)	i-=1;
			if(b*q != c[i])	count++;
			b *= q;
		} 
		cout<<count<<endl;
		return 0;
	}
	b = b1;
	i = 0;
	// DEBUG(q);
	if(q < 0)
	{	
	
		if(b1 > 0)
		{	
			b = b1;
			i = 0;
			if(abs(b*q) <= l)
			{	
				while(abs(b*q*q) <= l)
				{	
					// DEBUG(b);
					while(b*q*q > a[i] && i<m)
					{
						i++;
					}
					if(i == m)	i-= 1;
					if(b*q*q != a[i])	count++;
					b *= (q*q);
				}
				b = b1;
				i = 0;
			// cout<<endl;
			
				// DEBUG(b);
				while(b*q < c[i] && i<m)
				{
					i++;
				}
				if(i == m)  i-= 1;
				if(b*q != c[i])	count++;
				b *= (q);
				while(abs(b*q*q) <= l)
				{	
					// DEBUG(b);
					while(b*q*q < c[i] && i<m)
					{
						i++;
					}
					if(i == m)  i-= 1;
					if(b*q*q != c[i])	count++;
					b *= (q*q);
				}
				
			}
			

		}
		if(b1 < 0)
		{
			b = b1;
			i = 0;
			//DEBUG(b*q);
			if(abs(b*q) <= l)
			{	

				while(b*q > a[i] && i<m)
				{	
					// DEBUG(i);
					i++;
				}
				if(i==m)	i-=1;
				if(b*q != a[i])	count++;
				b *= (q);
				while(abs(b*q*q) <= l)
				{
					while(b*q*q > a[i] && i<m)
					{	
						// DEBUG(i);
						i++;
					}
					if(i==m)	i-=1;
					if(b*q*q != a[i])	count++;
					b *= (q*q);
				}
				b = b1;
				i = 0;
				while(abs(b*q*q) <= l)
				{
					while(b*q*q < c[i] && i<m)
					{	
						// DEBUG(i);
						i++;
					}
					if(i == m)	i-=1;
					if(b*q*q != c[i])	count++;
					b *= (q*q);
				}
				
			}
			
			
		}
		cout<<count<<endl;
		return 0;
	}
	return 0;

}