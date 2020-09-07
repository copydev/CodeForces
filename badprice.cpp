
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i = 0;i<n;i++){
			cin>>arr[i];
		}

		ll minNum = 1000000, ans = 0;

		for(ll i = n-1; i >=0 ;i--){
			if(minNum < arr[i]){
				ans++;
			}
			else{
				minNum= arr[i];
			}
		}

		cout<<ans<<endl;	
	}

	return 0;
}
