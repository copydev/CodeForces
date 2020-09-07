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

		sort(arr,arr+n);

		int ans[n-1];

		int i = 0, j = n-1;

		REP(idx,n){
			if(idx%2 == 0){
				ans[idx] = arr[i];
				i++;
			}
			else{
				ans[idx] = arr[j];
				j--;
			}
		}

		REP(i,n){
			cout<<ans[n-i-1]<<" ";
		}

		cout<<endl;

	}

	return 0;
}