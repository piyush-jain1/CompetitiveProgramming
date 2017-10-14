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
	fast_io;
	int t;	cin>>t;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(t--)
	{
		string s;
		getline(cin,s);
		// trace(s);
		ll len = s.length();
		// trace(len);
		ll i = 0;
		int r = 0;
		ll a[60];
		while(i < len)
		{	
			ll j = i;
			std::vector<int> dig;
			while(j < len and !isspace(s[j]))
			{	
				dig.pb(s[j]-'0');
				j++;
			}
			int k = dig.size();
			ll number = 0;
			int p = 0;
			while(k > 0)
			{
				number += pow(10,k-1)*dig[p];
				p++;
				k--;
			}
			a[r++] = number;
			i = j+1;
		}
		sort(a,a+r);
		// REP(l,r)
		// {	
		// 	// trace2(a[l],r);
		// 	if(a[l] == r-1)
		// 	{
		// 		if(l < r-1)	cout<<a[r-1];
		// 		else if(r >= 2) cout<<a[r-2];
		// 		break;
		// 	}

		// }

		if(a[r-1] == r-1){
			cout<<a[r-2]<<endl;
		}
		else{
			cout<<a[r-1]<<endl;
		}

		
	}
	return 0;
}