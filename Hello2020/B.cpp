#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	ll alreadyacc = 0;
	ll notacc = 0;

	vector<ll> elecheck;

	ll memo[1000005];
	
	for(ll i = 0;i<1000005;i++){
		memo[i] = 0;
	}

	while(n--){

		ll s;
		cin>>s;

		ll arr[s];
		ll desc = 1;

		REP(i,s){
			cin>>arr[i];
			if(i!=0 && arr[i]>arr[i-1]){
				desc = 0;
			}
		}

		if(desc == 0){
			alreadyacc++;
		}
		else{
			//cout<<arr[0]<<endl;
			memo[arr[0]]++;
			elecheck.push_back(arr[s-1]);
			notacc++;
		}

	}

	ll ans = alreadyacc * alreadyacc;
	ans += notacc * alreadyacc * 2;

	ll sum = 0;
	for(ll i = 1000004; i>= 0;i--){
		ll t = memo[i];
		memo[i] += sum;
		sum += t;
	}

	for(ll i = 0;i <elecheck.size();i++){
		ans += memo[elecheck[i]+1];
	}

	cout<<ans<<endl;

	return 0;
}