#include <bits/stdc++.h>
using namespace std;
#define ll int
#define REP(i,n) for(ll i = 0;i<n;++i)


// ll tin[siz],tout[siz], tlvl[siz], parents[siz];
// ll t = 0;

// void dfs(ll node,ll p, ll lvl){
// 	parents[node] = p;
// 	tlvl[node] = lvl;
// 	++t;
// 	tin[node] = t;

// 	for(ll i =0;i<tree[node].size();++i){
// 		if(tree[node][i] != p){
// 			dfs(tree[node][i],node,lvl+1);
// 		}
// 	}

// 	++t;
// 	tout[node] = t;
// }

// bool ifAncestor(ll a,ll b){ // if b ancestor of a
// 	return tin[b] <= tin[a] && tout[b] >= tout[a];
// }

// ll getLCS(ll a,ll b){

// 	if(ifAncestor(a,b)){
// 		return b;
// 	}

// 	if(ifAncestor(b,a)){
// 		return a;
// 	}

// 	while(!ifAncestor(b,a)){
// 		a = parents[a]; // the next parent
// 	}

// 	return a;

// }


void dfs(ll u, ll p, ll **memo, ll *lev, ll log, vector<ll> *g) 
{ 
    // Using recursion formula to calculate 
    // the values of memo[][] 
    memo[u][0] = p; 
    for (ll i = 1; i <= log; i++) 
        memo[u][i] = memo[memo[u][i - 1]][i - 1]; 
    for (ll v : g[u]) 
    { 
        if (v != p) 
        { 
            lev[v] = lev[u] + 1; 
            dfs(v, u, memo, lev, log, g); 
        } 
    } 
} 
  
// Function to return the LCA of nodes u and v 
ll lca(ll u, ll v, ll log, ll *lev, ll **memo) 
{ 
    // The node which is present farthest 
    // from the root node is taken as u 
    // If v is farther from root node 
    // then swap the two 
    if (lev[u] < lev[v]) 
        swap(u, v); 
  
    // Finding the ancestor of u 
    // which is at same level as v 
    for (ll i = log; i >= 0; i--) 
        if ((lev[u] - pow(2, i)) >= lev[v]) 
            u = memo[u][i]; 
  
    // If v is the ancestor of u 
    // then v is the LCA of u and v 
    if (u == v) 
        return u; 
  
    // Finding the node closest to the root which is 
    // not the common ancestor of u and v i.e. a node 
    // x such that x is not the common ancestor of u 
    // and v but memo[x][0] is 
    for (ll i = log; i >= 0; i--) 
    { 
        if (memo[u][i] != memo[v][i]) 
        { 
            u = memo[u][i]; 
            v = memo[v][i]; 
        } 
    } 
  
    // Returning the first ancestor 
    // of above found node 
    return memo[u][0]; 
} 

ll getDis(ll a,ll b, ll * lev, ll log, ll ** memo){
	if(a == b){
		return 0;
	}

	// a------->b
	//Lvl(a) + Lvl(b) - 2 * Lvl(LCS(a,b))

	ll dis = lev[a] + lev[b] - 2 * lev[lca(a,b,log,lev,memo)];

	return dis;
}



int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	ll n;
	cin>>n;

	vector<ll> tree[n];


	REP(i,n-1){
		ll a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	ll log = (ll)ceil(log2(n)); 
    ll **memo = new ll *[n + 1]; 
    for (ll i = 0; i < n + 1; i++) 
        memo[i] = new ll[log + 1]; 
  
    // Stores the level of each node 
    ll *lev = new ll[n + 1]; 
  
    // Initialising memo values with -1 
    for (ll i = 0; i <= n; i++) 
        memset(memo[i], -1, sizeof memo[i]);

	dfs(1, -1, memo, lev, log, tree); 

	// REP(i,n+1){
	// 	cout<<parents[i]<<endl;
	// }

	ll q;
	cin>>q;

	while(q--){
		// cout<<q<<endl;
		ll x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;

		//get a->b 
		ll dis = getDis(a,b,lev,log,memo);
		// cout<<"Dis1"<<dis<<endl;

		if(dis <= k && (dis & 1) == (k&1)){
			cout<< "YES"<<endl;
			continue;
		}

		// a->x ... y->b

		dis = getDis(a,x,lev,log,memo) + getDis(b,y,lev,log,memo) + 1;
		// cout<<"Dis2"<<dis<<endl;

		if(dis <= k && (dis & 1) == (k&1)){
			cout<< "YES"<<endl;
			continue;
		}

		// a->y .. x->b
		dis = getDis(a,y,lev,log,memo) + getDis(x,b,lev,log,memo) + 1;
		// cout<<"Dis3"<<dis<<endl;
		if(dis <= k && (dis & 1) == (k&1)){
			cout<< "YES"<<endl;
			continue;
		}

		cout<<"NO"<<endl;
	}


	return 0;
}