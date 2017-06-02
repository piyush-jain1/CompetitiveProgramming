#include <bits/stdc++.h>

#define ll long long int

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()

using namespace std;
///////////////////////////////////////////////////////

const int mod = 1000000009;

ll n,m,k;

ll fastPow(int base,int index){
	if(base==1) return 1;
	if(index==0) return 1;
	if(index==1) return base;

	ll ans = fastPow(base,index>>1);

	if(index&1) return (1LL*((ans*ans)%mod)*base)%mod;
	else return (1LL*ans*ans) % mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;

	ll temp = n%k;

	n-=temp;
	m-=temp;
	ll ans = 0;

	ll res =  m -( n - n/k );
	// DEBUG(res);
	if(res>0){
		ll temp_pow = fastPow(2,res);
		ans  =  (k*(2*(temp_pow-1+mod)%mod)%mod)%mod;
		DEBUG(temp_pow);
		m-=res*k;
		
		// ans = (ans + m)%mod;
	}

	// while(res>0){
	// 	ans  = (ans+k)%mod;
	// 	ans = (2LL*ans)%mod;
	// 	--res;
	// 	m-=k;
	// }

	ans  = (ans+m)%mod;

	// DEBUG(res);
	DEBUG(ans);

	cout<<(ans+temp)%mod<<endl;

}