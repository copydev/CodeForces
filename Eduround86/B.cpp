#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		int len = s.length();

		char c = s[0];

		int same = 1;

		for(ll i = 1;i<s.length();i++){
			if(s[i] != c){
				same = 0;
				break;
			}
		}

		if(same == 1){
			cout<<s<<endl;
		}
		else{
			string tl = "";

			REP(i,len){
				tl += '0';
				tl += '1';
			}
			cout<<tl<<endl;
		}
	}

	return 0;
}