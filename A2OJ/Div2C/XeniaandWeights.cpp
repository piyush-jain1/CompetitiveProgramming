#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define tlll tuple<ll,ll,ll>
#define mt make_tuple
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
#define mod 1000000007
/////////////////////////////////////////////////////////////////////////////////////////////////////////


vector<ll> adj[1000010];
bool visited[1000010] = {false};
ll pred[1000010];
bool found = false;
map<tuple<ll,ll,ll>, ll> tti;
map<ll, tuple<ll,ll,ll>> itt;
ll final_node,m;
void dfs(ll curr_index)
{
	visited[curr_index] = true;
	tlll curr = itt[curr_index];

	if(!found and get<2>(curr) == m)
	{
		final_node = curr_index;
		found = true;
	}

	for(ll u: adj[curr_index])
	{
		if(!visited[u])
		{
			pred[u] = curr_index;
			dfs(u);
		}
	}
}
int main()
{
	string s;	cin>>s;
	cin>>m;
	std::vector<ll> v;
	REP(i,10)
	{
		if(s[i] == '1')	v.pb(i+1);
	}
	
	
	tuple<ll,ll,ll> root = mt(0,0,0);
	tti[root] = 0;
	itt[0] = root;
	ll index = 1;
	queue<tlll> Q;
	for(ll u : v)
	{
		tlll temp = mt(u,u,1);
		Q.push(temp);
		tti[temp] = index;
		itt[index] = temp;
		adj[0].pb(index);
		index++;
	}

	while(!Q.empty())
	{
		tlll curr = Q.front();
		Q.pop();

		ll bal = get<0>(curr);
		ll pre_weight = get<1>(curr);
		ll count = get<2>(curr);
		ll curr_index = tti[curr];

		if(count == m)	continue;
		bool flag = true;
		if(bal < 0)	flag = false;
		for(ll u : v)
		{	
			tlll temp;
			if(u != pre_weight)
			{
				if(flag and bal-u < 0)
				{
					temp = mt(bal-u, u , count+1);
					if(tti[temp])	continue;
					tti[temp] = index;
					itt[index] = temp;
					adj[curr_index].pb(index);
					Q.push(temp);
					index++;
				}
				else if(!flag and bal+u>0)
				{
					temp = mt(bal+u,u, count+1);
					if(tti[temp])	continue;
					tti[temp] = index;
					itt[index] = temp;
					adj[curr_index].pb(index);
					Q.push(temp);
					index++;
				}
			}
		}
	}
	dfs(0);
	if(!found)	
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		ll temp = final_node;
		vector<ll> ans;
		cout<<"YES"<<endl;
		while(temp != 0)
		{
			ans.pb(get<1>(itt[temp]));
			temp = pred[temp];
		}
		reverse(ans.begin(), ans.end());
		for(ll u : ans)	cout<<u<<" ";
		cout<<endl;
	}
	return 0;
}