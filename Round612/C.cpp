#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n;
	cin>> n;

	int arr[n];

	ll odd = 0;
	ll even = 0;

	ll oddleft, evenleft;

	REP(i,n){
		cin>>arr[i];
		if(arr[i]%2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}

	if(n%2 == 0){
		oddleft = n/2 - odd;
		evenleft = n/2 - even;
	}
	else{
		oddleft = n/2 + 1 - odd;
		evenleft = n/2 - even;
	}

	vector<ll> odd_odd , even_even;

	ll beginseg = 0;
	ll beginpar = -1;

	ll endsef


	ll odd_even = 0;

	ll size = 0;
	ll before = -1; // 0 is odd 1 is even

	REP(i,n){
		if(arr[i] == 0){
			size++;
		}
		else{
			//If consecutive
			if(size == 0){
				if(arr[i]%2 == 0){
					before =1;
				}
				else{
					before =0;
				}
				continue;
			}
			//if range 
			if(arr[i]%2 == 0){
				if(before == -1 || before == 1){
					even_even.push_back(size);
				}
				else{
					odd_even += size;
				}
				before = 1;
			}
			else{
				if(before == -1 || before == 0){
					odd_odd.push_back(size);
				}
				else{
					odd_even+= size;
				}
				before = 0;
			}
			size = 0;
		}
	}

	//Check size and before to add the last
	if(size != 0 && before != -1){
		if(before == 0){
			odd_odd.push_back(size);
		}
		else{
			even_even.push_back(size);
		}
	}

	ll ans = odd_even;

	sort(odd_odd.begin(),odd_odd.end());
	sort(even_even.begin(),even_even.end());

	REP(i,odd_odd.size()){
		if(oddleft < odd_odd[i]){
			ans += 
		}
		else{
			oddleft -= odd_odd[i];
		}
	}


	return 0;
}