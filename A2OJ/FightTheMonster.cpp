#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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
#define MAX 100000
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int hpy, atky, defy, hpm, atkm, defm, h, a, d;

int main()
{
	cin>>hpy>>atky>>defy;
	cin>>hpm>>atkm>>defm;
	cin>>h>>a>>d;
	int cost = INT_MAX;
	if(atky > defm)
	{
		int t1 = ceil((double)hpm/(double)(atky-defm));
		if(hpy - t1*(atkm-defy) > 0)	cost = 0;
	}
	
	FOR(i,max(atky,defm+1),max(atky,hpm+defm))
	{	
		FOR(j,defy,max(defy,atkm))
		{	
			int temp = (i-atky)*a + (j-defy)*d;
			// DEBUG((i-atky)*a + (j-defy)*d);
			int t1 = ceil((double)hpm/(double)(i-defm));
			// DEBUG(i);
			// DEBUG(defm);
			// DEBUG(t1);
			temp += max(0,(t1*(atkm-j)-hpy+1)*h);
			// DEBUG(hpy-t1*(atkm-j));
			cost = min(cost, temp);
			// DEBUG(cost);
		}
	}
	cout<<cost<<endl;
	return 0;
}