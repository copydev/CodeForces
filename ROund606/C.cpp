#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	

	ll t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		vector<ll> ans; //zero indexed

		ll n = s.length() - 2;


		REP(i,n){

			string news = "";
			news += s[i];
			news += s[i+1];
			news += s[i+2];
			
			if(news == "one"){
				ans.push_back(i+1);
				i += 2;
				continue;
			}
			if(news == "two"){
				//check for preceding twone case
				if(i < s.length()-4){
					news += s[i+3];
					news += s[i+4];
					if(news == "twone"){
						ans.push_back(i+2);
						i += 4;
						continue;
					}
					else{
						ans.push_back(i+1);
						i+=2;
						continue;
					}
				}
				else{
					ans.push_back(i+1);
					i+=2;
					continue;
				} 
			}
		}

		cout<<ans.size()<<endl;
		if(ans.size() == 0){
			continue;
		}
		REP(i,ans.size()){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;
	}

	return 0;
}