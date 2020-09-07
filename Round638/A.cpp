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


		ll sum1 = 0;

		ll sum2 = 0;

		ll num = 2;


		ll midn = n/2;

		REP(i,midn-1){
			sum1 += num;
			num = num<<1;
		}

		for(ll i = midn-1;i <n-1;i++){
			sum2 += num;
			num = num<<1;
		}

		sum1 += num;


		// REP(i,n){

		// 	cout<<"n"<<num<<endl;

		// 	if(i%2 == 0){
		// 		sum1 += num;
		// 	}
		// 	else{
		// 		sum2 += num;
		// 	}
			
		// }

		// cout<<sum1<<","<<sum2<<endl;

		ll ans = abs(sum1 - sum2);

		cout<<ans<<endl;

	}

	return 0;
}