#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll X;
	cin>>X;

	ll rootX = floor(sqrt(X));

	ll a,b;

	while(rootX != 0){
		if((X%rootX) == 0){
			a = rootX;
			b = X/rootX;
			break;
		}
	}

	cout<<a<<" "<<b<<endl;

	return 0;
}