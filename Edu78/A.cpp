#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		string s, h;
		cin>>s>>h;

		if(h.length() < s.length()){
			cout<<"NO"<<endl;
			continue;
		}

		ll ans = 0;

		ll nn = h.length()-s.length()+1;

		REP(i,nn){
			//ll lenleft = s.length();

			unordered_map<char,ll> mp;

			REP(j,s.length()){
				mp[s[j]]++;
			}

			//check

			ll idx = 0;
			
			while(idx < s.length()){
				if(mp[h[i + idx]] > 0){
					mp[h[i + idx]]--;
				}
				else{
					//ans = 0;
					break;
				}
				idx++;
				//cout<<idx<<endl;
			}

			if(idx == s.length()){
				ans = 1;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}

	return 0;
}