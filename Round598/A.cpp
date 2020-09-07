#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int q;
	cin>>q;
	while(q--){
		ll a,b,n,s;
		cin>>a>>b>>n>>s;

		ll left = s - min(a, s/n) * n;

		if(left <= b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}