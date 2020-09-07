#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll arr[n];

		REP(i,n){
			cin>>arr[i];
		}

		map<ll,ll> mp;

		ll distinct = 0;

		ll maxsize = 0;
		ll maxele = -1;

		REP(i,n){
			if(mp[arr[i]] == 0){
				distinct++;
			}
			mp[arr[i]]++;

			if(maxsize <mp[arr[i]]){
				maxsize = mp[arr[i]];
				maxele = arr[i];
			}
			
		}

		ll ans = min(distinct-1,maxsize);

		ans = max(ans,min(distinct,maxsize-1));

		cout<<ans<<endl;

	}

	return 0;
}