#include <bits/stdc++.h>
#include <math.h>
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

ll timer = 0;
ll k = 0;

void DFS_Visit(vector<ll> adj[],ll i,ll dis[],ll fin[],bool flag[],vector<ll> vec[])
{
	flag[i] = true;
	timer = timer +1;
	dis[i] = timer;
	auto it = adj[i].begin();
	while(it != adj[i].end())
	{
		if(!flag[*it])
		{	
			DFS_Visit(adj,*it,dis,fin,flag,vec);
		}
		++it;
	}
	timer = timer + 1;
	fin[i] = timer;
	vec[k].pb(i);
}
int main()
{	
	std::ios::sync_with_stdio(false);

	ll q;
	cin>>q;
	while(q--)
	{	
		k = 0;
		ll n,m;
		ll d;
		cin>>n>>m;
		std::vector<ll> adj[n+10];
		ll dis[n+10];
		ll fin[n+10];
		bool flag[n+10];
		std::vector<ll> v;
		FOR(i,1,n)
		{
			cin>>d;
			REP(j,d)
			{	
				ll temp;
				cin>>temp;
				adj[i].pb(temp);
			}
			flag[i] = false;
			dis[i] = 0;
			fin[i] = 0;
		}
		REP(i,m)
		{	
			ll temp;
			cin>>temp;
			v.pb(temp);
		}
		std::vector<ll> vec[n+10];
		ll size = 0;
		for(auto iter = v.begin() ; iter != v.end() ; ++iter)
		{	
			if(!flag[*iter])
			{
				DFS_Visit(adj,*iter,dis,fin,flag,vec);
			}
			size += vec[k].size();
			k++;
		}
		// for(auto it = vec[1].begin() ; it != vec[1].end() ; ++it)
		// {
		// 	cout<<*it<<" ";
		// }
		cout<<size<<endl;
		map<ll,ll> mapping;
		ll r = 0;
		std::vector<ll> firse;
		REP(i,k)
		{
			if(!vec[i].empty())
			{
				mapping[*vec[i].begin()] = i;
				firse.pb(*vec[i].begin());
			}
		}
		sort(firse.begin(),firse.end());
		for(auto it = firse.begin() ; it != firse.end() ; ++it)
		{	

			for(auto j = vec[mapping[*it]].begin() ; j != vec[mapping[*it]].end() ; ++j)
			{
				cout<<*j<<" ";
			}
		}
		cout<<endl;

		// FOR(i,1,n)
		// {
		// 	cout<<"d["<<i<<"] : "<<dis[i]<<"  "<<"f["<<i<<"] : "<<fin[i]<<endl;
		// }
	}
	return 0;


}
