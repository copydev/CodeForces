#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	ll arr[n];

	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}

	map<ll,ll> mp;

	mp[0] = 0;

	ll sum =0;
	ll ans = (n * (n+1))/2;

	// cout<<"ans"<<ans<<endl;

	ll arrstart = 0;

	for(ll i = 1;i<=n;i++){
		sum += arr[i-1];
		// cout<<"i:"<<i-1<<endl;
		// cout<<"sum"<<sum<<endl;
		if(mp[sum] > 0){
			if(mp[sum] >= arrstart){
				ans -= (mp[sum] - arrstart + 1) *(n - i +1);
				arrstart = mp[sum] + 1;
			}
		}
		else if(sum == 0){
			if(mp[sum] >= arrstart){
				ans -= (0 - arrstart) + 1 + (n-i);
				arrstart = mp[sum] +1;
			}
		}

		// cout<<"ans"<<ans<<endl;
		// cout<<"arrstart"<<arrstart<<endl;


		mp[sum] = i;
	}

	cout<<ans<<endl;

	return 0;
}