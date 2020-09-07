#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	vector<ll> arr(n);

	REP(i,n){
		cin>>arr[i];
	}

	sort(arr.begin(),arr.end());

	ll ans = 10e15;

	ll idx = 1;

	while(1){
		ll ctr = 1;
		ll curr = 0;
		for(ll j =0; j<n;j++){
			if(arr[j] > ctr){
				curr += arr[j] - ctr;
			}
			else{
				curr += ctr - arr[j];
			}
			ctr *= idx;
			if(ctr > 10e15){
				break;
			}
		}

		if(ctr > 10e15){
			break;
		}

		if(curr < ans && curr >= 0){
			ans = curr;
		}
		idx++;
	}

	cout<<ans<<endl;


	return 0;
}