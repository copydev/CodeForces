#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int q;
	cin>>q;

	while(q--){
		int n;
		cin>>n;

		ll arr[n];

		unordered_map<ll,ll> mp;

		for(int i = 0;i<n;i++){
			cin>>arr[i];
			mp[arr[i]]++;
		}

		ll num = 2048;
		ll req = 1;
		ll flag = 0;

		while(num > 0){

			ll have = mp[num];
			if(req <= have){
				flag = 1;
				break;
			}
			else{
				req = req - have;
				req = req*2;
				num /= 2;
			}

		}

		if(flag == 1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

		
	}

	return 0;
}