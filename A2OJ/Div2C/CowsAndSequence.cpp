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
const int MAX = 200000;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int n;
int edit[200010] = {0};
int v[200010] = {0};
double avg = 0;
int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	int size = 1;
	v[0] = 0;
	while(n--)
	{
		int t;	cin>>t;
		if(t == 1)
		{
			int a,x;	cin>>a>>x;
			avg += (a*(x*1.0/size));
			edit[a-1] += x;
			v[a-1] += x;
		}
		else if(t == 2)
		{
			int k;	cin>>k;
			v[size] = k;
			avg = ((size*avg + k)/(size+1));
			size++;
		}
		else
		{	
			edit[size-2] += edit[size-1];
			v[size-2] += edit[size-1];
			edit[size-1] = 0;
			avg = (avg*size - v[size-1])/(size-1);
			size--;
		}
		cout << std::setprecision(6)<<fixed;
		cout<<avg<<endl;
	}
	return 0;

}