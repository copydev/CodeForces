#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll powOptimized(ll k, ll n){
	if(n == 0){
		return 1;
	}

	if(n == 1){
		return k;
	}

	ll num = powOptimized(k, n/2);

	if(n%2 == 0){
		return num*num;
	}
	else{
		return num*num*k;
	}
}

ll findkpower(ll sum, int k){
	ll temp = 1;
	int pow = 0;
	while(temp < sum){
		pow++;
		temp *= k;
	}

	return pow;
}

int main() {

	int t;
	cin>>t;

	while(t--){

		int n,k;
		cin>>n>>k;

		ll maxnum = 0;

		priority_queue<ll> pq;

		REP(i,n){
			ll temp;
			cin>>temp;

			if(temp > 0){
				pq.push(temp);
			}

			maxnum = max(maxnum,temp);
		}	

		int kpower;

		//find kpower

		kpower = findkpower(maxnum, k);

		while(!pq.empty() && kpower >= 0){
			
			ll num = pq.top();
			pq.pop();

			while(powOptimized(k,kpower) > num){
				kpower--;
			}

			if(kpower < 0){
				break;
			}

			num -= powOptimized(k,kpower);
			if(num != 0){
				pq.push(num);
			}

			kpower--;

		}

		if(pq.size() != 0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}

	return 0;
}