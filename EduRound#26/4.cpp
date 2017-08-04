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


std::vector<pair<ll,ll>> fac2,fac5;
// std::vector<pair<ll,ll>> fac10;

int main()
{	
	fast_io;
	int n,k;	cin>>n>>k;
	REP(i,n)
	{	
		fac2.push_back(make_pair(0,i));
		fac5.push_back(make_pair(0,i));
		// fac10.push_back(make_pair(0,i));
		ll temp;
		cin>>temp;
		while(temp%2 == 0)
		{
			fac2[i].first++;
			temp /= 2;
		}
		while(temp%5 == 0)
		{
			fac5[i].first++;
			temp/=5;
		}
		trace2(fac2[i].first,fac5[i].first);
		// fac10[i].first = min(fac2[i].first, fac5[i].first);
	}
	sort(fac2.begin(),fac2.end(),sortinrev);
	sort(fac5.begin(),fac5.end(),sortinrev);
	// sort(fac10.begin(),fac10.end(),sortinrev);
	int count = 0;
	int i = 0;
	bool visited[210] = {false};
	ll roundness = 0;
	int twoptr = 0, fiveptr = 0;
	ll cnt2 = 0;
	ll cnt5 = 0;
	while(count < k)
	{	
		while(twoptr < n and visited[fac2[twoptr].second])	twoptr++;
		while(fiveptr < n and visited[fac5[fiveptr].second])	fiveptr++;	
		if(fac2[twoptr].second == fac5[fiveptr].second)
		{
			cnt2 += min(fac2[twoptr].first, fac5[fiveptr].first);
			cnt5 += min(fac2[twoptr].first, fac5[fiveptr].first);
			visited[fac2[twoptr].second] = true;
			twoptr++;
			fiveptr++;
			count++;
		}
		else 
		{
			if(count <= k-2)
			{
				cnt2 += fac2[twoptr].first;
				cnt5 += fac5[fiveptr].first;
				visited[fac2[twoptr].second] = true;
				visited[fac5[fiveptr].second] = true;
				twoptr++;
				fiveptr++;
				count += 2;
			}
			else
			{
				cnt2 += max(min(fac2[fiveptr].first,fac2[twoptr].first),min(fac5[fiveptr].first,fac5[twoptr].first));
				cnt5 += max(min(fac2[fiveptr].first,fac2[twoptr].first),min(fac5[fiveptr].first,fac5[twoptr].first));
				count++;
			}	
		}
	}
	cout<<min(cnt2,cnt5)<<endl;
	return 0;
}