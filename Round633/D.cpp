#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int n;
int no_of_children = 0;
int p_of_children = 0;

int minans = 1,maxans;


vector<int> edges[100005];

// vector<int> dis(100005);

vector<int> le(100005);

vector<int> odd(100005), even(100005);


void dfs(int node,int parent){

	int lp = 0;

	le[node] = 1;

	// dis[node] = 1 + dis[parent];
	// cout<<"node"<<node<<endl;
	// cout<<edges[node].size()<<endl;

	REP(i,edges[node].size()){
		// cout<<"I:"<<i<<","<<edges[node].size()<<endl;
		if(edges[node][i] != parent){


			int nextnode = edges[node][i];
			// cout<<"n:"<<node<<"nn:"<<nextnode<<endl;


			dfs(nextnode,node);

			le[node] = 0;
			lp += le[nextnode];

			odd[node] |= even[nextnode];
			even[node] |= odd[nextnode];

		}
	}

	maxans -= max(0,lp-1);
	if(odd[node] && even[node]){
		minans = 3;
	}

	if(le[node]){
		even[node] = 1;
	}
}



int main() {
	
	cin>>n;


	REP(i,n-1){
		int a,b;
		cin>>a>>b;
		// cout<<",";
		// cout<<a<<b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// cout<<"\n"<<edges[3].size()<<endl;;

	//take root node
	//non child

	int rt = 1;

	REP(i,n){
		if(edges[i+1].size() != 1){
			rt = i+1;
			break;
		}
	}

	// cout<<"rt"<<rt<<endl;
	maxans = n-1;

	dfs(rt,0);

	cout<<minans<<" "<<maxans<<endl;


	return 0;
}