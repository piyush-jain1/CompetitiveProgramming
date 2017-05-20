#include <bits/stdc++.h>
#include <math.h>
#include <set>
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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void setBit(int & n, int b) { n |= two(b); }
inline void unsetBit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(int x,int y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
/////////////////////////////////////////////////////////////////////

int main()
{	
	std::ios::sync_with_stdio(false);

	ll n;
	cin>>n;
	std::vector<pair<ll,ll>> edge;
	REP(i,n-1)
	{
		ll u,v;
		cin>>u>>v;
		edge.pb(mp(u,v));
		edge.pb(mp(v,u));
	}
	std::vector<ll> c[n+10];
	ll maxc = 0;
	std::set<ll> diffc;
	FOR(i,1,n)
	{
		ll temp;
		cin>>temp;
		diffc.insert(temp);
		if(temp>maxc)
		{
			maxc = temp;
		}

		c[temp].pb(i);
	}
	//cout<<diffc.size()<<endl;
	if(diffc.size() > 3)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(diffc.size() == 1)
	{
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		return 0;
	}
	ll count = 0;
	ll index = 0;
	if(diffc.size() == 2)
	{
		FOR(i,1,maxc)
		{
			if(c[i].size() == 1)
			{
				count++;
				index = i;
			}
		}
		if(count == 1)
		{
			cout<<"YES"<<endl;
			cout<<c[index][0]<<endl;
			return 0;
		}
	}

	std::vector<ll> indices;
	if(diffc.size() == 3)
	{	
		count = 0;
		FOR(i,1,maxc)
		{
			if(c[i].size() == 1)
			{
				count++;
				indices.pb(i);
			}
		}
		
		REP(k,count)
		{
			ll counter = 0;
			FOR(j,1,maxc)
			{	
				if(j != indices[k] && c[j].empty() == false)
				{	
					FOR(i,1,n)
					{
						if(edge[i].first == c[indices[k]][0])
						{
							if(find(c[j].begin(),c[j].end(),edge[i].second) != c[j].end())
							{
								counter++;
								break;
							}
						}
					}
					
				}
				if(counter == 2)
				{
					break;
				}

			}
			if(counter == 2)
			{
				cout<<"YES"<<endl<<c[indices[k]][0]<<endl;
				return 0;
			}
		}
	
	}
	cout<<"NO"<<endl;
	return 0;
	
}