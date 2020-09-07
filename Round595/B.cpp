#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int q;
	cin>>q;

	while(q--){
		ll n;
		cin>>n;

		ll arr[n];
		for(ll i = 0;i<n;i++){
			cin>>arr[i];
		}

		ll move = 1;
		ll ans[n];

		memset(ans,0,sizeof(ans));

		for(ll i = 0;i<n;i++){
			if(ans[i] != 0){
				continue;
			}
			vector<ll> idx;
			idx.push_back(i);
			ll ci = i;
			while(arr[ci] != (i+1)){
				ci = arr[ci] - 1;	
				idx.push_back(ci);
			}

			for(ll j = 0;j<idx.size();j++){
				ans[idx[j]] = idx.size();
			}
		}

		for(ll i = 0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}