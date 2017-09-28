#include <bits/stdc++.h>
#define ll long long
using namespace std; 

////////////////////////////////////////////////////////////////////////////////////

ll l,r;
set<ll> s;

void pre(ll x)
{	
	s.insert(x);
	if(x < r)	pre(x*10+4),pre(x*10+7);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>l>>r;
	pre(0);
	ll ans = 0;
	while(l <= r)
	{
		auto it = s.lower_bound(l);
		ans += (min<ll>(r, *it) - l + 1)*(*it);
		l = *it+1;
	}
	cout<<ans<<endl;
	
}