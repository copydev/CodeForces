#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll s;
		cin>>s;

		ll ans = 0;
		while(s >= 10){
			ll rem = s%10;
			ans += s - rem;
			s = rem + s/10;
		}
		ans += s;

		cout<<ans<<endl;
	}

	return 0;
}