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

		int memo[n+1];

		REP(i,n){
			memo[arr[i]] = i;
		}

		int idx = 1;
		int exp = n-1;

		int ans = 1;

		while(idx<n){
			if(memo[idx] == exp){
				idx++;
				exp--;
			}
			else{
				int newexp = memo[idx]-1;
				int i = memo[idx];
				while(i <= exp){
					if(arr[i] != idx){
						ans = 0;
						break;
					}
					i++;
					idx++;
				}
				if(ans == 0){
					break;
				}
				exp = newexp;
			}
		}

		if(ans){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}