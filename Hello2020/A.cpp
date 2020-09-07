#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n,m;

	vector<string> strn;
	vector<string> strm;

	cin>>n>>m;

	REP(i,n){
		string s;
		cin>>s;
		strn.push_back(s);
	}

	REP(i,m){
		string s;
		cin>>s;
		strm.push_back(s);
	}

	ll q;
	cin>>q;

	while(q--){
		ll y;
		cin>>y;

		ll sn = (y-1)%n;
		ll sm = (y-1)%m;

		string ans = strn[sn] + strm[sm];

		cout<<ans<<endl;
	}


	return 0;
}