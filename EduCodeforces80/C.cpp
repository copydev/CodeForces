#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n,m;

	cin>>n>>m;

	ll dp[m+1][n+1];

	for(ll i = 1;i<= m;i++){
		for(ll j = 1;j<=n;j++){
			dp[i][j] = 0;
		}
	}

	for(ll i = 1; i <= n; i++){
		dp[1][i] = 1;
	}

	for (ll i = 2; i<= m; i++){
		for(ll j = 1; j<= n; j++){
			dp[i][j] = 0;

			for(ll k = 1; k<= j; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}
		}
	}

	ll dp2[m+1][n+1];

	for(ll i = 1; i<= n; i++){
		dp2[1][i] = 1;
	}

	for(ll i = 2; i<=m ;i++){
		for(ll j = 1; j<=n ;j++){
			dp2[i][j] = 0;

			for(ll k = j; k <= n; k++){
				dp2[i][j] += dp2[i-1][k] ;
				dp2[i][j] %= mod;
			}
		}
	}


	ll ans = 0;

	
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
            ans+=(dp[m][i]*dp2[m][j]) % mod;
            ans %= mod;
        }
    }

    if(ans > mod){
    	ans = ans % mod;
    }

	cout<<ans<<endl;


	return 0;
}