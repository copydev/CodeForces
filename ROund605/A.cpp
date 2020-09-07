#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;
	
	while(t--){
		ll arr[3];
		cin>>arr[0]>>arr[1]>>arr[2];

		sort(arr,arr+3);

		if(arr[0] == arr[1] && arr[0] == arr[2]){
			cout<<0<<endl;
			continue;
		}

		if(arr[0] == arr[1]){
			arr[0]++;
			arr[1]++;
			if(arr[0] < arr[2])
				arr[2]--;
		}

		else if(arr[1] == arr[2]){
			arr[1]--;
			arr[2]--;
			if(arr[1] > arr[0])
				arr[0]++;
		}

		else{
			arr[0]++;
			arr[2]--;
		}

		ll ans = abs(arr[0] -  arr[1]) + abs(arr[0] - arr[2]) + abs(arr[1] - arr[2]);


		cout<<ans<<endl;
	}

	return 0;
}