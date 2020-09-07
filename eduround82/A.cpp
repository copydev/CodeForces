#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;

		ll size = s.length();
		
		ll sti = 0, eti = size - 1;

		while(sti < size && s[sti] == '0'){
			sti++;
		}

		while(eti >= 0 && s[eti] == '0'){
			eti--;
		}

		ll ans = 0;

		for(ll i = sti; i<= eti; i++){
			if(s[i] == '0'){
				ans ++;
			}
		}

		cout<<ans<<endl;


	}

	return 0;
}