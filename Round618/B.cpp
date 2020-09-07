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

		ll size = 2*n;

		ll arr[size];

		REP(i,size){
			cin>>arr[i];
		}

		sort(arr,arr + 2*n);

		ll ans = arr[n] - arr[n-1];

		cout<<ans<<endl;

	}

	return 0;
}