#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		map<int,int> mp;

		int n,x;
		cin>>n>>x;

		int temp;

		for(int i = 0;i<n;i++){
			cin>>temp;
			mp[temp] = 1;
		}

		int num = 1;
		while(x){
			if(!mp[num]){
				x--;
			}
			num++;
		}

		while(mp[num]){
			num++;
		}

		num--;

		cout<<num<<endl;
	}

	return 0;
}