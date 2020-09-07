#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

bool checkpath(string &s){
	
	map<pair<ll,ll>, ll> mp;

	ll x =0, y= 0;

	REP(i,s.length()){
		if(s[i] == 'U'){
			y++;
		}
		if(s[i] == 'D'){
			y--;
		}
		if(s[i] == 'R'){
			x++;
		}
		if(s[i] == 'L'){
			x--;
		}
		if(mp[{x,y}] == 1){
			return false;
		}
		else{
			mp[{x,y}]++;
		}
	}

	if(x == 0 && y == 0){
		return true;
	}
	else{
		return false;
	}

}

int main() {

	ll t;
	cin>>t;
	while(t--){

		string s;
		cin>>s;

		//check if s is good
		if(checkpath(s)){
			cout<<s.length()<<endl;
			cout<<s<<endl;
		}
		else{

			//count L R U D
			ll l = 0,r = 0,u = 0,d = 0;
			REP(i,s.length()){
				if(s[i] == 'L'){
					l++;
				}
				if(s[i] == 'R'){
					r++;
				}
				if(s[i] == 'U'){
					u++;
				}
				if(s[i] == 'D'){
					d++;
				}
			}

			ll minlr , minud;

			minlr = min(l,r);
			minud = min(u,d);

			string ans = "";

			if(minlr >0 && minud > 0){
				cout<<(minlr + minud)*2<<endl;
				REP(i,minud){
					ans += 'U';
				}
				REP(i,minlr){
					ans += 'R';
				}
				REP(i,minud){
					ans += 'D';
				}
				REP(i,minlr){
					ans += 'L';
				}
				cout<<ans<<endl;
			}

			else if(minlr > 0){
				cout<<2<<endl;
				cout<<"LR"<<endl;
			}
			else if(minud > 0){
				cout<<2<<endl;
				cout<<"UD"<<endl;
			}
			else{
				cout<<0<<endl;
			}

		}
	}


	return 0;
}