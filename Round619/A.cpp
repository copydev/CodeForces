#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){

		string a,b,c;
		cin>>a>>b>>c;

		ll n = a.length();

		ll ans = 1;

		REP(i,n){
			if(a[i] == b[i]){
				if(a[i] != c[i]){
					ans = 0;
					break;
				}
			}
			else{
				if(a[i] != c[i] && b[i] != c[i]){
					ans = 0;
					break;
				}
			}
		}

		if(ans){
			cout<<"YES"<<endl;
		}	
		else{
			cout<<"NO"<<endl;
		}

	}

	return 0;
}