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
	string good;	cin>>good;
	map<char,bool> g;
	int l = good.length();
	REP(i,l)
	{
		g[good[i]] = true;
	}
	string pattern;	cin>>pattern;
	int patlen = pattern.length();
	int n;	cin>>n;
	REP(i,n)
	{
		string s;	cin>>s;
		int len = s.length();
		bool modi = true;
		if(len < patlen-1)
		{
			modi = false;
		}
		else
		{	
			int j = 0;
			int k = 0;
			while(j < len and k < patlen)
			{
				if(pattern[k] == '*')
				{
					int c = len-patlen+1;
					bool amit = true;
					while(c--)
					{
						if(g[s[j]] == true)
						{
							amit = false;
							break;
						}
						j++;
					}
					if(!amit)	
					{
						modi = false;
						break;
					}
					k++;
				}
				else
				{
					if(pattern[k] == '?')
					{
						if(g[s[j]] != true)
						{
							modi = false;
							break;
						}	
					}
					else if(pattern[k] != s[j])
					{
						modi = false;
						break;
					}
					j++;
					k++;
				}
			}
		}
		if(modi)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
	
}