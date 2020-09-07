#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		string s,t;
		cin>>s>>t;

		ll sn = s.length(), tn = t.length();

		ll memo[sn][26];
		memset(memo,-1,sizeof(memo));

		for(ll i = sn - 1; i>= 0;i--){
			if(i == (sn-1)){
				memo[i][s[i] - 'a'] = i;
			}
			else{
				for(ll j = 0; j<26;j++){
					memo[i][j] = memo[i+1][j];
				}
				memo[i][s[i] - 'a'] = i;
			}
		}

		// for(ll i = 0; i<sn;i++){
		// 	for(ll j = 0;j<26;j++){
		// 		cout<<memo[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		//FIND THE ANS
		ll ans = 1;
		ll idx = 0;
		for(ll i = 0;i<tn;i++){
			ll j = t[i] - 'a';
			if(idx >= sn){
				idx = 0;
				ans++;
			}

			if(idx == 0 && memo[idx][j] == -1){
				ans = -1;
				break;
			}

			if(memo[idx][j] != -1){
				idx = memo[idx][j];
				idx++;
			}
			else{
				idx = 0;
				ans++;
				i--;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}