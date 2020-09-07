#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll getGCD(ll a, ll b){
	if(a == 0){
		return b;
	}

	return getGCD(b%a, a);
}

int main() {

	int t;
	cin>>t;

	while(t--){
		ll a,b;
		cin>>a>>b;

		ll q;
		cin>>q;


		if(a > b){
			swap(a,b);
		}

		ll alwayszero = 0;

		if(b % a == 0){
			alwayszero = 1;
		}

		REP(i,q){
			ll l,r;
			cin>>l>>r;
			if(alwayszero){
				cout<<0<<" ";
				continue;
			}

			if(r < b){
				cout<<0<<" ";
				continue;
			}

			ll ans = 0;
			if(l < b){
				l = b;
			}

			ll diff = r - l;

			if(r < getGCD(a,b)){

				
			}
		}

		cout<<endl;
	}

	return 0;
}