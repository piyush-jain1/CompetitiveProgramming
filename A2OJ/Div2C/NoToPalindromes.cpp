#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define int_64 uint64_t
bool wayToSort(ll i, ll j) { return i > j; }
#define PI 3.14159265
// sorting vector of pairs
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b)	{    return (a.first > b.first);	}
bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b)	{    return a.second>b.second;	}
/* First number in array a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
#define mod 1000000007
const int MAX = 100000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll n,p;
string s;


int main()
{
	cin>>n>>p;
	cin>>s;
	
	ll pos = n-1;
	s[pos]++;
	while(pos >= 0 and pos < n)
	{
		if(s[pos] - 'a' >= p)
		{
			s[pos--] = 'a';
			if(pos >= 0)	s[pos]++;
		}
		else if(pos > 0 and s[pos] == s[pos-1])	s[pos]++;
		else if(pos > 1 and s[pos] == s[pos-2])	s[pos]++;
		else pos++;
	}
	if(pos < 0)	cout<<"NO"<<endl;
	else cout<<s<<endl;
	return 0;
}