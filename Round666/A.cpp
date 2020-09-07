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

		string s[n];

		REP(i,n){
			cin>>s[i];
		}

		int arr[26] = {0};

		REP(i,n){
			REP(j,s[i].size()){
				arr[int(s[i][j]-'a')]++;
			}
		}

		int ans = 1;

		for(int i = 0;i<26;i++){
			if(arr[i] % n != 0){
				ans = 0;
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