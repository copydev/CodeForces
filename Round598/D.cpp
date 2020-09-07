#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll q;
	cin>>q;
	while(q--){
		ll n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll idx = 0;
		ll onedx = 0;

		while(onedx < n && s[onedx] != '1'){
			onedx++;
		}

		idx = onedx;

		while(idx < n && k){
			//find 0
			//ll cntone = 0;
			ll zidx = idx;

			while(zidx < n && s[zidx] != '0' ){
				zidx++;
			}

			if(zidx >= n){
				break;
			}

			if(k >= (zidx - onedx)){
				s[zidx] = '1';
				s[onedx] = '0';
				k -= zidx - onedx;
			}
			else{

				s[zidx] = '1';
				s[zidx - k] = '0';
				break;
			}
			idx = zidx + 1;
			onedx++;

		}

		cout<<s<<endl;
	}
	return 0;
}