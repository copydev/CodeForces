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

		ll arr[n];

		ll maxele = INT_MIN;
		ll val = 0;

		REP(i,n){
			cin>>arr[i];
			maxele = max(maxele, arr[i]);
			val = max(val, maxele - arr[i]);
		}

		ll idx = 0;

		while(true){
			if(((1<<idx)-1) >= val){
				break;
			}
			idx++;	
		}

		cout<<idx<<endl;
	}




	return 0;
}