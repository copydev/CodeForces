#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {
	int t;
	cin>>t;

	while(t--){

		ll a,b,x,y;
		cin>>a>>b>>x>>y;

		ll maxarea = 0;

		//Up

		ll xlim = x-1;

		if(xlim >= 0){
			maxarea = max(maxarea, (xlim + 1)*b);
		}

		xlim = x+1;

		if(xlim <a){
			maxarea = max(maxarea, (a-xlim)*b);
		}

		ll ylim = y-1;

		if(ylim >= 0){
			maxarea = max(maxarea, (ylim + 1)*a);
		}

		ylim = y+1;
		if(ylim <b){
			maxarea = max(maxarea, (b-ylim)*a);
		}

		cout<<maxarea<<endl;

	}


	return 0;
}