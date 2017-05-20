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
/* First number in grundyay a which is greater than x
ll * p = std::upper_bound( a, a+n, x );
ll j = p - a;    // index
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ll grundy[100010];
ll *st = new ll[1000000];

ll constructSTUtil(ll ss, ll se, ll si)
{
    if (ss == se)
    {
        st[si] = grundy[ss];
        return grundy[ss];
    }

    ll mid = ss + (se-ss)/2 ;
    st[si] =  constructSTUtil(ss, mid, si*2+1)^constructSTUtil(mid+1, se, si*2+2);
    return st[si];
}


ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    ll mid = ss + (se-ss)/2;;
    return getSumUtil(ss, mid, qs, qe, 2*si+1)^getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

void updateValueUtil(ll ss, ll se, ll i, ll upd, ll si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si]^upd;
    if (se != ss)
    {
        ll mid = ss + (se-ss)/2 ;
        updateValueUtil(ss, mid, i, upd, 2*si + 1);
        updateValueUtil(mid+1, se, i, upd, 2*si + 2);
    }
}

void updateValue(ll n, ll i, ll new_val)
{
    ll old = grundy[i];
    grundy[i] = new_val;
    updateValueUtil(0, n-1, i, old^new_val, 0);
}

ll M[100010];

ll numbered(string cake[])
{	
	ll num = 0;
	ll idx=1;
	FORD(i,3,0)
	{
		FORD(j,3,0)
		{	
			// cout<<cake[i][j];
			if(cake[i][j] == '1')
			{
				num += idx ;
			}
			idx *= 2;
		}
		// cout<<endl;
	}

	return num;
} 
ll getgrundy(string cake[])
{		

	ll num = numbered(cake);
	// DEBUG(num);
	if(M[num] != LLONG_MAX)	return M[num];

	if(num == 0)
	{
		M[num] = 0;
		return 0;
	}
	set<ll> mex;
	// 1x1
	REP(i,4)
	{
		REP(j,4)
		{
			if(cake[i][j] == '1')
			{
				cake[i][j] = '0';
				mex.insert(getgrundy(cake));
				cake[i][j] = '1';
			}
		}
	}
	// 1X2 or 2X1
	REP(j,4)
	{
		REP(k,3)
		{
			if((cake[j][k] == '1' && cake[j][k+1] == '1'))
			{
				cake[j][k] = '0';
				cake[j][k+1] = '0';
				mex.insert(getgrundy(cake));
				cake[j][k] = '1';
				cake[j][k+1] = '1';

			}
			if(cake[k][j] == '1' && cake[k+1][j] == '1')
			{
				cake[k][j] = '0';
				cake[k+1][j] = '0';
				mex.insert(getgrundy(cake));
				cake[k][j] = '1';
				cake[k+1][j] = '1';
			}
		}
	}
	// 1X3 or 3X1
	REP(j,4)
	{
		REP(k,2)
		{	
			if((cake[j][k] == '1' && cake[j][k+1] == '1' && cake[j][k+2] == '1'))
			{	

				cake[j][k] = '0';
				cake[j][k+1] = '0';
				cake[j][k+2] = '0';
				mex.insert(getgrundy(cake));
				cake[j][k] = '1';
				cake[j][k+1] = '1';
				cake[j][k+2] = '1';
			}
			if(cake[k][j] == '1' && cake[k+1][j] == '1' && cake[k+2][j] == '1')
			{
				cake[k][j] = '0';
				cake[k+1][j] = '0';
				cake[k+2][j] = '0';
				mex.insert(getgrundy(cake));
				cake[k][j] = '1';
				cake[k+1][j] = '1';
				cake[k+2][j] = '1';
			}
		}
	}
	// 1X4 or 4X1
	REP(j,4)
	{
		if(cake[j][0]+cake[j][1]+cake[j][2]+cake[j][3] == '1'+'1'+'1'+'1')
		{
			cake[j][0] = '0';
			cake[j][1] = '0';
			cake[j][2] = '0';
			cake[j][3] = '0';
			mex.insert(getgrundy(cake));
			cake[j][0] = '1';
			cake[j][1] = '1';
			cake[j][2] = '1';
			cake[j][3] = '1';
		}
		if(cake[0][j]+cake[1][j]+cake[2][j]+cake[3][j] == '1'+'1'+'1'+'1')
		{
			cake[0][j] = '0';
			cake[1][j] = '0';
			cake[2][j] = '0';
			cake[3][j] = '0';
			mex.insert(getgrundy(cake));
			cake[0][j] = '1';
			cake[1][j] = '1';
			cake[2][j] = '1';
			cake[3][j] = '1';
		}
	}
	// 2X2
	REP(j,3)
	{
		REP(k,3)
		{
			if((cake[j][k] == '1' && cake[j][k+1] == '1' && cake[j+1][k] == '1' && cake[j+1][k+1] == '1'))
			{
				cake[j][k] = '0';
				cake[j][k+1] = '0';
				cake[j+1][k] = '0';
				cake[j+1][k+1] = '0';
				mex.insert(getgrundy(cake));
				cake[j][k] = '1';
				cake[j][k+1] = '1';
				cake[j+1][k] = '1';
				cake[j+1][k+1] = '1';
			}
		}
	}
	// 2X3 or 3X2
	REP(j,3)
	{
		REP(k,2)
		{
			if((cake[j][k] == '1' && cake[j][k+1] == '1' && cake[j][k+2] == '1' && cake[j+1][k] == '1' && cake[j+1][k+1] == '1' && cake[j+1][k+2] == '1'))
			{
				cake[j][k] = '0';
				cake[j][k+1] = '0';
				cake[j][k+2] = '0';
				cake[j+1][k] = '0';
				cake[j+1][k+1] = '0';
				cake[j+1][k+2] = '0';
				mex.insert(getgrundy(cake));
				cake[j][k] = '1';
				cake[j][k+1] = '1';
				cake[j][k+2] = '1';
				cake[j+1][k] = '1';
				cake[j+1][k+1] = '1';
				cake[j+1][k+2] = '1';
			}
			if(cake[k][j] == '1' && cake[k+1][j] == '1' && cake[k+2][j] == '1' && cake[k][j+1] == '1' && cake[k+1][j+1] == '1' && cake[k+2][j+1] == '1')
			{
				cake[k][j] = '0';
				cake[k+1][j] = '0';
				cake[k+2][j] = '0';
				cake[k][j+1] = '0';
				cake[k+1][j+1] = '0';
				cake[k+2][j+1] = '0';
				mex.insert(getgrundy(cake));
				cake[k][j] = '1';
				cake[k+1][j] = '1';
				cake[k+2][j] = '1';
				cake[k][j+1] = '1';
				cake[k+1][j+1] = '1';
				cake[k+2][j+1] = '1';
			}
		}
	}
	// 2X4 or 4X2
	REP(j,3)
	{
		if((cake[j][0]+cake[j][1]+cake[j][2]+cake[j][3] == '1'+'1'+'1'+'1' && cake[j+1][0]+cake[j+1][1]+cake[j+1][2]+cake[j+1][3] == '1'+'1'+'1'+'1'))
		{
			cake[j][0] = '0';
			cake[j][1] = '0';
			cake[j][2] = '0';
			cake[j][3] = '0';
			cake[j+1][0] = '0';
			cake[j+1][1] = '0';
			cake[j+1][2] = '0';
			cake[j+1][3] = '0';
			mex.insert(getgrundy(cake));
			cake[j][0] = '1';
			cake[j][1] = '1';
			cake[j][2] = '1';
			cake[j][3] = '1';
			cake[j+1][0] = '1';
			cake[j+1][1] = '1';
			cake[j+1][2] = '1';
			cake[j+1][3] = '1';
		}
		if(cake[0][j]+cake[1][j]+cake[2][j]+cake[3][j] == '1'+'1'+'1'+'1' && cake[0][j+1]+cake[1][j+1]+cake[2][j+1]+cake[3][j+1] == '1'+'1'+'1'+'1')
		{
			cake[0][j] = '0';
			cake[1][j] = '0';
			cake[2][j] = '0';
			cake[3][j] = '0';
			cake[0][j+1] = '0';
			cake[1][j+1] = '0';
			cake[2][j+1] = '0';
			cake[3][j+1] = '0';
			mex.insert(getgrundy(cake));
			cake[0][j] = '1';
			cake[1][j] = '1';
			cake[2][j] = '1';
			cake[3][j] = '1';
			cake[0][j+1] = '1';
			cake[1][j+1] = '1';
			cake[2][j+1] = '1';
			cake[3][j+1] = '1';
		}
	}
	// 3X3
	REP(j,2)
	{
		REP(k,2)
		{
			if((cake[j][k] == '1' && cake[j][k+1] == '1' && cake[j][k+2] == '1' && cake[j+1][k] == '1' && cake[j+1][k+1] == '1' && cake[j+1][k+2] == '1' && cake[j+2][k] == '1' && cake[j+2][k+1] == '1' && cake[j+2][k+2] == '1'))
			{
				cake[j][k] = '0';
				cake[j][k+1] = '0';
				cake[j][k+2] = '0';
				cake[j+1][k] = '0';
				cake[j+1][k+1] = '0';
				cake[j+1][k+2] = '0';
				cake[j+2][k] = '0';
				cake[j+2][k+1] = '0';
				cake[j+2][k+2] = '0';
				mex.insert(getgrundy(cake));
				cake[j][k] = '1';
				cake[j][k+1] = '1';
				cake[j][k+2] = '1';
				cake[j+1][k] = '1';
				cake[j+1][k+1] = '1';
				cake[j+1][k+2] = '1';
				cake[j+2][k] = '1';
				cake[j+2][k+1] = '1';
				cake[j+2][k+2] = '1';
			}
		}
	}
	// 4X3 or 3X4
	REP(j,2)	
	{
		if((cake[0][j] == '1' && cake[0][j+1] == '1' && cake[0][j+2] == '1' && cake[1][j] == '1' && cake[1][j+1] == '1' && cake[1][j+2] == '1' && cake[2][j] == '1' && cake[2][j+1] == '1' && cake[2][j+2] == '1' && cake[3][j] == '1' && cake[3][j+1] == '1' && cake[3][j+2] == '1'))
		{
			cake[0][j] = '0';
			cake[0][j+1] = '0';
			cake[0][j+2] = '0';
			cake[1][j] = '0';
			cake[1][j+1] = '0';
			cake[1][j+2] = '0';
			cake[2][j] = '0';
			cake[2][j+1] = '0';
			cake[2][j+2] = '0';
			cake[3][j] = '0';
			cake[3][j+1] = '0';
			cake[3][j+2] = '0';
			mex.insert(getgrundy(cake));
			cake[0][j] = '1';
			cake[0][j+1] = '1';
			cake[0][j+2] = '1';
			cake[1][j] = '1';
			cake[1][j+1] = '1';
			cake[1][j+2] = '1';
			cake[2][j] = '1';
			cake[2][j+1] = '1';
			cake[2][j+2] = '1';
			cake[3][j] = '1';
			cake[3][j+1] = '1';
			cake[3][j+2] = '1';
		}
		if(cake[j][0] == '1' && cake[j+1][0] == '1' && cake[j+2][0] == '1' && cake[j][1] == '1' && cake[j+1][1] == '1' && cake[j+2][1] =='1' && cake[j][2] == '1' && cake[j+1][2] == '1' && cake[j+2][2] == '1' && cake[j][3] == '1' && cake[j+1][3] == '1' && cake[j+2][3] == '1')
		{
			cake[j][0] = '0';
			cake[j+1][0] = '0';
			cake[j+2][0] = '0';
			cake[j][1] = '0';
			cake[j+1][1] = '0';
			cake[j+2][1] = '0';
			cake[j][2] = '0';
			cake[j+1][2] = '0';
			cake[j+2][2] = '0';
			cake[j][3] = '0';
			cake[j+1][3] = '0';
			cake[j+2][3] = '0';
			mex.insert(getgrundy(cake));
			cake[j][0] = '1';
			cake[j+1][0] = '1';
			cake[j+2][0] = '1';
			cake[j][1] = '1';
			cake[j+1][1] = '1';
			cake[j+2][1] = '1';
			cake[j][2] = '1';
			cake[j+1][2] = '1';
			cake[j+2][2] = '1';
			cake[j][3] = '1';
			cake[j+1][3] = '1';
			cake[j+2][3] = '1';
		}
	}
	// 4X4
	if(cake[0][1] == '1' && cake[0][2] == '1' && cake[0][3] == '1' && cake[0][0] == '1' && cake[1][1] == '1' && cake[1][2] == '1' && cake[1][3] == '1' && cake[1][0] == '1' && cake[2][1] == '1' && cake[2][2] == '1' && cake[2][3] == '1' && cake[2][0] == '1' && cake[3][1] == '1' && cake[3][2] == '1' && cake[3][3] == '1' && cake[3][0] == '1')
	{
		cake[0][0] = '0';
		cake[0][1] = '0';
		cake[0][2] = '0';
		cake[0][3] = '0';
		cake[1][0] = '0';
		cake[1][1] = '0';
		cake[1][2] = '0';
		cake[1][3] = '0';
		cake[2][0] = '0';
		cake[2][1] = '0';
		cake[2][2] = '0';
		cake[2][3] = '0';
		cake[3][0] = '0';
		cake[3][1] = '0';
		cake[3][2] = '0';
		cake[3][3] = '0';
		mex.insert(getgrundy(cake));
		cake[0][0] = '1';
		cake[0][1] = '1';
		cake[0][2] = '1';
		cake[0][3] = '1';
		cake[1][0] = '1';
		cake[1][1] = '1';
		cake[1][2] = '1';
		cake[1][3] = '1';
		cake[2][0] = '1';
		cake[2][1] = '1';
		cake[2][2] = '1';
		cake[2][3] = '1';
		cake[3][0] = '1';
		cake[3][1] = '1';
		cake[3][2] = '1';
		cake[3][3] = '1';
	}

	set<ll>::iterator it = mex.begin();
	set<ll>::iterator pr;
	if(*it == 0)
	{	
		pr = it;
		++it;
		if(it != mex.end())
		{
			for(;it != mex.end();++it)
			{	
				if(*it != (*pr+1))
				{	
					M[num] = *pr+1;
					return *pr+1;
				}
				pr = it;
			}
		
	}
	M[num] = *pr+1;
	return (*pr+1);
		
	}
	else
	{
		M[num] = 0;
		return 0;
	}
	

}
int main()
{	
	std::ios::sync_with_stdio(false); 

	REP(i,100000)
	{
		M[i] = LLONG_MAX;
	}
	ll t;	cin>>t;
	while(t--)
	{	
		ll n,m;	cin>>n>>m;
		string cake[4];
		
		FOR(i,1,n)
		{	
			FOR(j,0,3)
			{	
				cin>>cake[j];
			}
			grundy[i-1] = getgrundy(cake);
			// DEBUG(grundy[i-1]);
		} 
		constructSTUtil(0, n-1, 0);
		ll qt,qs,qe,pos;
		
		ll newGrundy;
		while(m--)
		{
			cin>>qt;
			if(qt == 1)
			{
				cin>>qs>>qe;
				// cout<<getSumUtil(st,0,n-1,qs-1,qe-1,0)<<endl;
				if(getSumUtil(0,n-1,qs-1,qe-1,0)==0)
				{
					cout<<"Lotsy"<<endl;
				}
				else
				{
					cout<<"Pishty"<<endl;
				}
			}
			else
			{	
				cin>>pos;
				string newcake[4];
				REP(i,4)
				{
					cin>>newcake[i];
				}
				newGrundy = getgrundy(newcake);
				updateValue(n,pos-1,newGrundy);

			}
		}

	}
	return 0;
}