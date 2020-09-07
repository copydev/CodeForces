#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		if(n%2 != 0){
			cout<<n/2<<endl;
		}
		else{
			cout<<(n/2)-1<<endl;
		}
	}

	return 0;
}