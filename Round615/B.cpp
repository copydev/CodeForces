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

		vector<pair<ll,ll>> cxy(n);

		REP(i,n){
			ll x,y;
			cin>>x>>y;
			cxy[i] = {x,y};
		}

		sort(cxy.begin(),cxy.end());

		string ans = "";

		ll prevx = 0;
		ll prevy = 0;

		ll poss = 1;

		REP(i,n){
			if(cxy[i].first >= prevx && cxy[i].second >= prevy){
				while(prevx < cxy[i].first){
					ans += 'R';
					prevx++;
				}

				while(prevy < cxy[i].second){
					ans += 'U';
					prevy++;
				}
			}
			else{
				poss = 0;
				break;
			}
		}

		if(poss){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}

	return 0;
}