#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n , k;
	cin>>n>>k;

	string s;
	cin>>s;

	ll almap[26] = {0};

	REP(i,k){
		char c;
		cin>>c;
		almap[c-'a']++;
	}
	ll ans = 0;
	ll cons = 0;
	REP(i,s.length()){
		if(almap[s[i] - 'a']){
			cons++;
			ans += cons;
		}
		else{
			cons = 0;
		}
	}

	cout<<ans<<endl;

	return 0;
}