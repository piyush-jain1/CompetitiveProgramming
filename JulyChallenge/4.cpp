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
#define MAX 100010
/////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{	
	fast_io;
	int test;	cin>>test;
	while(test--)
	{	
		std::vector<pair<int,int>> sd;
		int n,days;	cin>>n>>days;
		int ans = 0;
		int d[n+10], t[n+10], s[n+10];
		FOR(i,1,n)
		{
			cin>>d[i]>>t[i]>>s[i];
			if(t[i] > (days-d[i]+1))
			{
				ans += ((t[i]-(days-d[i]+1))*s[i]);
				t[i] = days-d[i]+1;	
			}
			// trace2(s[i],t[i]);
			sd.pb(mp(i,d[i]));
		}
		sort(sd.begin(), sd.end(),sortbysec);
		// int maxindex[100010] = {0};
		// int p = 1;
		// int q = 0;
		// int prakop = 0;
		// int jaade = 0;
		// while(p <= days)
		// {	
		// 	if(prakop < p)	jaade = 0;
		// 	maxindex[p] = maxindex[p-1];
		// 	while(q < n and sd[q].second <= p)
		// 	{
		// 		if(jaade < s[sd[q].first])
		// 		{
		// 			jaade = s[sd[q].first];
		// 			maxindex[p] = sd[q].first;
		// 			prakop = sd[q].second+t[sd[q].first]-1;
		// 		}

		// 		q++;
		// 	}
		// 	p++;
		// }
		// FOR(i,1,days)
		// {
		// 	trace(maxindex[i]);
		// }
		int j = 1;
		int k = 0;
		int maxm = 0, maxindex;
		while(k < n and sd[k].second <= j)
		{
			if(t[sd[k].first] > 0 and maxm < s[sd[k].first])
			{
				maxm = s[sd[k].first];
				maxindex = sd[k].first;
			}
			k++;	
		}
		do
		{	
			// trace3(maxm, maxindex, t[maxindex]);
			if(maxm > 0)	t[maxindex] -= 1;
			// trace(t[maxindex]);
			j++;
			if(j > days)	break;
			if(t[maxindex] == 0)
			{	
				// cout<<"got if"<<endl;
				k = 0;
				maxm = 0;
				while(k < n and sd[k].second <= j)
				{	
					// trace3(sd[k].first, sd[k].second, t[sd[k].first]);
					if(t[sd[k].first] > 0 and maxm < s[sd[k].first])
					{
						maxm = s[sd[k].first];
						maxindex = sd[k].first;
					}
					k++;	
				}
				// trace3(maxm, maxindex, t[maxindex]);
			}
			else
			{	
				// cout<<"got else"<<endl;
				// trace(k);
				while(k < n and sd[k].second <= j)
				{
					if(t[sd[k].first] > 0 and maxm < s[sd[k].first])
					{
						maxm = s[sd[k].first];
						maxindex = sd[k].first;
					}
					k++;	
				}
				// trace3(maxm, maxindex, t[maxindex]);
			}
		}while(j <= days);
		FOR(i,1,n)
		{	
			// trace2(s[i], t[i]);
			ans += (s[i]*t[i]);
		}
		cout<<ans<<endl;
	}	
	return 0;
}