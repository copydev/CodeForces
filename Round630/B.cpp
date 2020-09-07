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

		for(int i = 0; i<n;i++){
			cin>>arr[i];
		}	

		int color[n];

		memset(color,-1,sizeof(color));	

		sort(arr,arr+n);

		int col = 0;

		for(int i = 0;i<n;i++){
			if(color[i] != -1){
				continue;
			}
			col++;
			color[i] = col;
			for(int j = i+1;j<n;j++){
				int g = __gcd(arr[i],arr[j]);
				if(g > 1){
					color[j] = col;
				}
			}
		}

		cout<<col<<endl;

		REP(i,n){
			cout<<color[i]<<" ";
		}
		cout<<endl;

	}

	return 0;
}	