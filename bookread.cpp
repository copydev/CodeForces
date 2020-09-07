#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;

		ll tensum = 0;
		for(int i = 1; i<= 10;i++){
			tensum += (m*i)%10;
		}

		ll ans = 0;

		ll cnt = n/m;
		ll tencnt = cnt/10;
		ll extra = cnt%10;
		
		//Get tencount
		ans += tencnt * tensum;

		//get extra
		for(int i = 1;i<=extra;i++){
			ans += (m*i)%10;
		}

		cout<<ans<<endl;
	}

	return 0;
}