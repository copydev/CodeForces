#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow2(ll i, ll j){
	if(j == 0){
		return 1;
	}

	ll ans = pow2(i,j/2);

	if(j%2 == 0){
		return ans*ans;
	}
	else{
		return ans*ans*i;
	}
}

int main() {

	int q;
	cin>>q;
	while(q--){
		ll n;
		cin>>n;
		vector<int> ter;

		while(n){
			ter.push_back(n%3);
			n = n/3;
		}

		ll carry = 0;
		//cout<<"Size:" <<ter.size()<<endl;
		for(int i = 0;i<ter.size();i++){

			ter[i] += carry;
			carry = ter[i]/3;
			ter[i] = ter[i] % 3;

			if(ter[i] == 2){
				for(int j = 0;j < i;j++){
					ter[j] = 0;
				}
				ter[i] = 0;
				
				carry = 1;
			}

		}

		if(carry != 0){
			ter.push_back(carry);
		}

		ll ans = 0;

		for(ll i = 0;i<ter.size();i++){
			//cout<<ter[i]<<" ";
			ans += pow2(3,i) * ter[i];
		}
		//cout<<endl;

		cout<<ans<<endl;
	}

	return 0;
}