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

		ll ans = 4 * n - 2;

		ans /= 4;

		ans += 1;

		cout<<ans<<endl;
	}

	return 0;
}