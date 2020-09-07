#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int q;
	cin>>q;

	while(q--){
		int n;
		cin>>n;
		int arr[n];

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		int team = 1;

		for(int i = 1;i<n;i++){
			if((arr[i] - arr[i-1]) == 1){
				team = 2;
				break;
			}
		}

		cout<<team<<endl;
	}



	return 0;
}