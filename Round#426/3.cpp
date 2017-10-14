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

vector<int> faca,facb;

void primeFactor(ll a, ll b)
{	
	faca.clear();
	facb.clear();
	ll n = a;
	if(n == 1)	faca.pb(1);
	else
	{
		while(n%2 == 0)
		{
			faca.pb(2);
			n /= 2;
		}
		for(ll i = 3; i <= sqrt(n); i+= 2)
		{
			while(n%i == 0)
			{
				faca.pb(i);
				n /= i;
			}
		}
		if(n > 2)
		{
			faca.pb(n);
		}
	}
	n = b;
	if(n == 1)	facb.pb(1);
	else
	{
		while(n%2 == 0)
		{
			facb.pb(2);
			n /= 2;
		}
		for(ll i = 3; i <= sqrt(n); i+= 2)
		{
			while(n%i == 0)
			{
				facb.pb(i);
				n /= i;
			}
		}
		if(n > 2)
		{
			facb.pb(n);
		}
	}
	
	return;
}
int main()
{	
	fast_io;
	int n;	cin>>n;
	while(n--)
	{
		ll a,b;	cin>>a>>b;
		if(a == 1 and b == 1)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			primeFactor(a,b);
			// for(auto i : faca)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			// for(auto i : facb)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			int i = 0;
			int j = 0;
			bool modi = true;
			while(i < faca.size() and j < facb.size())
			{	
				// trace3(faca[i],facb[j],facb[j+1]);
				if(faca[i] == facb[j] and facb[j] ==  faca[i+1] and faca[i+1] ==  facb[j+1])
				{
					if(faca.size()-i >= facb.size()-j)
					{
						i+=2;
						j++;
					}
					else if(facb.size()-j >= faca.size()-i)
					{
						i++;
						j+=2;
					}
				}
				else if(i+1 < faca.size() and faca[i] == facb[j] and faca[i+1] == facb[j])
				{	
					// cout<<"a-jeeta"<<endl;
					i+=2;
					j++;
				}
				else if(j+1 < facb.size() and faca[i] == facb[j] and faca[i] == facb[j+1])
				{	
					// cout<<"b-jeeta"<<endl;
					i++;
					j+=2;
				}
				else
				{
					modi = false;
					break;
				}	
			}
			if(!modi)	cout<<"No"<<endl;
			else	
			{
				if(i == faca.size() and j == facb.size())
				{
					cout<<"Yes"<<endl;
				}
				else
				{
					cout<<"No"<<endl;
				}
			}
			
		}
		
	}
	return 0;
	
}