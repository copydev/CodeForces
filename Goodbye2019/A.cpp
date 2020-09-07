#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n, k1, k2;
		cin>>n>>k1>>k2;

		ll max1 = 0;
		ll max2 = 0;

		REP(i,k1){
			ll t;
			cin>>t;
			max1 = max(max1,t);
		}
		REP(i,k2){
			ll t;
			cin>>t;
			max2 = max(max2,t);
		}

		if(max1>max2){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}