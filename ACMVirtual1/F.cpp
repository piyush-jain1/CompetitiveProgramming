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
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)	{return (a.second < b.second);}
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{return a.second>b.second;}

/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int g[110];
int vote[110] = {0};
int last_voted[110] = {0};
std::vector<pair<int,int>> v;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b)	
{
	if(a.first > b.first)	return true;
	else if(a.first == b.first)	return (last_voted[a.second] < last_voted[b.second]);
	else	return false;
}

int main()
{	
	fast_io;
	int n,k,m,a;	cin>>n>>k>>m>>a;
	REP(i,a)
	{
		cin>>g[i];
		vote[g[i]]++;
		last_voted[g[i]] = i;
	}
	FOR(i,1,n)
	{
		v.pb(mp(vote[i],i));
	}
	sort(all(v),sortinrev);
	// REP(i,v.size())	trace2(v[i].first, v[i].second);
	int pre[n+10], post[n+10];
	pre[0] = 0;
	post[n+1] = 0;
	FOR(i,1,n)	pre[i] = pre[i-1] + v[i-1].first;
	int ans[n+10];
	REP(i,n)
	{	
		bool modi = false;
		// trace2(i+1,k);
		if(i > k-1)
		{	
			// checking for 2
			int req = v[k-1].first+1-v[i].first;
			// trace(req);
			if(req <= m-a)
			{
				ans[v[i].second] = 2;
				modi = true;
			}

		}
		else
		{	
			// trace2(k,n);
			if(k == n and v[i].first > 0)
			{	

				if(1)	
				// else	ans[v[i].second] = 3;
				{
					ans[v[i].second] = 1;
					modi = true;
				}	
			}
			else if(k+1 <= n)
			{	
				int req = 0;
				int f = v[i].first+1;
				// trace(v[k].first);
				FORD(j,k,i+1)
				{	
					// trace2(j,j+k-i);
					req += f-v[j].first;
				}
				if(v[i+1].first == 0)	req = f-v[i+1].first;
				// trace2(req,m-a);
				if(req > m-a)
				{
					if(v[i].first == 0)	ans[v[i].second] = 3;
					else	ans[v[i].second] = 1;
				}
				else
				{	
					ans[v[i].second] = 2;
				}	
			}
			else
			{	
				// cout<<"dvbfchdbv"<<endl;
				if(m==a)	ans[v[i].second] = 3;
				else	ans[v[i].second] = 2;
			}
			modi = true;	
		}
		if(!modi)	ans[v[i].second] = 3;
	}
	FOR(i,1,n)	cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}