#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)


ll a,b;

int bcustom(){
	ll low = 0, high = a;

	int method = 0;
	if(a > b/2){
		method = 0;
	}
	else{
		method = 1;
	}

	while(low <= high){
		
		ll mid = (high + low)/2;

		if(method){

			if((a - mid)*2 == (b - 2 * mid)){
				return 1;
			} 

			if((a - mid)*2 > (b - 2 * mid)){
				high = mid - 1;
			}
			else{
				high = mid + 1;
			}

		}	
		else{

			if((a - 2*mid)*2 == (b - mid)){
				return 1;
			} 

			if((a - 2*mid)*2 > (b - mid)){
				high = mid - 1;
			}
			else{
				high = mid + 1;
			}

		}

	}
	
	return 0;
}

int main() {

	int t;
	cin>>t;
	while(t--){

		cin>>a>>b;

		if(a > b){
			swap(a,b);
		}

		// a is always small
		// bsearch an element so that the difference between them makes it 2a = b
		// an element will lie between 0 to a

		int ans = bcustom();
	}

	return 0;
}