#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n, k;
		cin>>n>>k;

		ll candies = n/k * k;

		ll candiesleft = n%k;

		candies += min(k/2,candiesleft);

		cout<<candies<<endl;
	}

	return 0;
}