#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;

		ll low = (a-b)*n;

		ll high = (a+b)*n;

		ll lr = c-d;
		ll hr = c+d;


		if(low <= hr && high >= lr){
			cout<<"Yes"<<endl;
			continue;
		}

		cout<<"No"<<endl;
	}

	return 0;
}