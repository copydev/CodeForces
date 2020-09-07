#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	double ans = 0;

	for(double i = 1; i<= n;i++){

		ans += (1/i);

	}

	cout<<ans<<endl;

	return 0;
}