#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)


ll n;


ll getAns(){

	for(ll i = 2; i<= sqrt(n); ++i){
		if((n%i) == 0){
			
			while((n%i) == 0){
				n /= i;
			}

			if(n == 1){
				return i;
			}
			else{
				return 1;
			}

			
		}
	}

	return n;

}

int main() {

	cin>>n;
	cout<<getAns()<<endl;

	return 0;
}