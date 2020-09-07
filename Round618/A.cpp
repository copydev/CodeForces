#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int num_zero = 0;
		int sum = 0;

		int arr[n];
		REP(i,n){
			cin>>arr[i];
			sum += arr[i];
			if(arr[i] == 0){
				num_zero ++;
			}
		}

		int ans = 0;
		ans += num_zero;

		sum += num_zero;

		if(sum == 0){
			ans += 1;
		}

		cout<<ans<<endl;
	}

	return 0;
}