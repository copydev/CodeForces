#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int odd = 0,even = 0;

		REP(i,n){
			int num;
			cin>>num;
			if(num%2 == 0){
				even++;
			}
			else{
				odd++;
			}
		}

		if(even > 0 && odd > 0){
			cout<<"YES"<<endl;
		}
		else if(odd%2 != 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}