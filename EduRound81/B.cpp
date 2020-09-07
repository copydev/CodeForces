#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)


int main() {

	int t;
	cin>>t;

	while(t--){
		ll n,q;
		cin>>n>>q;
		string s;
		cin>>s;

		ll memo[n];
		ll ans = 0;
		ll diff = 0;

		for(ll i = 0;i<n;i++){
			if(s[i] == '0'){
				diff++;
			}
			else{
				diff--;
			}
			memo[i] = diff;
		}

		ll term = memo[n-1];

		if(term == 0){
			for(ll i = 0;i<n;i++){
				if(memo[i] == q){
					ans = -1;
					break;
				}
			}
		}
		else{
			for(ll i = 0;i<n;i++){
				ll rem = q - memo[i];
				if(((rem%term) == 0) && (rem/term) >= 0){
					ans++;
				}
			}
			if(q == 0){
				ans += 1;
			}
		}


		cout<<ans<<endl;

	}

	return 0;
}