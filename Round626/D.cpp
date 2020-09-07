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

		ll arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		//Handle when all are same	
		ll temp = arr[0];
		ll same = 1;

		REP(i,n){
			if(arr[i] != temp){
				same = 0;
				break;
			}
		}

		if(same){
			cout<<1<<endl;
			REP(i,n){
				cout<<1<<" ";
			}
			cout<<endl;
			continue;
		}

		ll flag = 1;
		ll specialIdx = -1;

		ll ans[n];
		ll k = 2;
		ans[0] = 1;

		for(ll i = 1; i< n;i++){
			if(arr[i-1] == arr[i] && flag == 1){
				flag = 0;
				specialIdx = i;
			}
			ans[i] = k;
			k = 3 - k;
		}

		if(ans[n-1] == ans[0] && arr[0] != arr[n-1]){
			if(flag){
				k = 3;
				ans[n-1] = 3;
			}
			else{
				for(ll i = specialIdx; i<n;i++){
					ans[i] = 3 - ans[i];
				}
				k = 2;
			}
		}else{
			k = 2;
		}

		cout<<k<<endl;
		REP(i,n){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}