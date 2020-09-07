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

		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}

		int start[n] = {0};
		int end[n] = {0};

		map<int,int> stmap;
		int chk = 1;

		for(int i = 0;i<n;i++){
			stmap[arr[i]] = 1;
			while(stmap[chk] == 1){
				chk++;
			}

			if((chk-1) == (i+1)){
				start[i] = 1;
			} 
		}

		map<int,int> revmap;
		chk = 1;

		for(int i = n-1;i>= 0;i--){
			revmap[arr[i]] = 1;
			while(revmap[chk] == 1){
				chk++;
			}

			if((chk - 1) == (n - i)){
				end[i] = 1;
			}
		}

		vector<vector<int>> ans;

		for(int i = 0;i<n-1;i++){
			if(start[i] && end[i+1]){
				vector<int> temp; 
				temp.push_back(i+1);
				temp.push_back(n-i-1);
				ans.push_back(temp);
			}
		}

		cout<<ans.size()<<endl;

		for(int i = 0;i<ans.size();i++){
			cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
		}

	}

	return 0;
}