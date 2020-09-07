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

		ll ans = 0;
		ll idx = 0;

		for(int i = 1;i<=n;i+=2){
			ans += idx * (2*i + 2* (i-2));
			idx++;
		} 

		cout<<ans<<endl;
	}

	return 0;
}