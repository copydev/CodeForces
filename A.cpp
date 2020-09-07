#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		ll n, s , k;
		cin>>n>>s>>k;

		vector<ll> places;


		for(ll i = 1; i<= k; i++){
			ll temp;
			cin>>temp;
			places.push_back(temp);
		}

		sort(places.begin(),places.end());

		ll idx = -1;

		for(ll i = 0;i<places.size();i++){
			if(places[i] == s){
				idx = i;
				break;
			}
		}

		if(idx == -1){
			cout<<0<<endl;
		}
		else{

			ll minstep = 10000;

			ll st = s;
			ll idxt = idx;

			//go back
			while(idxt > 0){
				if((st - 1) == places[idxt -1]){
					idxt--;
					st--;
				}
				else{
					minstep = min(minstep, idx - idxt + 1);
					break;
				}
			}

			if(idxt == 0 && places[idxt] != 1){
				minstep = min(minstep, idx + 1);
			}

			st = s;
			idxt = idx;

			while(idxt < places.size()-1){
				if((st + 1) == places[idxt +1]){
					idxt++;
					st++;
				}
				else{
					minstep = min(minstep, idxt + 1 - idx);
					break;
				}
			}

			if(idxt == places.size()-1 && places[idxt] != n){
				minstep = min(minstep, idxt + 1 - idx);
			}

			cout<<minstep<<endl;

		}

		

	}

	return 0;
}