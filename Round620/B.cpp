#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

ll checkPalin(string &s){

	ll n = s.length();

	ll i = 0, j = n-1;

	while(i < j){
		if(s[i] != s[j]){
			return 0;
		}
		i++, j--;
	}

	return 1;
}

string revStr(string &s){

	string newStr = "";
	ll n = s.length() -1;

	while(n>= 0){
		newStr += s[n];
		n--;
	}

	return newStr;
}

int main() {

	int n, m;

	cin>>n>>m;

	unordered_map<string,ll> mp;

	vector<string> str;
	vector<string> bac;

	string pal = "";

	REP(i,n){

		string s;
		cin>>s;

		if(checkPalin(s)){
			pal = s;
		}
		else{
			mp[s] = 1;
			string t = revStr(s);
			if(mp[t]){
				str.push_back(s);
				bac.push_back(t);
			}
		}

	}

	// string ans = "";

	// for(ll i = 0; i<str.size();i++){
	// 	ans += str[i];
	// }

	// ans += pal;

	// for(ll i = bac.size()-1; i>=0;i--){
	// 	ans += bac[i];
	// }

	// cout<<ans.length()<<endl;
	// cout<<ans<<endl;

	//find size

	ll size = 0;

	for(ll i = 0;i<str.size();i++){
		size += str[i].length();
	}

	size = size * 2;
	size = size + pal.length();

	cout<<size<<endl;

	for(ll i = 0;i<str.size();i++){
		cout<<str[i];
	}

	cout<<pal;

	for(ll i = bac.size() - 1; i >=0 ; i--){
		cout<<bac[i];
	}

	cout<<endl;

	return 0;
}