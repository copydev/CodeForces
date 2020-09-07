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
		// cout<<"n"<<n<<endl;

		ll p = 0, c= 0;

		ll ans = 1;

		while(n--){
			ll currp,currc;
			cin>>currp>>currc;

			// cout<<currp<<","<<currc<<endl;

			if(currc > currp){
				// cout<<"d"<<endl;
				ans = 0;
			}

			if(currp < p || currc < c){

				ans = 0;
			
			}

			ll diffp = currp - p;
			ll diffc = currc - c;

			if(diffc > diffp){

				ans = 0;
				
			}

			c = currc;
			p = currp;
		}

		if(ans){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}