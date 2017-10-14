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
	int n,s;	cin>>n>>s;
	std::vector<pair<int,int>> d1, d2;
	int a[n+10], b[n+10], q[n+10];
	ll tot = 0;
	int t1 = 0, t2 = 0, t3 = 0;
	ll sum1=0, sum2=0, sum3=0;
	REP(i,n)
	{
		cin>>q[i]>>a[i]>>b[i];
		tot += q[i];
		if(a[i] > b[i])
		{
			t1 += q[i];
			sum1 += a[i]*q[i];
			d1.pb(mp(i,a[i]-b[i]));
		}
		else if(a[i] < b[i])
		{
			t2 += q[i];
			sum2 += b[i]*q[i];
			d2.pb(mp(i,b[i]-a[i]));
		}
		else
		{
			t3 += q[i];
			sum3 += a[i]*q[i];
			d1.pb(mp(i,a[i]-b[i]));
			d2.pb(mp(i,b[i]-a[i]));
		}
	}
	// trace3(t1,t2,t3);
	sort(d1.begin(), d1.end(), sortbysec);
	sort(d2.begin(), d2.end(), sortbysec);
	int p = (int)ceil((double)tot/(double)s);
	// trace(p);
	if(p >= (int)ceil((double)t1/(double)s) + (int)ceil((double)t2/(double)s) +(int)ceil((double)t3/(double)s))
	{
		cout<<sum1+sum2+sum3<<endl;
		return 0;
	}
	int dec1 = (t1+t3)%s;
	int dec2 = (t2+t3)%s;
	// trace2(dec1, dec2);
	ll tot1,tot2;
	ll ans1 = sum1+sum3;
	ll ans2 = sum2;
	// trace2(sum1,sum2);
	int i = 0;

	// trace(d1[i].first);
	while(dec1 > 0)
	{			
		if(q[d1[i].first] >= dec1)
		{
			ans1 -= dec1*a[d1[i].first];
			ans2 += dec1*b[d1[i].first];
			dec1 = 0;
		}
		else
		{
			ans1 -= q[d1[i].first]*a[d1[i].first];
			ans2 += q[d1[i].first]*b[d1[i].first];
			dec1 -= q[d1[i].first];
		}
		i++;
	}	
	// trace2(ans1,ans2);
	tot1 = ans1+ans2;
	ans1 = sum1;
	ans2 = sum2+sum3;
	i = 0;
	while(dec2 > 0)
	{	
		// trace(d2[i].first);
		if(q[d2[i].first] >= dec2)
		{
			ans2 -= dec2*b[d2[i].first];
			ans1 += dec2*a[d2[i].first];
			dec2 = 0;
		}
		else
		{
			ans2 -= q[d2[i].first]*b[d2[i].first];
			ans1 += q[d2[i].first]*a[d2[i].first];
			dec2 -= q[d2[i].first];
		}
		i++;
	}
	// trace2(ans1,ans2);
	tot2 = ans1+ans2;
	// trace2(tot1,tot2);
	cout<<max(tot1,tot2)<<endl;
	return 0;
}