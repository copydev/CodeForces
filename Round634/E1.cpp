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

		int arr[n];

		REP(i,n){
			cin>>arr[i];
		}

		// 

		int dp[n+1][27] = {0};


		// REP(i,n){
		// 	REP(j,27){
		// 		cout<<dp[i][arr[i]]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		REP(i,n){
			
			dp[i+1][arr[i]]++;
			REP(j,27){
				dp[i+1][j] += dp[i][j];
				// cout<<"i"<<i<<"j"<<j<<"="<<dp[i][j]<<endl;
			}
		}

		// REP(i,n+1){
		// 	REP(j,27){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		ll ans = 0;

		for(int i = 0;i<=n;i++){
			for(int j = i;j<=n;j++){

				// cout<<"i:"<<i<<","<<j<<endl;

				ll midrange[27];
				ll firstrange[27];
				ll lastrange[27];

				REP(k,27){
					midrange[k] = dp[j][k] - dp[i][k];
					// if(k == 1){
					// 	cout<<midrange[k];
					// }
					firstrange[k] = dp[i][k];
					lastrange[k] = dp[n][k] - dp[j][k];
				}

				ll midlen = 0;
				ll extremelen = 0;

				REP(k,27){
					midlen = max(midlen,midrange[k]);
					extremelen = max(extremelen,min(firstrange[k],lastrange[k]));
				}


				// cout<<"i"<<i<<"j"<<j<<endl;
				// cout<<"mid"<<midlen<<"extremelen"<<extremelen<<endl;

				ans = max(ans,midlen+ (2 * extremelen));
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}