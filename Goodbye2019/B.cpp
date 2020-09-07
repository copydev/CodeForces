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


		ll ans = 0;
		vector<ll> av;

		REP(i,n-1){
			if(abs(arr[i]-arr[i+1]) > 1){
				ans = 1;
				av.push_back(i+1);
				av.push_back(i+2);
				break;
			}
		}

		if(ans){
			cout<<"YES"<<endl;
			cout<<av[0]<<" "<<av[1]<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
