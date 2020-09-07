#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n,a,b;
		cin>>n>>a>>b;

		string sa = "";

		int idx = 0;

		for(int i = 0;i<a;i++){
			sa += char('a' + idx);
			if(idx<b-1){
				idx++;
			}
		}

		// cout<<sa<<endl;

		string sans = "";

		ll times = n/a + 1;

		REP(i,times){
			sans += sa;
		}

		REP(i,n){
			cout<<sans[i];
		}

		cout<<endl;

	}

	return 0;
}