#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	ll arr[n];

	vector<ll> neg;

	REP(i,n){
		cin>>arr[i];
		if(arr[i] < 0){
			neg.push_back(arr[i]);
		}
	}

	ll ctr = 1;

	ll ansp1 = 0;
	ll ansp2 = 0;

	REP(i,n){
		if(arr[i] > 0){
			if(ctr == 1){
				ansp1++;
			}
			else{
				ansp2++;
			}
		}
		else{
			ctr *= -1;
			if(ctr == 1){
				ansp1++;
			}
			else{
				ansp2++;
			}
		}
	}

	ll ansp = (ansp1 * (ansp1+1))/2 + (ansp2 * (ansp2 - 1))/2; 
	

	cout<<(n * (n + 1))/2 - ansp<<" "<<ansp<<endl;

	return 0;
}