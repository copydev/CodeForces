#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	string a,b;
	cin>>a>>b;

	ll same = 0, ab = 0, ba = 0;

	vector<ll> samev;

	vector<ll> abv , bav;

	REP(i,n){
		if(a[i] == b[i]){
			same++;
			samev.push_back(i);
		}
		else if( a[i] == 'a' & b[i] == 'b'){
			ab++;
			abv.push_back(i);
		}
		else {
			ba++;
			bav.push_back(i);
		}
	}

	ll ans = 0;

	ans += ab/2 + ba/2;

	ab = ab%2;
	ba = ba%2;

	if(ab && ba){
		if(same > 0){
			ans += 2;
		}
		else{
			ans += 3;
		}
	}

	if(ab || ba){
		cout<<-1<<endl;
		return 0;
	}

	cout<<ans<<endl;

	ll absize = (abv.size() %2) == 0 ? abv.size() : abv.size() - 1;
	ll basize =  



	return 0;
}