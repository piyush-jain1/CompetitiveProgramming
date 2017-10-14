#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define INF (1<<28)
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define PI 3.141592653589793

using namespace std;

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

bool wayToSort(ll i, ll j) { return i > j; }
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{return (a.first > b.first);}
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{return (a.second < b.second);}
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{return a.second>b.second;}

/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<int> adj[50010];
vector<int> d;
int dis[50010];
int n,k;	
void bfs(int r)
{	
	queue<int> q;
	q.push(r);
	dis[r] = 0;
	while(!q.empty())
	{
		int t = q.front();
		if(dis[t] >= k)	break;	
		q.pop();
		for(auto i : adj[t])
		{
			if(dis[i] == -1)
			{
				q.push(i);
				dis[i] = dis[t]+1;
				if(dis[i] == k)	d.pb(i);
			}
		}
	}

}
int main()
{	
	fast_io;
	cin>>n>>k;
	REP(i,n-1)
	{
		int u,v;	cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	set<pair<int,int>> p;
	FOR(i,1,n)
	{	
		fill(dis, dis+n+5, -1);
		d.clear();
		bfs(i);
		// trace(i);
		for(auto u : d)
		{	
			// trace2(i,u);
			p.insert(mp(i,u));
			p.insert(mp(u,i));
		}	
	}
	// for(auto u : p)
	// {
	// 	cout<<u.first<<" "<<u.second<<endl;
	// }
	cout<<p.size()/2<<endl;
	return 0;	
}