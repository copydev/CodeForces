#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		ll xornum = 0;
		ll sumnum = 0;

		REP(i,n){
			xornum = xornum ^ arr[i];
			sumnum += arr[i];
		}

		if((2 * xornum) == sumnum){
			cout<<0<<endl;
			cout<<endl;
		}
		else{
			ll nums = 0;
			vector<ll> ansnum;

			if(xornum == 0){
				nums = 1;
				ansnum.push_back(sumnum);
			}
			else{
				nums = 2;
				ansnum.push_back(xornum);
				sumnum += xornum;
				ansnum.push_back(sumnum);
			}

			cout<<nums<<endl;
			REP(i,ansnum.size()){
				cout<<ansnum[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}