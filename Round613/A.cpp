#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	string s;
	cin>>s;

	ll left =0, right = 0;

	REP(i,n){
		if(s[i] == 'L'){
			left++;
		}
		else{
			right++;
		}
	}

	ll ans = 1 + left + right;

	cout<<ans<<endl;

	return 0;
}