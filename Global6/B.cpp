#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {
	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll ans = 0;
		REP(i,6){
			ll k = 15 + i;
			ll temp = n - k;
			if((temp%14) == 0){
				ans = 1;
				break;
			}
		}

		if(ans){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}