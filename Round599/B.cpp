#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		vector<char> sc;
		vector<char> tc;

		REP(i,n){
			if(s[i] != t[i]){
				sc.push_back(s[i]);
				tc.push_back(t[i]);
			}
			if(sc.size() >= 3){
				break;
			}
		}

		if(sc.size() >= 3){
			cout<<"NO"<<endl;
		}
		else{
			//for yes
			

			if(sc.size() == 0){
				cout<<"YES"<<endl;
			}
			else if (sc.size() == 1){
				cout<<"NO"<<endl;
			}
			else{
				sort(sc.begin(),sc.end());
				sort(tc.begin(),tc.end());
				if(sc[0] == sc[1] && tc[0] == tc[1]){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}

		}
	}

	return 0;
}