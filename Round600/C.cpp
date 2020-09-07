#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n, m;
	cin>>n>>m;

	ll arr[n];

	ll sumarr[n];

	ll ans[n];

	REP(i,n){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	sumarr[0] = arr[0];

	ans[0] = arr[0];

	for(ll i = 1;i<n;i++){
		sumarr[i] = sumarr[i-1] + arr[i];
		if(i - m < 0){
			ans[i] = sumarr[i];
		}
		else{
			ans[i] = sumarr[i] + ans[i - m];
		}
		//cout<<"i:"<<ans[i]<<endl;
	}

	REP(i,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}