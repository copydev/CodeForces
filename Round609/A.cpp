#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)


int main() {

	ll n;
	cin>>n;

	bool prime[100000]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=100000; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers
    //cout<<prime[8]<<prime[9]<<endl; 
    
    for(ll i = 4;i<= 1000000;i++){
    	if(prime[i] == true){
    		continue;
    	}
    	ll a = i;
    	ll b = abs(a - n);
    	cout<<prime[a]<<prime[b]<<endl; 
    	if(prime[b] == false){
    		cout<<a<<" "<<b<<endl;
    		break;
    	}
    }


	return 0;
}