#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int a1, a2, k1, k2, n;

	cin>>a1>>a2>>k1>>k2>>n;

	//for min

	ll maxredcard = a1 * (k1 - 1) + a2 * (k2 - 1);
	ll minpep = n - maxredcard;
	if(minpep < 0){
		minpep = 0;
	} 

	//for max

	ll bigk, biga, smallk, smalla;

	if(k1 > k2){
		bigk = k1;
		biga = a1;
		smalla = a2;
		smallk = k2;
	}
	else{
		bigk = k2;
		biga = a2;
		smallk = k1;
		smalla = a1;
	}

	ll ans = 0;

	ans = min(n/smallk, smalla);

	n -= ans * smallk;

	ans += min(n/bigk, biga);

	cout<<minpep<<" "<<ans<<endl;


	return 0;
}