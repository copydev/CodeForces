#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll a,b,p;
		cin>>a>>b>>p;

		string s;
		cin>>s;

		ll money = 0;
		ll idx = s.length()-2;

		if(s[idx] == 'A'){
			money = a;
		}
		else{
			money = b;
		}

		idx--;

		// cout<<money<<endl;

		if(money > p){
			cout<<s.length()<<endl;
			continue;
		}

		while(idx >= 0){
			// cout<<"I:"<<idx<<":"<<money<<endl;
			// cout<<s[idx]<<endl;

			if(s[idx] == s[idx+1]){
				idx--;
			}
			else{
				if(s[idx] == 'A'){
					money += a;
				}
				else{
					money += b;
				}

				if(money > p){
					break;
				}
				idx--;
			}
		}

		// cout<<idx<<endl;
		idx++;

		cout<<idx+1<<endl;

	}

	return 0;
}
