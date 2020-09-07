#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll a,b,c,r;
		cin>>a>>b>>c>>r;

		if(a > b){
			swap(a,b);
		}

		ll ans = b - a;

		ll cmax = min(b,c+r);

		ll cmin = max(a,c-r);

		if(cmax < a || cmin > b){
			cout<<ans<<endl;
		}
		else{
			ans -= (cmax - cmin);
			cout<<ans<<endl;
		}


	}

	return 0;
}