#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;

		if(n == 1){
			cout<<0<<endl;
			continue;
		}

		if(n == 2){
			cout<<m<<endl;
			continue;
		}

		m = m*2;
		cout<<m<<endl;
	}

	return 0;
}	