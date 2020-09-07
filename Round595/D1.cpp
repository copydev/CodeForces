#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	int n,k;
	cin>>n>>k;
	unordered_map<int,int> mp;

	pair<int,int> pt[n];
	for(int i = 0;i<n;i++){
		cin>>pt[i].first>>pt[i].second;

		for(int j = pt[i].first ;j <= pt[i].second ; j++){
			mp[j]++;
		}
	}


	for(int i = 0;i<n;i++){
		
	}

	


	return 0;
}