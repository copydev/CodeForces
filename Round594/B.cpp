#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll n;
	cin>>n;
	ll arr[n];
	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}

	sort(arr, arr+n);

	ll hor = 0;
	ll ver = 0;

	
	for(ll i = 0;i<n/2;i++){
		ver += arr[i];
	}
	for(ll i = n/2;i<n;i++){
		hor += arr[i];
	}

	ll ans = ver*ver + hor*hor;
	
	cout<<ans<<endl;


	return 0;
}