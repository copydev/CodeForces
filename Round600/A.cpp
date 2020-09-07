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

		ll a[n],b[n];
		REP(i,n){
			cin>>a[i];
		}

		REP(i,n){
			cin>>b[i];
		}
		ll opp = 0;
		ll cons = 0;
		ll k = -1;
		ll ans = 1;
		REP(i,n){
			if(a[i] == b[i]){
				cons = 0;
				continue;
			}

			if(opp == 0){
				opp = 1;
				cons = 1;
				k = b[i] - a[i];
				if(k <= 0){
					ans =0;
					break;
				}
			}
			else{
				if(cons == 0 || (a[i] + k != b[i])){
					ans = 0;
					break;
				}
			}
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