#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		sort(arr,arr+n, greater<int>());

		REP(i,n){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}