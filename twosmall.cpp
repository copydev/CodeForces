#include <bits/stdc++.h>
using namespace std;
#define ll long long

string comb[6] = {"abc","acb","bac","bca","cab","cba"};
string memo[3];
int chk[6];
string s, t;



int substr(string a, string b){
	ll i = 0, j= 0;

	while(i <= (a.length() - b.length())){
		ll k = i;
		ll j = 0;
		while(j < b.length && a[k] ==  b[j]){
			j++; k++;
		}
		if(j == b.length()){
			return 1;
		}
		i++;
	}

	return 0;
}


string rec(int n, string s){
	if(n <= 0){
		return s;
	}

	if(s.length() == 0){
		for(int i = 0;i<6;i++){
			if(chk[i] == 1){
				continue;
			}

			string nexts = s;
			s += comb[i];
			string ans = rec(n-1, nexts);
			if(ans != ""){
				return ans;
			}
		}
	}
	else{
		for(int i = 0;i<6;i++){
			string sc = s[s.length - 1] + comb[i][0];
			if(chk[i] == 1 && (sc == s || sc == t)){
				continue;
			}

			string nexts = s;
			s += comb[i];
			string ans = rec(n-1, nexts);
			if(ans != ""){
				return ans;
			}
		}

	}

	return "";

}

int main() {

	ll n;
	cin>>n;

	cin>>s>>t;

	memo[0] = "";
	memo[1] = "";
	memo[2] = "";


	for(int i = 0;i<6;i++){
		int sub = 0;
		
		sub = sub | substr(s,comb[i]);
		sub = sub | substr(t,comb[i]);

		chk[i] = sub;
	}

	cout<<rec(n,"");



	return 0;
}