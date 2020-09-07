#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

void reverseStr(string& str) 
{ 
    ll n = str.length(); 
   
    for (ll i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		vector<string> bin;
		vector<ll> ans;

		while(n--){
			string s;
			cin>>s;
			//cout<<s<<endl;
			bin.push_back(s);
		}

		vector<string> m00;
		vector<string> m11;
		vector<string> m01;
		vector<string> m10;

		map<string,ll> mp; //check for unordered if not working
		map<string,ll> idx;

		ll ans_exist = 1;



		REP(i,bin.size()){
			string s = bin[i];
			idx[s] = i+1;

			if(mp[s] == 1){
				reverseStr(s);
				ans.push_back(i+1);
				if(mp[s] == 1){
					//dont continue failed already
					ans_exist = 0;
					break;
				}
			}
			else{
				mp[s] = 1;
			}



			if(s[0] == '0' && s[s.length() - 1] == '0'){
				m00.push_back(s);
			}
			if(s[0] == '0' && s[s.length() - 1] == '1'){
				m01.push_back(s);
			}
			if(s[0] == '1' && s[s.length() - 1] == '0'){
				m10.push_back(s);
			}
			if(s[0] == '1' && s[s.length() - 1] == '1'){
				m11.push_back(s);
			}



		} 


		//duplicate words with duplicate reverse
		if(ans_exist == 0){
			//cout<<"First break"<<endl;
			cout<<-1<<endl;
			continue;
		}

		// place combination once get

		//trivial condition

		if(m00.size() > 0 && m11.size() > 0){
			if(m01.size() == 0 && m10.size() == 0){
				cout<<-1<<endl;
				continue;
			}
		}

		////






		ll m01s = m01.size();
		ll m10s = m10.size();

		//cout<<m01s<<","<<m10s<<","<<endl;


		if (m01s > m10s){
			REP(i,m01.size()){
				if((m01s - m10s) <= 1){
					break;
				}

				//cout<<m01s<<","<<m10s<<","<<endl;

				//check if reverse exist
				string s = m01[i];
				reverseStr(s);

				if(mp[s] != 1){
					mp[s] = 1;
					m01s--;
					m10s++;

					//add ans;
				}
				else{
					//ignore
					continue;
				}
				//cout<<"S:"<<m01[i]<<endl;
				ans.push_back(idx[m01[i]]);

			}

			if((m01s - m10s) > 1){
				//cout<<m01s<<","<<m10s<<","<<endl;
				cout<<-1<<endl;
				continue;
			}

		}
		else if(m10.size() > m01.size()){
			REP(i,m10.size()){
				if((m10s - m01s) <= 1){
					break;
				}

				//check if reverse exist
				string s = m10[i];
				reverseStr(s);
				if(mp[s] != 1){
					mp[s] = 1;
					m10s--;
					m01s++;

					//add ans;
				}
				else{
					//ignore
					continue;
				}

				ans.push_back(idx[m10[i]]);

			}

			if((m10s - m01s) > 1){
				cout<<-1<<endl;
				continue;
			}


		}

		else{
			//equal and fine
		}

		cout<<ans.size()<<endl;
		REP(i,ans.size()){
			cout<<ans[i]<<" ";
		}
		cout<<endl;


	}

	return 0;
}