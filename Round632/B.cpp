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
		int a[n];
		int b[n];

		REP(i,n){
			cin>>a[i];
		}

		REP(i,n){
			cin>>b[i];
		}

		int ans = 1, up = 0, down = 0;

		REP(i,n){
			if(a[i] == b[i]){
				
			}
			else if(a[i] < b[i]){
				if(up){
					
				}
				else{
					ans = 0;
					break;
				}
			}
			else{
				if(down){
					
				}
				else{
					ans = 0;
					break;
				}
			}

			if(a[i] == 1){
				up = 1;
			}
			if(a[i] == -1){
				down = 1;
			}

			if(up && down){
				break;
			}
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