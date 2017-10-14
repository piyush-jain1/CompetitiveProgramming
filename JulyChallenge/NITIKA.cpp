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
		std::string name;
		std::getline (std::cin,name);
		int letter = 1;
		int i = 0;
		std::vector<char> let[4];
		while(i < name.length())
		{	
			if(isspace(name[i]))	letter++;
			else let[letter-1].pb(name[i]);
			i++;
		}
		if(letter == 1)
		{
			int j = 1;
			char p = let[0][0];
			if(let[0][0] > 95) p = let[0][0]-32;
			cout<<p;
			while(j < let[0].size())
			{
				char c = let[0][j];
				if(let[0][j] < 95) c = let[0][j]+32;
				cout<<c;
				j++;
			}
		}
		else if(letter == 2)
		{	
			char p = let[0][0];
			if(let[0][0] > 95) p = let[0][0]-32;
			cout<<p;
			cout<<". ";
			p = let[1][0];
			if(let[1][0] > 95) p = let[1][0]-32;
			cout<<p;
			int j = 1;
			while(j < let[1].size())
			{
				char c = let[1][j];
				if(let[1][j] < 95) c = let[1][j]+32;
				cout<<c;
				j++;
			}
		}
		else if(letter == 3)
		{
			char p = let[0][0];
			if(let[0][0] > 95) p = let[0][0]-32;
			cout<<p;
			cout<<". ";
			p = let[1][0];
			if(let[1][0] > 95) p = let[1][0]-32;
			cout<<p;
			cout<<". ";
			p = let[2][0];
			if(let[2][0] > 95) p = let[2][0]-32;
			cout<<p;
			int j = 1;
			while(j < let[2].size())
			{
				char c = let[2][j];
				if(let[2][j] < 95) c = let[2][j]+32;
				cout<<c;
				j++;
			}
		}
		cout<<endl;
	}
	
	return 0;
	
}