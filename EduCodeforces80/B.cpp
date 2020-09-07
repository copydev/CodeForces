#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll getNmin(ll dig){
	ll ans = 1;
	while(dig--){
		ans *= 10;
	}

	return ans;
}

int main() {

	int t;
	cin>>t;
	while(t--){

		ll a, b;
		cin>>a>>b;

		ll getb = 9;
		ll ans = 0;

		while(getb <= b){
			ans += a;
			getb *= 10;
			getb += 9;
		}

		cout<<ans<<endl;
	}

	return 0;
}