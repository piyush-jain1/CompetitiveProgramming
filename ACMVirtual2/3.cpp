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

int pn[110]={0}, sn[110]={0};
int pm[110]={0}, sm[110]={0};
int a[110], b[110];

int main()
{	
	fast_io;
	int n,m;	cin>>n>>m;
	REP(i,n)
	{	
		int temp;	cin>>temp;
		a[i] = temp;
		FOR(j,1,3)
		{	
			// trace(temp%10);
			sn[i] += temp%10;
			temp /= 10;
		}
		// cout<<"-----------"<<endl;
		FOR(j,1,3)
		{	
			// trace(temp%10);
			pn[i] += temp%10;
			temp /= 10;
		}
	}
	// debug_array(pn,n);
	// debug_array(sn,n);
	REP(i,m)
	{	
		int temp;	cin>>temp;
		b[i] = temp;
		FOR(j,1,3)
		{
			sm[i] += temp%10;
			temp /= 10;
		}
		FOR(j,1,3)
		{
			pm[i] += temp%10;
			temp /= 10;
		}
	}
	// debug_array(pm,m);
	// debug_array(sm,m);
	ll cnt = 0;
	std::vector<pair<int,int>> at, ta;
	ll garbage = 50;
	bool modi1 = false, modi2 = false;
	vector<int> atob[n+10], btoa[m+10];
	REP(i,n)
	{
		REP(j,m)
		{	
			modi1 = false;
			modi2 = false;
			// trace2(a[i],b[j]);
			// trace2(pn[i],sm[j]);
			if(pn[i] == sm[j])
			{
				// cnt++;
				// cout<<"AT"<<endl;
				// at.pb(mp(i,j));
				modi1 = true;

			}
			// trace2(b[j],a[i]);
			// trace2(pm[j],sn[i]);
			if(sn[i] == pm[j])
			{
				// cnt++;
				// cout<<"TA"<<endl;
				// ta.pb(mp(j,i));
				modi2 = true;
			}
			if(modi1 or modi2)
			{	
				cnt++;
				// pn[i] = garbage;
				// garbage++;
				// sn[i] = garbage;
				// garbage++;
				// sm[j] = garbage;
				// garbage++;
				// pm[j] = garbage;
				// garbage++;
				atob[i].pb(j);
			}
		}
	}
	// REP(i,n)
	// {
	// 	for(auto u : atob[i])	cout<<u<<" ";
	// 	cout<<endl;
	// }

	// cout<<cnt<<endl;
	// REP(i,at.size())
	// {
	// 	cout<<"AT "<<a[at[i].first]<<" "<<b[at[i].second]<<endl;
	// }
	// REP(i,ta.size())
	// {
	// 	cout<<"TA "<<b[ta[i].first]<<" "<<a[ta[i].second]<<endl;
	// }
	return 0;
}