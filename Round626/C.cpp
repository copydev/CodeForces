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

		string x;
		cin>>x;

		string a,b;

		a = '1';
		b = '1';

		//a is the sacrificing string

		ll flag = 1;

		for(ll i = 1;i<n;i++){
			if(x[i] == '0'){
				a += '0';
				b += '0';
			}
			if(x[i] == '1'){
				if(flag){
					a += '1';
					b += '0';
					flag = 0;
				}
				else{
					a += '0';
					b += '1';
				}
			}
			if(x[i] == '2'){
				if(flag){
					a += '1';
					b += '1';
				}
				else{
					a += '0';
					b += '2';
				}
			}
		}

		cout<<a<<endl;
		cout<<b<<endl;

	}

	return 0;
}