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

	cout<<1<<" "<<n<<endl;

	ll gcd = -1;

	// cout<<-n * arr[0]<<endl;

	REP(i,n){
		ll split = -n * arr[i];

		arr[i] += split;
		cout<<split<<" ";
		if(gcd == -1){
			// cout<<"ok"<<endl;
			gcd = abs(arr[i]);
		}
		else{
			gcd = __gcd(gcd, abs(arr[i]));
		}
	}
	cout<<endl;

	// cout<<"g"<<gcd<<endl;
	if(gcd == 0){
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;

		return 0;

	}

	if(gcd > n){
		for(ll i = n; i> n/2;i--){
			if(gcd % i == 0){
				gcd = i;
				break;
			}
		}
	}

	cout<<1<<" "<<gcd<<endl;

	REP(i,gcd){
		ll ans = -arr[i];
		arr[i] = 0;

		cout<<ans<<" ";
	}
	cout<<endl;

	ll stIdx = n - gcd;

	cout<<stIdx + 1<<" "<<n<<endl;

	for(ll i = stIdx;i < n;i++){
		cout<<-arr[i]<<" ";
	}

	cout<<endl;

	return 0;
}