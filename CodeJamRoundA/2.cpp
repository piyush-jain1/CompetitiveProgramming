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
ll n,r,o,y,g,b,v;
char mincol1, mincol2;
void findmin()
{	
	if(b >= r)
	{
		if(b >= y)
		{
			mincol1 = 'b';
			if(r >= y)
			{
				mincol2 = 'r';
			}
			else
			{
				mincol2 = 'y';
			}

		}
		else
		{	
			mincol1 = 'y';
			mincol2 = 'b';
		}
	}
	else
	{
		if(r >= y)
		{
			mincol1 = 'r';
			if(b >= y)
			{
				mincol2 = 'b';
			}
			else
			{
				mincol2 = 'y';
			}
		}
		else
		{
			mincol1 = 'y';
			mincol2 = 'r';
		}
	}
}
int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll test;	cin>>test;
	FOR(t,1,test)
	{	
		cin>>n>>r>>o>>y>>g>>b>>v;
		b -= o;
		r -= g;
		y -= v;
		
		ll max1,max2,max3;
		if(b >= r)
		{
			if(b >= y)
			{
				max1 = b;
				if(r >= y)
				{
					max2 = r;
					max3 = y;
				}
				else
				{
					max2 = y;
					max3 = r;
				}
			}
			else
			{	
				max1 = y;
				max2 = b;
				max3 = r;
			}
		}
		else
		{
			if(r >= y)
			{
				max1 = r;
				if(y >= b)
				{
					max2 = y;
					max3 = b;
				}
				else
				{
					max2 = b;
					max3 = y;
				}
			}
			else
			{
				max1 = y;
				max2 = r;
				max3 = b;
			}

		}
		if(max1 > max2+max3)	cout<<"IMPOSSIBLE"<<endl;
		else
		{
			
			ll index = 0;
			bool flag[5] = {false};
			char prev = 'Z';
			while(index < n)
			{
				findmin();
				ll counter = 0;
				if(mincol1 == 'b' && mincol2 == 'r')
				{	
					counter = 0;
					if(flag[1] == false)
					{
						counter = 0;
						while(counter < o)	
						{
							cout<<"BO";
							counter++;
							b--; o--;
							index+=2;
						}
						flag[1] = true;
					}
					cout<<"B";
					b--;
					index += 1;
					counter = 0;
					if(flag[2] == false)
					{
						counter = 0;
						while(counter < g)	
						{
							cout<<"RG";
							r--; g--;
							counter++;
							index+=2;
						}
						flag[2] = true;
					}
					cout<<"R";
					r--;
					index += 1;
				}
				else if(mincol1 == 'r' && mincol2 == 'y')
				{	
					counter = 0;
					if(flag[2] == false)
					{
						counter = 0;
						while(counter < g)	
						{
							cout<<"RG";
							r--; g--;
							counter++;
							index+=2;
						}
						flag[2] = true;
					}
					cout<<"R";
					r--;
					index += 1;
					counter = 0;
					if(flag[3] == false)
					{
						counter = 0;
						while(counter < v)	
						{
							cout<<"YV";
							y--; v--;
							counter++;
							index+=2;
						}
						flag[3] = true;
					}
					cout<<"Y";
					y--;
					index += 1;
				}
				else if(mincol1 == 'y' && mincol2 == 'b')
				{	
					counter = 0;
					if(flag[3] == false)
					{
						counter = 0;
						while(counter < v)	
						{
							cout<<"YV";
							y--; v--;
							counter++;
							index+=2;
						}
						flag[3] = true;
					}
					cout<<"Y";
					y--;
					index += 1;
					counter = 0;
					if(flag[1] == false)
					{
						counter = 0;
						while(counter < o)	
						{
							cout<<"BO";
							b--; o--;
							counter++;
							index+=2;	
						}
						flag[1] = true;
					}
					cout<<"B";
					b--;
					index += 1;
				}	
				else if(mincol1 == 'r' && mincol2 == 'b')
				{
					counter = 0;
					if(flag[2] == false)
					{
						counter = 0;
						while(counter < g)	
						{
							cout<<"RG";
							r--; g--;
							counter++;
							index+=2;
						}
						flag[2] = true;
					}
					cout<<"R";
					r--;
					index += 1;
					counter = 0;
					if(flag[1] == false)
					{
						counter = 0;
						while(counter < o)	
						{
							cout<<"BO";
							b--; o--;
							counter++;
							index+=2;
						}
						flag[1] = true;
					}
					cout<<"B";
					b--;
					index += 1;
				}	
				else if(mincol1 == 'y' && mincol2 == 'r')
				{
					counter = 0;
					if(flag[3] == false)
					{
						counter = 0;
						while(counter < v)	
						{
							cout<<"YV";
							y--; v--;
							counter++;
							index+=2;
						}
						flag[3] = true;
					}
					cout<<"Y";
					y--;
					index += 1;
					counter = 0;
					if(flag[2] == false)
					{
						counter = 0;
						while(counter < g)	
						{
							cout<<"RG";
							r--; g--;
							counter++;
							index+=2;
						}
						flag[2] = true;
					}
					cout<<"R";
					r--;
					index += 1;
				}	
				else if(mincol1 == 'b' && mincol2 == 'y')
				{
					counter = 0;
					if(flag[1] == false)
					{
						counter = 0;
						while(counter < o)	
						{
							cout<<"BO";
							b--; o--;
							counter++;
							index+=2;
						}
						flag[1] = true;
					}
					cout<<"B";
					b--;
					index += 1;
					counter = 0;
					if(flag[3] == false)
					{
						counter = 0;
						while(counter < v)	
						{
							cout<<"YV";
							y--; v--;
							counter++;
							index+=2;
						}
						flag[3] = true;
					}
					cout<<"Y";
					y--;
					index += 1;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}