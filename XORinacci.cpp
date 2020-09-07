#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		ll a, b, n, c;
		cin>>a>>b>>n;
		c = a^b;
		if(n%3 == 0){
			cout<<a<<endl;
		}
		else if (n%3 == 1){
			cout<<b<<endl;
		}
		else {
			cout<<c<<endl;
		}
	}
	return 0;
}