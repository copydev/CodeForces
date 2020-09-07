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

		ll findn = 0;
		ll sumn = 0;
		while(sumn < k){
			findn++;
			sumn += findn;
		}

		// cout<<"S:"<<sumn<<"F:"<<findn<<endl;

		char ans[n];
		for(ll i = 0; i< n;i++){
			ans[i] = 'a';
		}



		sumn -= findn;

		ll kpos = k - sumn;

		ans[n- 1 - findn] = 'b';
		ans[n - kpos] = 'b';

		for(ll i = 0; i<n; i++){
			cout<<ans[i];
		}

		cout<<endl;
	}

	return 0;
}