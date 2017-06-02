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
 
ll t,n,height[100010];
ll cost;
ll pre[100010];
ll prei[100010];
 
void precal(){
	prei[0] = 0;
 
	FOR(i,1,100050){
		prei[i] = prei[i-1] + i;
	}
}
 
ll findCost(int index,int req_height){
	ll curr_cost = height[index] - req_height;
	// DEBUG(curr_cost);
 
 
	curr_cost += pre[index+req_height-1] - pre[index] - prei[req_height - 1];
	// DEBUG(curr_cost);
	curr_cost += pre[index-1] - pre[index - req_height] - prei[req_height - 1];
 
	// DEBUG(pre[index-1] - pre[index - req_height]);
	// DEBUG(prei[req_height - 1]);
	// DEBUG(curr_cost);
	curr_cost += pre[n] - pre[index + req_height - 1];
	// DEBUG(curr_cost);
	curr_cost += pre[index - req_height];
	// DEBUG(curr_cost);
 
	return curr_cost;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	precal();
	cin>>t;
	while(t--){
		cin>>n;
 
		FOR(i,1,n) cin>>height[i];
 
		cost = 0;
 
		
		cost += height[1] - min(1LL,height[1]);
		height[1] = min(1LL,height[1]);
 
		FOR(i,2,n){
			cost += height[i] - min(height[i-1]+1 , height[i]);
			height[i] = min(height[i-1]+1 , height[i]);
		}
 
		cost += height[n] - min(1LL,height[n]);
		height[n] = min(1LL,height[n]);
 
		FORD(i,n,2){
			cost += height[i] - min(height[i+1]+1 , height[i]);
			height[i] = min(height[i+1]+1, height[i]);
		}
 
		// DEBUG(cost);
		// FOR(i,1,n){
		// 	cout<<height[i]<<" ";
		// }
		// cout<<endl;
 
		pre[0] = 0;
		FOR(i,1,n){
			pre[i] = pre[i-1] + height[i];
			// DEBUG(pre[i]);
		}
 
		ll min_cost = INT_MAX;
		FOR(i,1,n){
 
			min_cost = min(min_cost , findCost(i,height[i]));
			
			ll hi,lo,mid;
 
			hi = height[i]-1;
			lo = 0;
 
			while(hi-lo>1){
 
				mid = (hi+lo)>>1;
 
				ll f_mid = findCost(i,mid);
				ll f_mid_1 = findCost(i,mid+1);
 
				if(f_mid_1 - f_mid >0){
					hi = mid;
				}
				else{
					lo = mid;
				}
			}
 
			// DEBUG(hi);
			// DEBUG(lo);
			// DEBUG(findCost(i,hi));
			// DEBUG(findCost(i,lo));
 
			min_cost = min(min_cost , min(findCost(i,hi),findCost(i,lo)));
		}
 
		cout<<cost+min_cost<<endl;
	}
}