#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll oddn = 0, evenn = 0;
		for(ll i = 0;i<n;i++){
			ll num;
			cin>>num;
			if(num%2 == 0){
				evenn ++;
			}
			else{
				oddn++;
			}
		}
		ll m;
		cin>>m;
		ll oddm = 0, evenm = 0;
		for(ll i = 0;i<m;i++){
			ll num;
			cin>>num;
			if(num%2 == 0){
				evenm ++;
			}
			else{
				oddm++;
			}
		}

		ll ans = 0;
		ans += oddn*oddm + evenn*evenm;

		cout<<ans<<endl;
	}

	return 0;
}