#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll arr[n];

		ll totaltasty = 0;

		REP(i,n){
			cin>>arr[i];
			totaltasty += arr[i];
		}

		ll maxtasty = 0;

		ll temptasty = 0;

		REP(i,n-1){

			if(temptasty < 0){
				temptasty = arr[i];
			}
			else{
				temptasty += arr[i];
			}

			//cout<<temptasty<<"1"<<endl;

			maxtasty = max(maxtasty,temptasty);
		}

		temptasty = 0;

		for(ll i = 1; i<n;i++){

			if(temptasty < 0){
				temptasty = arr[i];
			}
			else{
				temptasty += arr[i];
			}

			//cout<<temptasty<<"2"<<endl;

			maxtasty = max(maxtasty,temptasty);
		}

		if(maxtasty < totaltasty){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}