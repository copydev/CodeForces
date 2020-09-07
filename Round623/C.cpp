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

		int dp[2*n + 1];
		memset(dp,0,sizeof(dp));

		int arr[n];
		REP(i,n){
			cin>>arr[i];
			dp[arr[i]] = 1;
		}

		int ansposs= 1;
		int ans[2*n];

		REP(i,n){
			ans[2*i] = arr[i];
			int nextmax= arr[i]+1;

			while(dp[nextmax]){
				nextmax++;
			}

			if(nextmax > 2*n){
				ansposs = 0;
				break;
			}
			else{
				dp[nextmax] = 1;
			}

			ans[2*i + 1] = nextmax;
		}

		if(ansposs){
			REP(i,2*n){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}

	return 0;
}