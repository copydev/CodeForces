#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		cin>>n;

		ll arr[n];

		REP(i,n){
			cin>>arr[i];
		}

		ll maxele = -1;
		ll minele = 1000000000;

		REP(i,n){
			if(arr[i] == -1){
				continue;
			}

			if(i != 0){
				if(arr[i-1] == -1){
					maxele = max(maxele, arr[i]);
					minele = min(minele, arr[i]);
				}


			}
			if(i != n-1){
				if(arr[i+1] == -1){
					maxele = max(maxele, arr[i]);
					minele = min(minele, arr[i]);
				}
			}
		}

		if(maxele == -1){
			cout<<"0 0"<<endl;
			continue;
		}

		ll avg = (maxele + minele)/2;

		REP(i,n){
			if(arr[i] == -1){
				arr[i] = avg;
			}
		}

		ll ansdiff = 0;

		REP(i,n){
			if(i != 0){
				ll tdiff = abs(arr[i] - arr[i-1]);
				ansdiff = max(ansdiff,tdiff);
			}
			if(i != n-1){
				ll tdiff = abs(arr[i] - arr[i+1]);
				ansdiff = max(ansdiff,tdiff);
			}
		}

		cout<<ansdiff<<" "<<avg<<endl;

	}

	return 0;
}