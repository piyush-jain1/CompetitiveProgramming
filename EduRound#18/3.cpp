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
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
#define ll long long
#define int_64 uint64_t
inline ll two(ll n) { return 1 << n; }
inline ll test(ll n, ll b) { return (n>>b)&1; }
inline void setBit(ll & n, ll b) { n |= two(b); }
inline void unsetBit(ll & n, ll b) { n &= ~two(b); }
inline ll last_bit(ll n) { return n & (-n); }
inline ll ones(ll n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
inline bool sortDown(ll x,ll y){return x>y;}
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
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
	std::ios::sync_with_stdio(false);
	string str;	cin>>str;
	ll len = str.length();
	std::vector<ll> index1,index2;
	std::vector<char> s;
	REP(i,len)
	{	
		s.pb(str[i]);
		if((str[i]-'0')%3 == 1)		index1.pb(i);
		if((str[i]-'0')%3 == 2)		index2.pb(i);
	}
	ll len1 = index1.size();
	ll len2 = index2.size();
	bool flag[len+10];
	REP(i,len+10)	flag[i] = true;
	ll sum = 0;
	REP(i,len)
	{
		sum += s[i]-'0';
	}
	ll count;
	if(sum%3 == 0)
	{
		cout<<str<<endl;
		return 0;
	}
	else if(sum%3 == 1)
	{	
		ll k1=0,k2=0;
		if(index1.size() >= 1)
		{
			count = 1;
			while(k1<len-1)
			{	
				if(k1 == index1[len1-1])	{k1++; count--;}
				if(s[k1] == '0' && k1!=index1[len1-1])	k1++;
				if(s[k1] != '0' && k1!=index1[len1-1])	break;
			}
			k1 += count;
		}
		if(index2.size() >= 2)
		{
			// s.erase(s.begin()+index2[len2-1]);
			// s.erase(s.begin()+index2[len2-2]);
			count = 2;
			while(k2<len-1)
			{	
				if(k2 == index2[len2-1] || k2 == index2[len2-2]) {k2++; count--;}
				if(s[k2] == '0' && k2!=index2[len2-1] && k2!=index2[len2-2])	k2++;
				if(s[k2] != '0' && k2!=index2[len2-1] && k2!=index2[len2-2])	break;
			}
			k2 += count;
		}
		if(k1 == 0 && k2 == 0)
		{
		    cout<<-1<<endl;
		    return 0;
		}
		if(k1 == 0 || k2 == 0)
		{
		    if(k1!=0)
    		{
    			s.erase(s.begin()+index1[len1-1]);
    			len -= 1;
    		}
    		else if(k2!=0)
    		{
    			s.erase(s.begin()+index2[len2-1]);
    			s.erase(s.begin()+index2[len2-2]);
    			len -= 2;
    		}
		}
		else
		{
		    if(k1 <= k2)
    		{
    			s.erase(s.begin()+index1[len1-1]);
    			len -= 1;
    		}
    		else if(k2 < k1)
    		{
    			s.erase(s.begin()+index2[len2-1]);
    			s.erase(s.begin()+index2[len2-2]);
    			len -= 2;
    		}
		}
		// DEBUG(k1);
		// DEBUG(k2);
		
	}
	else if(sum%3 == 2)
	{	
		ll k1=0,k2=0;
		if(index2.size() >= 1)	
		{
			// s.erase(s.begin()+index2[len2-1]);
			ll count = 1;
			while(k1<len-1)
			{	
				if(k1==index2[len2-1])	{k1++; count--;}
				if(s[k1] == '0' && k1!=index2[len2-1])	k1++;
				if(s[k1] != '0' && k1!=index2[len2-1])	break;
			}
			k1 += count;
		}
		if(index1.size() >= 2)
		{
			// s.erase(s.begin()+index1[len1-1]);
			// s.erase(s.begin()+index1[len1-2]);
			count = 2;
			while(k2<len-1)
			{	
				if(k2==index1[len1-1] || k2==index1[len1-2]){k2++;	count--;}
				if(s[k2] == '0' && k2!=index1[len1-1] && k2!=index1[len1-2])	k2++;
				if(s[k2] != '0' && k2!=index1[len1-1] && k2!=index1[len1-2])	break;
			}
			k2 += count;
		}
		if(k1 == 0 && k2 == 0)
		{
		    cout<<-1<<endl;
		    return 0;
		}
		if(k1 == 0 || k2 == 0)
		{
		    if(k1!=0)
    		{
    			s.erase(s.begin()+index2[len2-1]);
			    len -= 1;
    		}
    		else if(k2!=0)
    		{
    			s.erase(s.begin()+index1[len1-1]);
    			s.erase(s.begin()+index1[len1-2]);
    			len -= 2;
        	}
		}
		else
		{
		    if(k1 <= k2)
    		{
    			s.erase(s.begin()+index2[len2-1]);
			    len -= 1;
    		}
    		else if(k2 < k1)
    		{
    			s.erase(s.begin()+index1[len1-1]);
    			s.erase(s.begin()+index1[len1-2]);
    			len -= 2;
    		}
		}
	
	}
	if(len == 0)
	{
		cout<<-1<<endl;
		return 0;
	}	
	ll k = 0;
	while(s[k] == '0' && k<len-1)	k++;
	FOR(j,k,len-1)	cout<<s[j];
	cout<<endl;
	return 0;
	
}