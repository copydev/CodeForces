#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;

		int arr[n];
		REP(i,n){
			cin>>arr[i];
		}

		ll idx = 0;
		
		while(idx < n){
			int min = arr[idx];
			int minidx = idx;
			for(int i = idx;i <n;i++){
				if(min > arr[i]){
					min = arr[i];
					minidx = i;
				}
			}

			//cout<<"m:"<<minidx<<endl;
			int tempidx = minidx;
			while(minidx != idx){
				int temp = arr[minidx];
				arr[minidx] = arr[minidx-1];
				arr[minidx-1] = temp;
				minidx--;
				
			}
			if(idx == tempidx){
				idx++;
			}
			else{
				idx = tempidx;
			}
		}

		REP(i,n){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}