#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;

	while(t--){
		ll a,b,c,n;
		cin>>a>>b>>c>>n;

		ll maxc = max(a,max(b,c));

		ll diff = maxc - a;
		diff += maxc - b;
		diff += maxc - c;

		n -= diff;

		if(n<0){
			cout<<"NO"<<endl;
		}
		else{
			if(n%3 == 0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}

	return 0;
}