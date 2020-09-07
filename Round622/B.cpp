#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n, x, y;
		cin>>n>>x>>y;
		if(n == 1){
			cout<<"1 1"<<endl;
			continue;
		}

		ll best,worst;

		//find best
		ll f1 = 1;
		ll e2 = n;

		ll Aavg = x + y;

		if(x == 1){
			f1++;
		}

		if(y == n){
			e2--;
		}

		ll currAvg = (f1 + e2);

		// if(Aavg > (currAvg + 1)){
		// 	best = 1;
		// } else

		if(Aavg > currAvg){
			if((x + y) - 1 <= n){
				best = 1;
			}
			else{
				best = 2;
			}
		}
		else{
			if((x + y) - 1 <= n){
				best = currAvg - Aavg + 2;
			}
			else{
				best = currAvg - Aavg + 3;
			}
		}


		//find worst

		ll f2 = n;
		ll e1 = 1;

		if(x == n){
			f2--;
		}

		currAvg = f2 + e1;

		if(Aavg < currAvg){
			if((n-x)<=(y-1)){
				worst = n;
			}
			else{
				worst = n-1;
			}
		}


	}

	return 0;
}