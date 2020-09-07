#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll x,y,a,b;
		cin>>x>>y>>a>>b;

		ll dist = y - x;
		ll speed = a+b;

		if(dist%speed != 0){
			cout<<-1<<endl;
		}
		else{
			cout<<dist/speed<<endl;
		}
	}

	return 0;
}