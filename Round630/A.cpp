#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;

		ll x,y;
		cin>>x>>y;

		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;

		if(x1 == x2){
			if(a > 0 || b > 0){
				cout<<"No"<<endl;
				continue;
			}
		}

		if(y1 == y2){
			if(c > 0 || d > 0){
				cout<<"No"<<endl;
				continue;
			}
		}

		ll lr = x + b-a;
		ll ud = y + d-c;

		if(x1 <= lr && lr <= x2 && y1 <= ud &&  ud <= y2){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}