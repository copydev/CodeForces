#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll getans(ll num, ll diff){
	return (num | diff) - diff;
}

int main() {

	ll n;
	cin>>n;

	ll arr[n];

	REP(i,n){
		cin>>arr[i];
	}

	ll frontarr[n] = {0};
	ll backarr[n] = {0};

	ll prev = 0;

	for (ll i = 1; i<n;i++){
		prev = prev | arr[i-1];
		frontarr[i] = prev;
	}

	prev = 0;

	for(ll i = n-2; i>= 0;i--){
		prev = prev | arr[i+1];
		backarr[i] = prev;
	}

	ll ans = 0;

	ll idx = 0;

	ans = getans(arr[0],backarr[0]);

	ll temp = max(ans, getans(arr[n-1],frontarr[n-1]));

	if(temp > ans){
		ans = temp;
		idx = n-1;
	}

	for(ll i = 1;i < n-1; i++){
		temp = max(ans, getans(arr[i], (frontarr[i] | backarr[i])));
		if(temp > ans){
			ans = temp;
			idx = i;
		}
	}

	cout<<arr[idx]<<" ";
	REP(i,n){
		if(i != idx){
			cout<<arr[i]<<" ";
		}
	}

	cout<<endl;


	return 0;
}