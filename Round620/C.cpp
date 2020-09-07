#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n , m;
		cin>>n>>m;

		ll time = 0;

		ll ans = 1;

		ll low = m, high = m;

		while(n--){

			ll t,l,h;
			cin>>t>>l>>h;

			low -= (t - time);
			high += (t- time);

			if(high < l || low > h){
				ans = 0;
				//break;
			}

			high = min(high,h);
			low = max(low,l);

			if(high < low){
				ans = 0;
				//break;
			}

			time= t;

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