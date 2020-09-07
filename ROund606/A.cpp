#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans = 0;

		for(ll i = 1;i<10;i++){
			ll num = i;
			while(num<=n){
				ans++;
				num *= 10;
				num += i;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}