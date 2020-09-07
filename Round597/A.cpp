#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0; i<n;++i)

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  

}


int main() {

	int t;
	cin>>t;
	while(t--){
		int a , b;
		cin>>a>>b;
		if(a==1 || b==1){
			cout<<"Finite"<<endl;
			continue;
		}

		int ans = gcd(a,b);

		if(ans == 1){
			cout<<"Finite"<<endl;
		}
		else{
			cout<<"Infinite"<<endl;
		}


	}

	return 0;
}