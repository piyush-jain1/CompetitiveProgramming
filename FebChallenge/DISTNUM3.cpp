// Segment Tree with Lazy Implementation
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
#define MAX 100005
/*si -> index of current node in segment tree
    s and e -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */

set<ll> * entry = new set<ll>[2*MAX - 1];
std::map<pair<ll,ll>,vector<ll>> path;
std::vector<ll> tempvec;
void dfs_visit(std::vector<ll> adj[], ll i, bool flag[])
{	
	flag[i] = true;
	for(auto it = adj[i].begin(); it != adj[i].end(); ++it)
	{	
		if(!flag[*it])
		{	
			cout<<*it<<" "<<endl;
			tempvec.pb(*it);
			dfs_visit(adj, *it, flag);
		}
	}
}
void dfs(std::vector<ll> adj[], ll n)
{
	FOR(i,1,1)
	{	
		bool flag[n+10];
		FOR(j,1,n)
		{
			flag[j] = false;
		}
		tempvec.clear();
		dfs_visit(adj, i, flag);
		std::vector<ll> v;
		v.pb(i);
		for(auto j = tempvec.begin(); j != tempvec.end(); ++j)
		{	
			v.pb(tempvec[*j]);
			path[mp(i,tempvec[*j])]  = v;
		}
		v.clear();
	}
}
set<ll> buildEntry(ll a[],ll s, ll e,ll si)
{
	if(s==e)
	{	
		//DEBUG(s);
		entry[si].insert(a[s]);
		return entry[si];
	}
	ll mid = s + (e-s)/2;
	set<ll> left = buildEntry(a,s,mid,2*si + 1);
	set<ll> right = buildEntry(a,mid+1,e,2*si + 2);
	entry[si].insert(left.begin(),left.end());
	entry[si].insert(right.begin(),right.end());
	//cout<<entry[si].size()<<endl;
	return entry[si];
}
ll * constructTree(ll a[], ll n)
{
	ll h = (ll)(ceil(log2(n)));

	ll max_size = 2*(ll)pow(2,h) - 1;

	ll *st = new ll[max_size];
	buildEntry(a, 0 ,n-1, 0);
	REP(i,max_size)
	{
		st[i] = entry[i].size();
	}

	return st;

}

void updateValueUtil(ll a[],ll *st, ll ss, ll se, ll u, ll old, ll si)
{
    // Base Case: If the input index lies outside the range of 
    // this segment
    if (u < ss || u > se)
        return;
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children
    entry[si].erase(old);
    entry[si].insert(a[u]);
    st[si] = entry[si].size();
    if (se != ss)
    {
        ll mid = ss + (se - ss)/2;
        updateValueUtil(a, st, ss, mid, u, old, 2*si + 1);
        updateValueUtil(a, st, mid+1, se, u, old, 2*si + 2);
    }
}
 
void updateValue(ll a[], ll *st, ll n, ll u, ll v)
{
    // Check for erroneous input index
    if (u < 0 || u > n-1)
    {
        printf("Invalid Input");
        return;
    }

 	ll old = a[u];
    // Update the value in array
    a[u] = v;
 
    // Update the values of nodes in segment tree
    updateValueUtil(a, st, 0, n-1, u, old, 0);
}

ll getVal(ll *st, ll ss, ll se, ll qs, ll qe, ll si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    ll mid = ss + (se -  ss)/2;
    return getVal(st, ss, mid, qs, qe, 2*si+1) +
           getVal(st, mid+1, se, qs, qe, 2*si+2);
}

int main()
{
    ll n,q;
	cin>>n>>q;
	ll a[n+10];
	FOR(i,0,n-1)
	{
		cin>>a[i];
	}
	ll h = (ll)(ceil(log2(n)));
	ll max_size = 2*(ll)pow(2,h) - 1;
	ll *st = (ll *)malloc(max_size * sizeof(ll));
	ll *lazy = (ll *)malloc(max_size * sizeof(ll));
	REP(i,max_size)
	{
		st[i] = 0;
		lazy[i] = 0;
	}
	st = constructTree(a,n);
	// REP(i,max_size)
	// {
	// 	for(auto it = entry[i].begin(); it != entry[i].end(); ++it)
	// 	{
	// 		cout<<*it<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// REP(i,max_size)
	// {
	// 	cout<<st[i]<<endl;
	// }
	std::vector<ll> adj[n+10];

	REP(i,n-1)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(adj, n);
	// FOR(i,1,n)
	// {
	// 	for(auto it = path[mp(1,i)].begin(); it != path[mp(1,i)].end(); ++it )
	// 	{
	// 		cout<<*it<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// REP(i,1)
	// {
	// 	ll t,u,v;
	// 	cin>>t>>u>>v;
	// 	u -= 1;
	// 	v -= 1;
	// 	DEBUG(i);
	// 	if(t == 1)
	// 	{
	// 		cout<<getVal(st,0,n-1,u,v,0)<<endl;
	// 	}
	// 	else if(t == 2)
	// 	{
	// 		updateValue(a,st,n,u,v);
	// 	}
	// }


	return 0;



}
