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
#define REP(i,n) for(int i=0;i<(n);i++)
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
	int n,k;	cin>>n>>k;
	string s;	cin>>s;
	map<int,int> open, close;
	REP(i,26)
	{
		open[i] = n;
		close[i] = -1;
	}
	REP(i,n)
	{
		open[s[i]-'A'] = min(open[s[i]-'A'],i);
		close[s[i]-'A'] = max(close[s[i]-'A'],i);
	}
	// REP(i,26)
	// {
	// 	trace2(open[i],close[i]);
	// }
	int req = 0;
	int cnt = 0;
	bool flag[30] = {false};
	REP(i,n)
	{	
		if(flag[s[i]-'A'] == false and open[s[i]-'A'] <= i)
		{
			flag[s[i]-'A'] = true;
			cnt++;
		}
		req = max(req,cnt);
		// trace(req);
		if(flag[s[i]-'A'] == true and close[s[i]-'A'] <= i)
		{
			cnt--;
		}
		// req = max(req,cnt);
		// trace(req);
		// trace(cnt);
	}
	if(req > k)
	{
		cout<<"YES"<<endl;
	}
	else	cout<<"NO"<<endl;
	return 0;
}