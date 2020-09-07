#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;
	while(t--){
		ll a, b;
		cin>>a>>b;

		if(a>b){
			swap(a,b);
		}

		ll moves = 0;
		ll idx = 1;

		while(a != b){
			if(a + idx > b){
				b += idx;
			}
			else{
				a += idx;
			}

			idx++;
			moves++;
		}

		cout<<moves<<endl;
	}

	return 0;
}