#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		

		ll x,y;
		cin>>x>>y;

		ll a, b;
		cin>>a>>b;

		ll diff = abs(x-y);

		ll rest = min(x,y);

		ll c1 = diff * a + rest * b;

		ll c2 = diff * a + 2* rest * a;

		ll ans = min(c1,c2);

		cout<<ans<<endl;
	}

	return 0;
}