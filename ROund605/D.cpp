#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	ll arr[n];
	REP(i,n){
		cin>>arr[i];
	}

	ll remidx = -1;
	ll ans = 1;
	ll subs = 1;

	for(ll i = 1;i< n;i++){
		if(arr[i] > arr[i-1]){
			subs++;
		}
		else{
			// subs = i - remidx - 1;
			// remidx = i - 1;
			// if(i != 1){
			// 	if(arr[i] <= arr[i-2]){
			// 		subs = 1;
			// 	}
			// }

			// part 1 skip prev ele
			if(i != 1){
				if(arr[i] > arr[i-2]){
					subs = i - remidx - 1;
					remidx = i - 1;
					continue;
				}
				else{
					subs = i - remidx - 1;
					remidx = i;

					//do a check
					//if next element doesn't support this tranformation

					if(i + 1 < n){
						if(arr[i-1] < arr[i+1]){
							continue;
						}
						else{
							if(arr[i] < arr[i+1]){
								remidx = i - 1;
								subs = 1;
							}
							else{
								i++;
								remidx = i - 1;
								subs = 1;
							}
						}

					}
				}
			}
			else{
				remidx = 0;
				subs = 1;
			}

		}
		//cout<<"i:"<<i<<","<<subs<<endl;
		ans  = max(ans, subs);
	}

	cout<<ans<<endl;

	return 0;
}