#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll solve(vector<ll> &v, vector<ll> &l, vector<ll> &h){
	ll ans = LONG_MAX;

	for(int i = 0;i<v.size();i++){
		auto li = lower_bound(l.begin(),l.end(),v[i]);
		auto hi = lower_bound(h.begin(),h.end(),v[i]);

		if(hi == h.end()){
			continue;
		}

		// if(*li == 0){
		// 	continue;
		// }

		// if(hi == h.begin() || li == l.end()){
		// 	continue;
		// }
		// hi--;

		cout<<"vi"<<v[i]<<endl;
		cout<<"*li"<<*li<<endl;
		cout<<"*hi"<<*hi<<endl;

		ll temp = (v[i] - *li)*(v[i] - *li) + (v[i] - *hi)*(v[i] - *hi) + (*li - *hi)*(*li - *hi);
		ans= min(ans,temp);
	}

	return ans;
}

int main() {

	vector<int> arr(10);

	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 4;
	arr[4] = 7;
	arr[5] = 10;
	arr[6] = 12;
	arr[7] = 15;
	arr[8] = 15;
	arr[9] = 20;

	auto i = lower_bound(arr.begin(),arr.end(),9);

	// if(i == arr.end()){
	// 	cout<<"Reached arr end"<<endl;
	// }
	// i--;

	cout<<*i<<endl;

	int t;
	cin>>t;

	while(t--){
		ll nr,ng,nb;
		cin>>nr>>ng>>nb;

		vector<ll> red(nr);
		vector<ll> green(ng);
		vector<ll> blue(nb);

		sort(red.begin(),red.end());
		sort(green.begin(),green.end());
		sort(blue.begin(),blue.end());

		REP(i,nr){
			cin>>red[i];
		}

		REP(i,ng){
			cin>>green[i];
		}

		REP(i,nb){
			cin>>blue[i];
		}

		ll ans = LONG_MAX;

		// ans = min(ans,solve(red,green,blue));
		// ans = min(ans,solve(red,blue,green));
		// ans = min(ans,solve(blue,red,green));
		// ans = min(ans,solve(blue,green,red));
		// ans = min(ans,solve(green,red,blue));
		ans = min(ans,solve(green,blue,red));

		cout<<ans<<endl;
	}

	
	return 0;
}