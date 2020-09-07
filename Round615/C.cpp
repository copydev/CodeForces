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

		ll truen = n;

		ll gotans = 0;

		for (ll i = 2;i<= sqrt(n);i++){
			if(n%i == 0){
				
				n /= i;

				for(ll j = i+1; j<= sqrt(n);j++){
					if(n%j == 0){
						//find ans

						ll a = i;
						ll b = j;
						ll c = truen / (i*j);

						if(b != c){
							cout<<"YES"<<endl;
							cout<<a<<" "<<b<<" "<<c<<endl;
							gotans = 1;
							break;
						}
					}
					
				}

				if(gotans){
					break;
				}
			}
		}

		if(!gotans){
			cout<<"NO"<<endl;
		}
	}

	return 0;
}