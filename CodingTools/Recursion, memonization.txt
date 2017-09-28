#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#define pb push_back
#define mp make_pair
#define f first
#define s second
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
#define MAX INT_MAX
/////////////////////////////////////////////////////////////////////

ll s[5010],d[5010];
ll dist[110][110];
map< pair<ll, pair<ll,bool> > ,ll > memo;

ll find_cost(ll loaded, ll family_num, ll k,bool flag)
{	
	if(memo.find(mp(loaded,mp(family_num,flag))) != memo.end()) 
	{
		return memo[mp(loaded,mp(family_num,flag))];
	}
	if(family_num == k+1 && loaded == 0)
	{
		return 0;
	}

	if(family_num == k && loaded == 1)
	{	
		ll temp;
		if(flag == false)
		{	
			temp = dist[s[family_num]][d[family_num]];
			memo[mp(loaded,mp(family_num,flag))] = temp;
			return temp;
		}
		else
		{	
			temp = dist[d[family_num-1]][d[family_num]];
			memo[mp(loaded,mp(family_num,flag))] = temp;
			return temp;
		}
		
	}
	if(loaded == 0)
	{		
		flag = false;
		ll temp =  (dist[d[family_num-1]][s[family_num]] + find_cost(loaded+1,family_num,k,flag));
		memo[mp(loaded,mp(family_num,flag))] = temp;
		return temp;
	}
	else if(loaded == 1)
	{	
		ll light1;
		ll light2;
		if(flag == false)
		{
			light1 =  (dist[s[family_num]][d[family_num]] + find_cost(loaded-1,family_num+1,k,flag));
			light2 = (dist[s[family_num]][s[family_num+1]] + find_cost(loaded+1,family_num+1,k,flag));
		}
		else
		{
			light1 = (dist[d[family_num-1]][d[family_num]]) + find_cost(loaded-1,family_num+1,k,flag);
			light2 = (dist[d[family_num-1]][s[family_num+1]] + find_cost(loaded+1,family_num+1,k,flag));
		}
		ll temp = min(light1,light2);
		memo[mp(loaded,mp(family_num,flag))] = temp;
		return temp;

	}
	else if(loaded == 2)
	{
		flag = true;
		ll temp = dist[s[family_num]][d[family_num-1]] + find_cost(loaded-1,family_num,k,flag);
		memo[mp(loaded,mp(family_num,flag))] = temp;
		return temp;
	}
	return 0;
}

int main()
{	
	std::ios::sync_with_stdio(false);

	ll t;
	cin>>t;
	FOR(r,1,t)
	{	
		ll n,m,k;
		cin>>n>>m>>k;
		REP(i,110)
		{
			REP(j,110)
			{
				if(i == j)
				{
					dist[i][j] = 0;
				}
				else
				{
					dist[i][j] = MAX;
				}
			}
		}
		FOR(i,1,m)
		{	
			ll a,b,g;
			cin>>a>>b>>g;
			if(dist[a][b] > g)
			{
				dist[a][b] = g;
				dist[b][a] = g;
			}
		}
		FOR(p,1,n)
		{
			FOR(i,1,n)
			{
				FOR(j,1,n)
				{
					if((dist[i][p] + dist[p][j]) < dist[i][j])
					{
						dist[i][j] = (dist[i][p] + dist[p][j]);
					}
				}
			}
		}
		FOR(i,1,k)
		{
			cin>>s[i]>>d[i];
		}
		bool another_flag = false;
		FOR(i,1,k)
		{
			if(dist[s[i]][d[i]] == MAX)
			{
				cout<<"Case #"<<r<<": "<<-1<<endl;
				another_flag = true;
				break;
			}
		}

		if(!another_flag)
		{
			FOR(i,1,k-1)
			{
				if(dist[s[i]][s[i+1]] == MAX && dist[s[i]][d[i+1]] == MAX && dist[d[i]][s[i+1]] == MAX && dist[d[i]][d[i+1]] == MAX)
				{
					cout<<"Case #"<<r<<": "<<-1<<endl;
					another_flag = true;
					break;
				}
			}
		}

		if(!another_flag)
		{
			ll family_num = 1;
			ll cost = dist[1][s[1]];
			ll loaded = 1;
			bool flag = false;
			ll mycost = cost+find_cost(loaded,family_num,k,flag);
			cout<<"Case #"<<r<<": "<<mycost<<endl;
		}
		memo.clear();
	}
	return 0;
}