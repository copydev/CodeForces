#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n, q;
	cin>>n>>q;

	ll dp[2][n+20];

	REP(i,2){
		REP(j,n+20){
			dp[i][j] = -1;
		}
	}

	ll conflict = 0;

	REP(i,q){
		ll r,c;

		cin>>r>>c;
		r--; c--;

		// cout<<"r:"<<r<<"c:"<<c<<endl;
		//cout<<dp[r][c]<<";"<<endl;

		if(dp[r][c] == -1){

			dp[r][c] = 0;

			ll newr = 0;

			if(r == 0){
				newr = 1;
			}

			ll cc = c-1;
			ll idx = 3;

			while(idx){
				if(cc >= 0 && cc < n){
					if(dp[newr][cc] != -1){
						conflict++;
						dp[newr][cc]++;
						dp[r][c]++;
					}
				}
				cc++;
				idx--;
			}

			// if(r == 0){

			// 	//cout<<"Zero"<<endl;

			// 	if(dp[r+1][c] != -1){
			// 		dp[r+1][c]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}

			// 	if((c - 1) >= 0 && dp[r+1][c-1] != -1){
			// 		dp[r+1][c-1]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}

			// 	if((c+1) < n &&dp[r+1][c+1] != -1){
			// 		dp[r+1][c+1]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}

			// }
			// else{

			// 	//cout<<"One"<<endl;

			// 	if(dp[r-1][c] != -1){
			// 		dp[r-1][c]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}

			// 	if((c - 1) >= 0 && dp[r-1][c-1] != -1){
			// 		dp[r+1][c-1]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}

			// 	if((c+1) < n && dp[r-1][c+1] != -1){
			// 		dp[r+1][c+1]++;
			// 		dp[r][c]++;
			// 		conflict++;
			// 	}
			// }
		}
		else{
			conflict -= dp[r][c];
			dp[r][c] = -1;

			ll newr = 0;
			if(r == 0){
				newr = 1;
			}

			ll cc = c-1;
			ll idx = 3;
			while(idx){
				if(cc >= 0 && cc < n){
					if(dp[newr][cc] != -1){
						dp[newr][cc]--;
					}
				}
				//cout<<"r:"<<newr<<"c:"<<cc<<endl;
				cc++;
				idx--;
			}

			// if(r == 0){

			// 	if(dp[r+1][c] >0){
			// 		dp[r+1][c]--;
					
			// 	}

			// 	if((c - 1) >= 0 && dp[r+1][c-1] > 0){
			// 		dp[r+1][c-1]--;
					
			// 	}

			// 	if((c+1) < n && dp[r+1][c+1] > 0){
			// 		dp[r+1][c+1]--;	
					
			// 	}

			// }
			// else{

			// 	if(dp[r-1][c] >0){
			// 		dp[r-1][c]--;
					
			// 	}

			// 	if((c - 1) >= 0 && dp[r-1][c-1] >0){
			// 		dp[r-1][c-1]--;
					
			// 	}

			// 	if((c+1) < n &&dp[r-1][c+1] >0){
			// 		dp[r-1][c+1]--;
					
			// 	}
			// }
		}

		//cout<<conflict<<endl;

		if(conflict == 0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}