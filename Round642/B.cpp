#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;

		ll a[n], b[n];

		REP(i,n){
			cin>>a[i];
		}

		REP(i,n){
			cin>>b[i];
		}

		sort(a,a+n);
		sort(b,b+n);

		vector<ll> ansv;

		REP(i,n){
			ansv.push_back(a[i]);
		}

		REP(i,k){
			ansv.push_back(b[n-1-i]);
		}

		sort(ansv.begin(),ansv.end(),greater<ll>());

		ll ans = 0;

		REP(i,n){
			ans += ansv[i];
		}

		cout<<ans<<endl;
	}

	return 0;
}