#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		string s;
		cin>>s;

		int ans = 0;

		int a = 0;
		int t = 0;
		REP(i,k){
			if(s[i] == 'A'){
				a = 1;
				t = 0;
			}
			else{
				if(a){
					t++;
					ans = max(ans,t);
				}
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}