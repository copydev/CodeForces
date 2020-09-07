#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin>>n;

	//ll arr[n];
	ll num;
	ll odd = 0, even = 0;

	for(int i = 0;i<n;i++){
		cin>>num;
		if(num%2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}

	cout<<min(even,odd)<<endl;


	return 0;
}
