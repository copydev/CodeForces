#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){

		ll n,g,b;

		cin>>n>>g>>b;

		ll gd = (n+1) / 2;

		ll left, turns;

		if(gd%g == 0){

			turns = gd/g - 1;
			left = n - gd;
		}
		else{

			turns = gd/g;
			left = n - gd;
		}

		ll bd = turns * b;

		// turns -= left/b;

		// if(turns <= 0){
		// 	turns = 0;
		// }

		// ll adj = 0;

		// if(turns > 0 && left > 0){
		// 	adj = b - left;
		// 	turns--;
		// }

		ll adj = bd - left;

		if(adj < 0){
			adj = 0;
		}

		cout<< (n + adj)<<endl;
	}

	return 0;
}