#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		vector<char> ans;
		ll n;
		cin>>n;
		// ll ans = 0;
		while(n>3){
			ans.push_back('1');
			n-=2;
		}

		if(n == 3){
			ans.push_back('7');
		}
		if(n == 2){
			ans.push_back('1');
		}

		for(ll i = ans.size()-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<endl;

	}

	return 0;
}