#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {
	int a;
	cin>>a;

	while(a--){
		string s;
		cin>>s;

		ll sum = 0;
		ll even = 0;
		ll zero = 0;

		//remove leading zeros

		int idx = 0;

		while(s[idx] == '0'){
			zero = 1;
			idx++;
		}

		if(idx == s.length()){
			cout<<"red"<<endl;
			continue;
		}

		//now check for params

		

		while(idx != s.length()){
			ll num = (s[idx] - '0');
			sum += num;
			idx++;
			//cout<<"n:"<<num<<endl;
			if(num == 0 && zero == 0){
				zero = 1;
				continue;
			}

			if((num % 2) == 0){
				even = 1;
			}
			
		}

		//cout<<zero<<even<<sum<<endl;

		if(zero && even && ((sum % 3) == 0)){
			cout<<"red"<<endl;
		}
		else{
			cout<<"cyan"<<endl;
		}
	}
	return 0;
}