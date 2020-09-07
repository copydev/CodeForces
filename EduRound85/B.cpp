#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n,x;

		cin>>n>>x;

		ll arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		ll sum = 0;

		REP(i,n){
			sum += arr[i];
		}

		cout<<sum/x<<endl;
	}

	return 0;
}