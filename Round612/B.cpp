#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n;
	int k;

	cin>>n>>k;

	unordered_map<string,int> mp;
	vector<string> svec;

	REP(i,n){
		string s;
		cin>>s;
		mp[s] = 1;
		svec.push_back(s);
	}

	int ans = 0;

	set<pair<string,pair<string,string>>> st;

	REP(i,n){
		for(ll j = i+1;j<n;j++){
			string a = svec[i];
			string b = svec[j];
			//cout<<a<<b<<endl;
			string c = "";

			REP(z,k){
				if(a[z] == b[z]){
					c += a[z];
				}	
				else{
					if((a[z] == 'S' && b[z] == 'E') || (a[z] == 'E' && b[z] == 'S')){
						c += 'T';
					}
					if((a[z] == 'S' && b[z] == 'T') || (a[z] == 'T' && b[z] == 'S')){
						c += 'E';
					}
					if((a[z] == 'T' && b[z] == 'E') || (a[z] == 'E' && b[z] == 'T')){
						c += 'S';
					}
				}
			}
			//cout<<c<<endl;

			if(mp[c]){
				vector<string> vp;
				vp.push_back(a);
				vp.push_back(b);
				vp.push_back(c);
				sort(vp.begin(),vp.end());
				st.insert({vp[0],{vp[1],vp[2]}});
				
			}

		}
	}

	ans = st.size();

	cout<<ans<<endl;

	return 0;
}