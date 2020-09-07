#include <bits/stdc++.h>
using namespace std;
#define ll int

ll check(string str){
	stack<char> stk;
	int idx = 0;
	//cout<<str<<endl;

	while(idx < str.length()){
		if(str[idx] == '('){
			stk.push('(');
		}
		else{
			if(stk.empty()){
				return 0;
			}
			else{
				stk.pop();
			}
		}
		idx++;
	}
	return stk.empty();
}

ll findVal(string str){
	ll ans = 0;
	if(check(str)){
		ans++;
	}
	for(int i = 1;i<str.length();i++){
		string newstr = "";
		newstr += str.substr(i,str.length()) + str.substr(0,i);
		if(check(newstr)){
			ans++;
		}
	}

	return ans;
}

ll findVal2(string str){
	ll openB = -1; // ')'
	ll cntOB = 0;

	ll cb = 0;
	for(int i = 0;i<str.length();i++){
		if(str[i] == '('){
			cb++;
		}
		else{
			if(cb == 0){
				cntOB++; 
				openB = i;
			}
			else{
				cb--;
			}
		}
	}

	ll closeB = str.length(); //'('
	ll cntCB = 0;

	ll ob = 0;

	for(int i = str.length()-1;i>=0;i--){
		if(str[i] == ')'){
			ob++;
		}
		else{
			if(ob == 0){
				cntCB++;
				closeB = i;
			}
			else{
				ob--;
			}
		}
	}

	if(openB > closeB || cntOB != cntCB){
		return 0;
	}
	else{
		ll st = openB + 1;
		ll en = closeB - 1;
		ll ans = 1;
		if(st == 0 && en == str.length() - 1){
			ans = 0;
		}

		stack<char> stk;
		while(st <= en){
			if(str[st] == '('){
				stk.push('(');
			}
			else{
				if(stk.empty()){
					ans = 0;
					break;
				}
				else{
					stk.pop();
				}
			}
			if(stk.empty()){
				ans++;
			}
			st++;
		}

		if(!stk.empty()){
			ans = 0;
		}

		return ans; 
	}

}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	string str;
	cin>>str;

	ll maxValue = 0;
	ll l = 1, r = 1;

	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			//Make new str

			string newstr = str;
			newstr[i] = str[j];
			newstr[j] = str[i];

			//Check cyclical Value
			ll value = findVal2(newstr);
			if(value > maxValue){
				maxValue = value;
				l = i+1;
				r = j+1;
			}
		}
	}

	cout<<maxValue<<endl;
	cout<<l<<" "<<r<<endl;
	return 0;
}