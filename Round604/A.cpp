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

		//Check if already not beautiful

		int notgood = 0;

		REP(i,s.length()-1){
			if(s[i] == '?'){
				continue;
			}
			if(s[i] == s[i+1]){
				notgood = 1;
			}
		}

		if(notgood){
			cout<<-1<<endl;
			continue;
		}

		REP(i,s.length()){
			if(s[i] == '?'){
				char rep = 'a';
				while(s[i-1] == rep || s[i+1] == rep){
					rep++;
				}

				s[i] = rep;
				
			}

		}

		cout<<s<<endl;
	}

	return 0;
}	