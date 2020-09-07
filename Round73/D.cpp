#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
vector<ll> ht;
vector<ll> cost;

ll costrec(ll i){
	if(i >= n-1){
		return 0;
	}
	
}

int main() {

	ll q;
	cin>>q;

	while(q--){

		cin>>n;

		ht = vector<ll> (n);
		cost = vector<ll> (n);

		for(ll i = 0;i<n;i++){
			cin>>ht[i]>>cost[i];
		}


	}


	return 0;
}