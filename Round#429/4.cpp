#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
using namespace std;
///////////////////////////////////////////////////////
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
	fast_io;
	int n,m;	cin>>n>>m;
	int d[n+10];
	FOR(i,1,n)	cin>>d[i];
	bool flag[m+10];
	int degree[n+10];
	fill(degree, degree+n+5, 0);
	std::vector<pair<int,int>> edge;
	FOR(i,1,m)
	{
		int u,v;	cin>>u>>v;
		edge.pb(mp(u,v));
		degree[u]++;
		degree[v]++;
	}
	if(n == 1)
	{	
		if(d[1] == 1)	cout<<-1<<endl;
		else cout<<0<<endl;
		return 0;
	}

	bool modi = true;
	REP(i,m)
	{	
		flag[i] = true;
		if(d[edge[i].first] == -1 and d[edge[i].second] == 0)
		{
			if(degree[edge[i].second]%2 == 1)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 0 and d[edge[i].second] == -1)
		{
			if(degree[edge[i].first]%2 == 1)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 0 and d[edge[i].second] == 1)
		{
			if(degree[edge[i].first]%2 == degree[edge[i].second]%2)
			{	
				// modi = false;
				// break;
			}
			else if(degree[edge[i].first]%2 == 1 and degree[edge[i].second]%2 == 0)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 1 and d[edge[i].second] == 0)
		{
			if(degree[edge[i].first]%2 == degree[edge[i].second]%2)
			{	
				// modi = false;
				// break;
			}
			else if(degree[edge[i].first]%2 == 0 and degree[edge[i].second]%2 == 1)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 1 and d[edge[i].second] == 1)
		{
			if(degree[edge[i].first]%2 != degree[edge[i].second]%2)
			{	
				// modi = false;
				// break;			
			}
			else if(degree[edge[i].first]%2 == 0 and degree[edge[i].second]%2 == 0)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 0 and d[edge[i].second] == 0)
		{
			if(degree[edge[i].first]%2 != degree[edge[i].second]%2)
			{	
				// modi = false;
				// break;			
			}
			else if(degree[edge[i].first]%2 == 1 and degree[edge[i].second]%2 == 1)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == 1 and d[edge[i].second] == -1)
		{
			if(degree[edge[i].first]%2 == 0)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
		else if(d[edge[i].first] == -1 and d[edge[i].second] == 1)
		{
			if(degree[edge[i].second]%2 == 0)
			{	
				flag[i] = false;
				degree[edge[i].first]--;
				degree[edge[i].second]--;
			}
		}
	}
	REP(i,m)
	{	
		if(flag[i] == true)
		{
			if(d[edge[i].first] == -1 and d[edge[i].second] == 0)
			{
				if(degree[edge[i].second]%2 == 1)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 0 and d[edge[i].second] == -1)
			{
				if(degree[edge[i].first]%2 == 1)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 0 and d[edge[i].second] == 1)
			{
				if(degree[edge[i].first]%2 == degree[edge[i].second]%2)
				{	
					// modi = false;
					// break;
				}
				else if(degree[edge[i].first]%2 == 1 and degree[edge[i].second]%2 == 0)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 1 and d[edge[i].second] == 0)
			{
				if(degree[edge[i].first]%2 == degree[edge[i].second]%2)
				{	
					// modi = false;
					// break;
				}
				else if(degree[edge[i].first]%2 == 0 and degree[edge[i].second]%2 == 1)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 1 and d[edge[i].second] == 1)
			{
				if(degree[edge[i].first]%2 != degree[edge[i].second]%2)
				{	
					// modi = false;
					// break;			
				}
				else if(degree[edge[i].first]%2 == 0 and degree[edge[i].second]%2 == 0)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 0 and d[edge[i].second] == 0)
			{
				if(degree[edge[i].first]%2 != degree[edge[i].second]%2)
				{	
					// modi = false;
					// break;			
				}
				else if(degree[edge[i].first]%2 == 1 and degree[edge[i].second]%2 == 1)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == 1 and d[edge[i].second] == -1)
			{
				if(degree[edge[i].first]%2 == 0)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
			else if(d[edge[i].first] == -1 and d[edge[i].second] == 1)
			{
				if(degree[edge[i].second]%2 == 0)
				{	
					flag[i] = false;
					degree[edge[i].first]--;
					degree[edge[i].second]--;
				}
			}
		}
		
	}
	FOR(i,1,n)
	{
		if(d[i] != -1 and degree[i]%2 != d[i])
		{
			modi = false;
			break;
		}
	}
	if(!modi) cout<<-1<<endl;
	else
	{		
		int count = 0;
		REP(i,m)
		{
			if(flag[i] == true)
			{
				count++;
			}
		}
		cout<<count<<endl;
		REP(i,m)
		{
			if(flag[i] == true)
			{
				cout<<i+1<<endl;
			}
		}
	}
	return 0;
}