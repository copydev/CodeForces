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

		vector<ll> vec;

		for(ll i = 1; i<= n;i*=2){
			vec.push_back(i);
			n -= i;
		}

		if(n>0){
			vec.push_back(n);
			sort(vec.begin(),vec.end());
		}

		cout<<vec.size()-1<<endl;

		REP(i,vec.size()-1){
			cout<<vec[i+1] - vec[i]<<" ";
		}
		cout<<endl;

	}

	return 0;
}