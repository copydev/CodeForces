#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)
#define MOD 998244353
#define mod 998244353

ll modpow(ll n, ll k){
	if(k == 0){
		return 1;
	}

	if(k == 1){
		return n;
	}

	if(k%2 == 0){
		ll ans = modpow(n,k/2);
		ans = ans%mod;
		return (ans*ans) % mod;
	}

	else{
		return (n * modpow(n,k-1)) % mod;
	}
}



int main() {

	ll n,m;

	cin>>n>>m;

	if(n == 2){
		cout<<0<<endl;
		return 0;
	}

	ll fact[m+1];
	fact[0] = 1;
	for(ll i = 1;i<=m ;i++){
		fact[i] = fact[i-1] * i;
		fact[i] = fact[i] % mod;
	}

	// ll peakplaces = n-2; 

	// ll restplaces =  peakplaces; // n - 1 for ignoring the duplicate element and -1 for peak

	ll ans = fact[m];

	ans = ans * modpow(fact[n-1],mod-2);

	ans = ans%mod;

	ans = ans * modpow(fact[m - n + 1],mod-2);

	ans = ans%mod;

	ans *= (n-2);

	ans = ans % mod;

	ans = ans * modpow(2,n-3);

	ans = ans % mod;	

	cout<<ans<<endl;

	return 0;
}