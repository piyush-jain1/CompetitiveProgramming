// Rotation of a point w.r.t. to a given arbitrary point by 90 degrees counter-clockwise
// Check if four points make a square
#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define mp make_pair
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
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
//////////////////////////////////////////////////////////////////////////////////////

int a[6], b[6], x[6], y[6];


void rotate(int i)
{
	int tempx = x[i];
	int tempy = y[i];
	x[i] = a[i]+(b[i]-tempy);
	y[i] = b[i]-(a[i]-tempx);
}

bool issquare(int i, int j, int k, int l)
{
	if(x[i] == x[j] and y[i] == y[j])	return false;
	int tempx = x[j]+(y[i]-y[j]);
	int tempy = y[j]-(x[i]-x[j]);
	if(tempx != x[k] or tempy != y[k])	return false;
	tempx = x[i]+(y[i]-y[j]);
	tempy = y[i]-(x[i]-x[j]);
	if(tempx != x[l] or tempy != y[l])	return false;
	return true; 
}
int main()
{
	int n;	cin>>n;
	while(n--)
	{
		FOR(i,1,4)	cin>>x[i]>>y[i]>>a[i]>>b[i];
		int cost = 100;
		FOR(i,0,3)
		{
			FOR(j,0,3)
			{
				FOR(k,0,3)
				{
					FOR(l,0,3)
					{
						if(issquare(1,2,3,4))	cost = min(cost,i+j+k+l);
						if(issquare(1,2,4,3))	cost = min(cost,i+j+k+l);
						if(issquare(1,3,2,4))	cost = min(cost,i+j+k+l);
						if(issquare(1,3,4,2))	cost = min(cost,i+j+k+l);
						if(issquare(1,4,2,3))	cost = min(cost,i+j+k+l);
						if(issquare(1,4,3,2))	cost = min(cost,i+j+k+l);
						rotate(4);
					}
					rotate(3);
				}
				rotate(2);
			}
			rotate(1);
		}
		if(cost == 100)	cout<<-1<<endl;
		else	cout<<cost<<endl;	
	}
	return 0;
}
