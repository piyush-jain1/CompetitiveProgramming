#include <bits/stdc++.h>
using namespace std; 
 
#define ll long long int
#define ull unsigned long long int
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define V vector<ll>
#define trace(x) cout << '>' << #x << ':' << x << endl;
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << endl;
#define trace3(x,y,z) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << endl;
#define trace4(x,y,z,w) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y <<" | " << #z << ':' << z << " | " << #w << ':' << w << endl;
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());

int main()
{
	fast_io;
	ll n,k;
	cin>>n>>k;
	V ans;
	if((n*(n-1))/2 <k)
		{ cout<<"Impossible\n"; return 0;}
	ll total=0;
	while(k>0)
	{
		ll x=floor(sqrt(2.0*k+0.25)+0.5);
		ans.pb(x);
		k-=(x*(x-1))/2;
		total+=x;
	}
	if(total>n)
		{ cout<<"Impossible\n"; return 0;}
	for(ll i=0;i<ans.size();i++)
	{
		rep(j,1,ans[i]) cout<<"(";
		rep(j,1,ans[i]) cout<<")";
		n-=ans[i];
	}
	rep(i,1,n)
		cout<<"()";
	cout<<"\n";
	return 0;
}
