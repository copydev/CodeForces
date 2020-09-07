#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	string s;
	string t;

	cin>>s>>t;

	ll ti = t.length() - 1;

	ll rt[t.length()];
	ll idx = s.length() - 1;

	while(ti>=0){
		
		while(s[idx] != t[ti]){
			idx--;
		}

		rt[ti] = idx;
		idx--;
		ti--;

	}

	// for(ll i = 0;i<t.length();i++){
	// 	cout<<rt[i]<<" ";
	// }
	// cout<<endl;

	ll ans = 0;
	
	ti = 0;

	for(ll i = 0;i<s.length();i++){

		if(ti == t.length()){
			ti = s.length(); // check
			ans = max(ans,(ll)s.length() - i);
			break;
		}

		ans = max(ans,rt[ti] - i);

		if(ti != s.length() && t[ti] == s[i]){
			ti++;
		}
	}

	cout<<ans<<endl;;

	return 0;
}