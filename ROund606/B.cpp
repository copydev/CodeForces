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
		ll arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		unordered_map<ll,ll> mp;

		ll moves = 0;

		REP(i,n){
			ll num = arr[i];

			while((num % 2) == 0){
				if(mp[num] == 1){
					break;
				}
				mp[num] = 1;
				num /= 2;
				moves++;
			}
		}

		cout<<moves<<endl;

	}

	return 0;
}