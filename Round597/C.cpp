#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0; i<n;++i)
#define mod 1000000007ll

long long modMul(long long a, 
                            long long b) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 


int main() {

	ll memo[100005];
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 3;

	for(ll i = 4;i<100005;i++){
		memo[i] = 2 * memo[i-2] + memo[i-3];
		memo[i] = memo[i] % mod;

	}

	// cout<<memo[100004]<<endl;

	//Sub 1 from all

	string s;
	cin>>s;
	ll n = s.length();

	REP(i,n){
		if(s[i] == 'm' || s[i] == 'w'){
			cout<<0<<endl;
			return 0;
		}
	}

	ll ans = 1;

	//find n rep
	REP(i,n){
		if(s[i] == 'n'){
			ll j = i+1;
			ll cnt = 1;
			while(j<n && s[j] == 'n'){
				cnt++;
				j++;
			}

			//cout<<cnt<<endl;
			i = j-1;
			ans = modMul(memo[cnt],ans);
			// ans = ans % mod;
		}
	}

	REP(i,n){
		if(s[i] == 'u'){
			ll j = i+1;
			ll cnt = 1;
			while(j<n && s[j] == 'u'){
				cnt++;
				j++;
			}
			//cout<<cnt<<endl;

			i = j-1;
			ans = modMul(memo[cnt],ans);
			// ans = ans % mod;
		}
	}

	// if(ans<0){
	// 	ans = (ans + mod) % mod;
	// }

	cout<<ans<<endl;

	return 0;
}