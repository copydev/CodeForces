#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int n,m;

struct node{
	int val;
	int lvl;
};

int memo[200005][20];

vector<int> edges[200005];

vector<int> parent(200005);

vector<int> lvl(200005);

void initialise(int idx,int p,int level){
	parent[idx] = p;
	lvl[idx] = level;

	// cout<<"i:"<<idx<<"parent"<<parent[idx]<<"lvl"<<lvl[idx]<<endl;

	REP(i,edges[idx].size()){
		if(edges[idx][i] != p){
			initialise(edges[idx][i],idx,level+1);
		}
	}
}

int comp(int &a, int &b){
	return lvl[a] < lvl[b];
}

void dfs(int idx,int p){
	memo[idx][0] = p;

	for(int i = 1;i<20;i++){
		memo[idx][i] = memo[memo[idx][i-1]][i-1];
	}

	for(int i=0; i<edges[idx].size();i++){
		if(edges[idx][i] != p){
			dfs(edges[idx][i],idx);
		}
	}
}

int findlca(int n1,int n2){

	// binary lifting
	// if(n1 == n2){

	// }

	if(lvl[n1] < lvl[n2]){
		swap(n1,n2);
	}

	for(int i = 19;i >= 0; i--){
		if(lvl[n1] - pow(2,i) >= lvl[n2]){
			n1 = memo[n1][i];
		}
	}

	if(n1 == n2){
		return n1;
	}
	else{
		return 0;
	}


}


int main() {
	
	cin>>n>>m;

	REP(i,n-1){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// cout<<"ok"<<endl;

	initialise(1,1,0);

	memset(memo,0,sizeof(memo));

	dfs(1,1);

	while(m--){
		int p;
		cin>>p;

		int arr[p];
		REP(i,p){
			cin>>arr[i];
			arr[i] = parent[arr[i]];
		}

		sort(arr,arr+p,comp);

		// REP(i,p){
		// 	cout<<arr[i]<<",";
		// }
		// cout<<endl;

		int node = 1;
		int ans = 1;

		int idx = 1;

		while(idx < p){
			int lca = findlca(arr[idx-1],arr[idx]);
			if(arr[idx-1] != lca){
				ans = 0;
				break;
			}
			idx++;
		}



		if(ans){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}

	}



	return 0;
}