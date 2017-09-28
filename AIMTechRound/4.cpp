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
	int n,start,x;	cin>>n>>start>>x;
	int a = -1;
	int i = 1;
	int next;
	int ans = INT_MAX;
	bool flag = false;
	int high = n;
	int low = start;
	int maxm = INT_MIN;
	int maxindex;
	int q = 0;
	bool hit = false;
	int t = 10;
	int upper = pow(2,t);
	int lower = 1;
	while(upper <= n)
	{	
		i = lower;
		while(i <= min(upper,n))
		{
			cout<<"? "<<i<<endl;
			cin>>a>>next;
			if(a >= x)
			{
				ans = min(ans,a);
				hit = true;
				if(a == x)
				{
					flag = true;
					break;
				}
			}
			else
			{
				if(a > maxm)
				{
					maxm = a;
					maxindex = i;
				}
			}
			i *= 2;
			q++;
			fflush(stdout);
		}
		t++;
		lower = upper;
		upper = pow(2,t);
	}
	
	
	int cnt = 0;
	if(maxm > INT_MIN)
	{
		i = maxindex;
		while(i != -1 and (cnt < n and q < 1998))
		{
			cout<<"? "<<i<<endl;
			cin>>a>>next;
			if(a >= x)
			{
				ans = min(ans,a);
				hit = true;
				if(a == x)
				{
					flag = true;
					break;
				}
			}
			i = next;
			q++;
			cnt++;
		}
	}
	
	if(hit)	cout<<"! "<<ans<<endl;
	else	cout<<"! -1"<<endl;
	fflush(stdout);
	return 0;

	
}