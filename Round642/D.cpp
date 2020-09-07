#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

struct Compare{

	bool operator() (pair<int,int>& p1, pair<int,int>& p2){
		int diff1 = p1.second - p1.first;
		int diff2 = p2.second - p2.first;

		if(diff1 == diff2){
			return p1.first > p2.first;
		}
		else{
			return diff1 < diff2;
		}
	}
};

int main() {

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> arr(n);

		priority_queue<pair<int,int>, vector<pair<int,int>>,Compare> pq;

		// pq.push({1,2});
		// pq.push({3,4});
		// cout<<"p:"<<pq.top().first<<endl;

		pq.push({0,n-1});

		int idx = 1;

		while(idx <= n){
			pair<int,int> p = pq.top();
			pq.pop();

			// cout<<p.first<<","<<p.second<<endl;

			int diff = p.first + (p.second - p.first)/2;
			// cout<<diff<<endl;
			arr[diff] = idx;
			idx++;

			if(p.first != (diff)){
				pq.push({p.first,diff-1});
			}

			if(p.second != (diff)){
				pq.push({diff+1,p.second});
			}
		}

		REP(i,n){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}