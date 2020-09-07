#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int x,n,m;

		cin>>x>>n>>m;

		int lim = 10 * m;

		int ans = 0;

		while(n--){
			if(x <= lim){
				ans = 1;
			}

			x = x/2 + 10;
		}

		if(x <= lim){
			ans = 1;
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