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

/////////////////////////////////////////////////////////////////////////////////////////////////////////


ll a[100010], b[100010], c[100010];
int main()
{	
	// std::cout << std::setprecision(2);
 //  	std::cout << std::fixed;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	string s, m;
	cin>>s>>m;

	REP(i,n)
	{
		a[i] = s[i]-'0';
		b[i] = m[i]-'0';
		c[i] = b[i];
	}
	sort(b,b+n);
	sort(c,c+n);
	ll counts = 0;
	ll countm = n;
	REP(i,n)
	{
		REP(j,n)
		{	
			if(b[j] >= a[i])
			{	
				b[j] = -1;
				countm--;
				break;
			}
		}
	}
	REP(i,n)
	{
		REP(j,n)
		{
			if(c[j] > a[i])
			{	
				c[j] = -1;
				counts++;
				break;
			}
		}
	}
	cout<<countm<<endl<<counts<<endl;
	return 0;

	
}