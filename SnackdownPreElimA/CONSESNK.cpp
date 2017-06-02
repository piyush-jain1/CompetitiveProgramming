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
 
ll t,n,l,a,b,s_pos[100010];
 
ll findCost(ll pos){
	ll curr_cost = 0;
 
	FOR(i,1,n){
		curr_cost += abs(s_pos[i]-pos);
		pos += l;
	}
 
	return curr_cost;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin>>t;
	while(t--){
 
		cin>>n>>l>>a>>b;
 
		FOR(i,1,n) cin>>s_pos[i];
 
		sort(s_pos+1, s_pos+n+1);
 
		ll min_cost = 1e18;
 
		ll hi,lo,mid;
 
		hi = b - n*l;
		lo = a;
 
		// DEBUG(hi);
		// DEBUG(lo);
 
		min_cost = min(min_cost , findCost(hi));
		min_cost = min(min_cost , findCost(lo));
 
		if(hi==lo){
			cout<<min_cost<<endl;
			continue;
		}
 
		// DEBUG(min_cost);
		--hi;
 
		// FOR(i,lo,hi){
		// 	cout<<i<<" "<<findCost(i)<<endl;
		// }
 
		bool ok = false;
		while(hi-lo>1){
			mid = lo+(hi-lo)/2;
			ll f1,f2;
 
			f1 = findCost(mid+1);
			f2 = findCost(mid);
 
			if(f1 == f2){
				ok = true;
				break;
			}
 
			if(f1 -f2  >0){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
 
		// DEBUG(hi);
		// DEBUG(lo);
 
		if(ok) min_cost = min(min_cost , findCost(mid));
		else min_cost = min(min_cost, min(findCost(lo) , findCost(hi)));
 
		cout<<min_cost<<endl;
	}
}
 