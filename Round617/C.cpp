#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		map<pair<ll,ll>,ll> mp;

		ll minlen = INT_MAX;
		ll left = -1, right = -1;

		ll lrcnt = 0, udcnt = 0;

		ll n;
		cin>>n;

		string s;
		cin>>s;

		REP(i,s.length()){
			if(s[i] == 'L'){
				lrcnt--;
			}
			if(s[i] == 'R'){
				lrcnt++;
			}
			if(s[i] == 'U'){
				udcnt++;
			}
			if(s[i] == 'D'){
				udcnt--;
			}

			if(lrcnt == 0 && udcnt == 0){
				ll dis = i + 1 - mp[{0,0}];
				if(dis < minlen){
					minlen = dis;
					left = mp[{0,0}] + 1;
					right = i + 1;
				}
			}
			else{
				if(mp[{lrcnt,udcnt}]){
					ll dis = i + 1 - mp[{lrcnt,udcnt}];
					if(dis < minlen){
						minlen = dis;
						left = mp[{lrcnt,udcnt}] + 1;
						right = i + 1;
					}
				}
			}

			mp[{lrcnt,udcnt}] = i+1;
		}

		if(left == -1){
			cout<<-1<<endl;
		}
		else{
			cout<<left<<" "<<right<<endl;
		}
	}

	return 0;
}