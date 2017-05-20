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
#define MAX 200020
string s[MAX];
struct Trie
{	
	struct Trie * edge[26];
};
void initialize(struct Trie * node)
{
	REP(i,26)	node->edge[i] = NULL;
}
struct Trie * head = (struct Trie *)malloc(sizeof(struct Trie)) ;
void addWord(string word)
{	
	struct Trie * temp = head;
	ll len = word.length();
	ll i = 0;
	while(i < len)
	{	
		if(temp->edge[word[i]-'a'] == NULL)
		{
			struct Trie * t = (struct Trie *)malloc(sizeof(struct Trie)) ;
			initialize(t);
			temp->edge[word[i]-'a'] = t;
		}
		temp = temp->edge[word[i]-'a'];
		// cout<<temp<<endl; 
		i++;
	}	

}

int main()
{	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin>>n;
	ll index = 0;
	initialize(head);
	REP(i,n)
	{
		char tempc;
		
		cin>>tempc;
		if(tempc == '+')
		{	
			string tempstr;
			cin>>tempstr;
			addWord(tempstr);
		}
		else	cin>>s[index++];
	}
	set<string> ans;
	REP(i,index)
	{	
		// DEBUG(s[i]);
		struct Trie * temp = head;
		ll len = s[i].length();
		ll j = 0;
		while(j < len)
		{	
			if(temp->edge[s[i][j]-'a'] == NULL)	break;
			else	temp = temp->edge[s[i][j]-'a'];
			j++;
		}
		if(j == len)
		{
			cout<<-1<<endl;
			return 0;
		}
		else	ans.insert(s[i].substr(0,j+1));
	}
	cout<<ans.size()<<endl;
	for(auto it = ans.begin();it!=ans.end();++it)	cout<<*it<<endl;
	return 0;

}