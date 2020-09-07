#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		double n ,d;
		cin>>n>>d;

		if(n >= d){
			cout<<"YES"<<endl;
		}
		else{
			double x = 1;
			ll D = (n - x) - ceil(d/(x+1));

			while(D < 0 && x < 1000000){
				x++;
				// cout<<"X"<<x<<endl;
				ll newD = (n - x) - ceil(d/(x+1));
				// if(newD <= D){
				// 	break;
				// } 
				// cout<<"newD"<<newD<<endl;
				// cout<<"D"<<D<<endl;

				D = newD;

			}

			if(D < 0){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
	}

	return 0;
}