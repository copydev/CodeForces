#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int n,k;

		cin>>n>>k;

		int arr[n];

		int mp[n+1] = {0};

		vector<int> pat;

		int distinct = 0;

		REP(i,n){
			cin>>arr[i];
			if(mp[arr[i]] == 0){
				distinct++;
				mp[arr[i]] = 1;
				pat.push_back(arr[i]);
			}
		}

		if(distinct > k){
			cout<<-1<<endl;
			continue;
		}

		int ptr = pat.size();

		while(ptr < k){
			pat.push_back(1);
			ptr++;
		}

		cout<<n*pat.size()<<endl;

		REP(i,n){
			REP(j,pat.size()){

				cout<<pat[j]<<" ";
			}
		}

		cout<<endl;


	}

	return 0;
}