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

int main()
{	
	fast_io;
	int t;	cin>>t;
	while(t--)
	{
		int r,c,n;	cin>>r>>c>>n;
		int sx,sy;	cin>>sx>>sy;
		std::vector<pair<int,int>> v;
		REP(i,n)
		{
			int a,b;	cin>>a>>b;
			v.pb(mp(a,b));
		}
		int w[r+5][c+5];
		REP(i,r)
		{
			REP(j,c)	cin>>w[i][j];
		}
		int ans = INT_MIN;
		if(n == 1)
		{	
			// bool flag[15][15];
			// REP(i,11)
			// {
			// 	REP(j,11)	flag[i][j] = true;
			// }
			// flag[sx][sy] = false;
			int dy = v[0].first;
			int dx = v[0].second;
			int point = w[sx][sy];
			ans = max(ans,point);
			FOR(a,0,r*c -1)
			{	
				int k1 = a/c;
				int k2 = a-k1*c;
				if(abs(k1-sx) == dx and abs(k2-sy) == dy)
				{	
					int point1 = point+w[k1][k2];
					ans = max(ans,point1);
				}	
			}
			cout<<max(ans,w[sx][sy])<<endl;
		}
		else if(n == 2)
		{
			FOR(a,0,r*c -1)
			{	
				int point = w[sx][sy];
				ans = max(ans,point);
				int dy = v[0].first;
				int dx = v[0].second;
				int k1 = a/c;
				int k2 = a-k1*c;
				if(abs(k1-sx) == dx and abs(k2-sy) == dy)
				{	
					int point1 = point+w[k1][k2];
					ans = max(ans,point1);
					FOR(b,0,r*c -1)
					{	
						dy = v[1].first;
						dx = v[1].second;
						int k3 = b/c;
						int k4 = b-k3*c;
						if(abs(k3-k1) == dx and abs(k4-k2) == dy)
						{	
							int point2 = point1+w[k3][k4];
							ans = max(ans,point2);	
						}
					}
				}
			}
			cout<<max(ans,w[sx][sy])<<endl;
		}
		else if(n == 3)
		{
			// bool flag[15][15];
			FOR(a,0,r*c -1)
			{	
				int point = w[sx][sy];
				ans = max(ans,point);
				int dy = v[0].first;
				int dx = v[0].second;
				int k1 = a/c;
				int k2 = a-k1*c;
				if(abs(k1-sx) == dx and abs(k2-sy) == dy)
				{
					int point1 = point+w[k1][k2];
					ans = max(ans,point1);
					FOR(b,0,r*c -1)
					{	
						dy = v[1].first;
						dx = v[1].second;
						int k3 = b/c;
						int k4 = b-k3*c;

						if(abs(k3-k1) == dx and abs(k4-k2) == dy)
						{
							int point2 = point1+w[k3][k4];
							ans = max(ans,point2);
							FOR(p,0,r*c -1)
							{	
								dy = v[2].first;
								dx = v[2].second;
								int k5 = p/c;
								int k6 = p-k5*c;
								if(abs(k5-k3) == dx and abs(k6-k4) == dy)
								{	
									int point3 = point2+w[k5][k6];
									ans = max(ans,point3);
								}
							}
							
						}

					}
				}
			}
			cout<<max(ans,w[sx][sy])<<endl;
		}
		else if(n == 4)
		{
			FOR(a,0,r*c -1)
			{	
				int dy = v[0].first;
				int dx = v[0].second;
				int k1 = a/c;
				int k2 = a-k1*c;
				int point = w[sx][sy];
				ans = max(ans,point);
				if(abs(k1-sx) == dx and abs(k2-sy) == dy)
				{	
					int point1 = point+w[k1][k2];
					ans = max(ans,point1);
					FOR(b,0,r*c -1)
					{	
						dy = v[1].first;
						dx = v[1].second;
						int k3 = b/c;
						int k4 = b-k3*c;
						if(abs(k3-k1) == dx and abs(k4-k2) == dy)
						{
							int point2 = point1+w[k3][k4];
							ans = max(ans,point2);
							FOR(p,0,r*c -1)
							{	
								dy = v[2].first;
								dx = v[2].second;
								int k5 = p/c;
								int k6 = p-k5*c;
								if(abs(k5-k3) == dx and abs(k6-k4) == dy)
								{
									int point3 = point2+w[k5][k6];
									ans = max(ans,point3);
									FOR(q,0,r*c -1)
									{	
										dy = v[3].first;
										dx = v[3].second;
										int k7 = q/c;
										int k8 = q-k7*c;
										if(abs(k7-k5) == dx and abs(k8-k6) == dy)
										{
											int point4 = point3+w[k7][k8];
											ans = max(ans,point4);
										}
									}
								}
							}
							
						}

					}
				}
			}
			cout<<max(ans,w[sx][sy])<<endl;
		}
		else	cout<<max(ans,w[sx][sy])<<endl;
	}
	
}