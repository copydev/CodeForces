#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll a,b;
		cin>>a>>b;

		ll div = a%b;

		ll ans = b - div;

		if(ans == b){
			ans = 0;
		}

		cout<<ans<<endl;
	}

	return 0;
}