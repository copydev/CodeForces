#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;++i)

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

		sort(arr,arr+n,greater<int>());

		int maxarea = 0;
		int maxHt = INT_MAX;

		REP(i,n){
			maxHt = min(maxHt, arr[i]);
			maxarea = max(maxarea, min(maxHt,i+1));
		}

		cout<<maxarea<<endl;
	}

	return 0;
}