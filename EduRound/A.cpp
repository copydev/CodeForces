#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n;
	cin>>n;

	while(n--){
		int c, sum;
		cin>>c>>sum;

		if(c >= sum){
			cout<<sum<<endl;
		}
		else{
			int avg = sum/c;
			int rem = sum%c;


			ll ans = 0;
			REP(i,rem){
				ans += (avg + 1)*(avg + 1); 
			}
			REP(i,c-rem){
				ans += avg*avg;
			}

			cout<<ans<<endl;
		}
	}

	return 0;
}