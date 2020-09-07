#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;

	while(t--){
		ll n,p,k;
		cin>>n>>p>>k;

		ll price[n];

		REP(i,n){
			cin>>price[i];
		}

		sort(price,price+n);

		ll ans = 0;

		ll prev = 0;

		for(ll i = 0;i < k;i++){
			ll newp = p - prev;
			if(newp <0){
				break;
			}
			ll tans = i;

			ll idx = i + k -1;

			while(newp > 0 && idx < n){
				if(newp >= price[idx]){
					newp -= price[idx];
					tans += k;
				}
				else{
					break;
				}
				idx += k;
			}

			idx = 0;

			ans = max(ans,tans);

			prev += price[i];
		}

		cout<<ans<<endl;
	}

	return 0;
}