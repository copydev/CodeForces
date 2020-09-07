#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

vector<int> edges[200005];


struct Node{
	int parent;
	int node;
	int depth;
	int succ;

	bool operator<(const Node &b) const{
		return (this->depth - this->succ) > (b.depth - b.succ);
	}


};

Node node[200005];

struct cmp{
	bool operator() (Node &a, Node &b) const{
		return (a.depth - a.succ) > (b.depth - b.succ);
	}
};

multiset<Node> treenode;

int dfs(int idx, int parent, int depth){


	node[idx].node = idx;
	node[idx].depth = depth;
	node[idx].parent = parent;
	node[idx].succ = 0;

	int number_of_children = 0;

	int leaf = 1;

	for(int i = 0;i<edges[idx].size();i++){

		if(parent != edges[idx][i]){

			leaf = 0;
			number_of_children += dfs(edges[idx][i],idx,depth+1);
		}
	}

	
	node[idx].succ = number_of_children;

	// cout<<"idx"<<idx<<endl;


	treenode.insert(node[idx]);

	return (1 + number_of_children);
	
}

int main() {

	int n,k;
	cin>>n>>k;

	REP(i,n-1){
		ll a,b;
		cin>>a>>b;

		// cout<<a<<b<<endl;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	ll ans = 0;

	dfs(1,1,0);

	int ik = 0;

	for(auto idx = treenode.begin();ik<k;ik++,idx++){
		ans += idx->depth - idx->succ;
		// cout<<"idx"<<idx->node<<endl;
	}

	cout<<ans<<endl;


	return 0;
}