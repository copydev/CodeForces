#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int n;
	cin>>n;
	ll arr[n];
	ll dup = 0;

	ll ans = INT_MAX;

	unordered_map<ll,ll> mp;

	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(mp[arr[i]] != 0){
			dup++;
		}
		mp[arr[i]]++;
	}



	for(int i = 0;i<n;i++){

		unordered_map<ll,ll> np = mp;

		ll d = dup;

		for(int j = i;j<n;j++){

			if(d == 0){
				// cout<<i<<","<<j<<endl;
				ll len = j - i;
				ans = min(ans,len);
				break;
			}

			if(np[arr[j]] > 1){
				d--;
			}

			np[arr[j]]--;

		}

		if(d == 0){
			ll len = n - i;
			ans = min(ans,len);
		}

	}

	cout<<ans<<endl;


	return 0;
}