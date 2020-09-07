#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

void solve(){
	ll n;
	cin>>n;

	string s;
	cin>>s;

	//find out small lis
	ll idx = 0;
	ll num = n;
	ll ans1[n], ans2[n];


	for(ll i = 0; i< n-1;i++){
		if(s[i] == '>'){
			ll j = i;
			while(j >= idx){
				ans1[j--] = num--;
			}
			idx = i+1;
		}
	}

	ll tn = n-1;

	while(num){
		ans1[tn--] = num--;
	}

	// greatest 

	idx = 0, num = 1;

	for(ll i = 0;i<n-1;i++){
		if(s[i] == '<'){
			ll j = i;
			while(j >= idx){
				ans2[j--] = num++;
			}
			idx = i+1;
		}
	}

	tn = n-1;

	while(num <= n){
		ans2[tn--] = num++;
	}

	REP(i,n){
		cout<<ans1[i]<<" ";
	}

	cout<<endl;

	REP(i,n){
		cout<<ans2[i]<<" ";
	}

	cout<<endl;

}

int main() {

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}