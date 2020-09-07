#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;

		ll arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		ll memo[n] = {0};

		for(ll i = 1;i<n-1;i++){
			if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
				memo[i] = 1;
			}
		}

		ll ans = 0;
		ll sum = 0;

		ll left = -1;

		ll centerk = k-2;

		for(int i = 1;i<=centerk;i++){
			sum += memo[i];
		}

		ans = sum;
		left = 1;

		// cout<<ans<<endl;

		for(int i = 2; i<=n-centerk;i++){
			sum -= memo[i-1];
			sum += memo[i+centerk-1];

			if(ans < sum){
				ans = sum;
				left = i;
			}
		}


		cout<<ans+1<<" "<<left<<endl;
	}

	return 0;
}