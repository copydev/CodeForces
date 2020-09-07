#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;

		ll moves = 0;

		if(a>0){
			moves++;
			a--;
		}

		if(b>0){
			moves++;
			b--;
		}

		if(c>0){
			moves++;
			c--;
		}

		if(a>c){
			swap(a,c);
		}
		if(b>c){
			swap(b,c);
		}

		if(a>0 && c>0){
			moves++;
			a--;
			c--;
		}

		if(b>0 && c>0){
			moves++;
			b--;
			c--;
		}

		if(a>0 && b>0){
			moves++;
			a--;
			b--;
		}

		if(a>0 && b>0 && c>0){
			moves++;
		}

		cout<<moves<<endl;
	}

	return 0;
}