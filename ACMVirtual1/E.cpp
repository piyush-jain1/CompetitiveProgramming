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

ll n;
string s;		
bool check(ll t)
{	
	ll done = -1;
	ll left = n;
	bool flag = true;
	REP(i,n)
	{	
		cout<<i<<" ";
		if(done >= n-1)	return true;	
		if(s[i] == '*' and done < i)
		{
			if(flag)
			{
				left = i;
				flag = false;
			}
		}
		else if(s[i] == 'P' and done < n)
		{	
			if(done >= i-1)
			{
				// cout<<"hcuudc"<<endl;
				// trace2(n-1, done+t);
				done = min(n-1,i+t);
			}
			else if(left == n)	done = min(n-1,done+t);
			else
			{	
				if(left <= done)	done = min(n-1,done+t);
				else
				{
					ll dis = i-left;
					// trace2(dis,t);
					if(dis > t)	return false;
					else
					{	
						done = max(i,i+t-2*dis);
						// cout<<i+t-2*dis<<endl;
						done = min(done,n-1);
					}
				}
				
			}	
			flag = true;
		}
		trace2(left, done);
	}
	if(done>=n-1)	return true;
	else return false;
}
int main()
{	
	fast_io;
	cin>>n;
	cin>>s;
	ll low = 0, high = 1e6+5;
	// while((high-low)>1)
	// {
	// 	ll mid = (high+low)/2;
	// 	if(check(mid))	high = mid;
	// 	else low = mid;
	// }

	// if(check(low))	cout<<low<<endl;
	// else if(check(high))	cout<<high<<endl;
	cout<<"**P.*..*..P..*.*P**"<<endl;
	bool ans = check(7);
	trace(ans);
	// FOR(i,0,100){
	// 	trace(check(i));
	// }

	return 0;
	
}