#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		char ans[n][m];

		int pos = 0;

		REP(i,n){
			REP(j,m){
				if(pos == 0){
					ans[i][j] = 'B';
					pos = 1;
				}
				else{
					ans[i][j] = 'W';
					pos = 0;
				}
			}
		}

		if((n*m)%2 == 0){
			ans[n-1][m-1] = 'B';
		}

		REP(i,n){
			REP(j,m){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}