#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n,a,b,k;

	cin>>n>>a>>b>>k;

	ll arr[n];
	ll rem[n];

	ll ans = 0;

	REP(i,n){
		cin>>arr[i];

		ll left = arr[i]%(a+b);
		if(left == 0){
			left = a + b;
		}

		rem[i] = left;
	}

	sort(rem,rem+n);

	REP(i,n){
		if(rem[i] <= a){
			ans++;
		}
		else{
			if(rem[i] % a == 0){
				if(k >= ((rem[i]/a) - 1)){
					k -= ((rem[i]/a) - 1);
					ans++;
				}
			}
			else{
				if(k >= (rem[i]/a)){
					k -= (rem[i]/a);
					ans++;
				}
			}
		}
		if(k <= 0){
			break;
		}
	}

	cout<<ans<<endl;



	return 0;
}