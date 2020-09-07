#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll n;
	
ll arr[200005];
ll vis[200005];
ll ans[200005];

ll findans(ll i, ll par){
	//cout<<"i:"<<i<<endl;
	if(i <0 || i >= n){
		return -1;
	}

	if(par == 0){ // need odd par
		if((arr[i] % 2) != 0){
			return 0;
		}
	}

	if(par == 1){
		if((arr[i] % 2) != 1){
			return 0;
		}
	}

	if(vis[i] == 1){
		return ans[i];
	}

	
	// check par
	
	vis[i] = 1;

	//else
	ll a1 = findans(i - arr[i],par);
	ll a2 = findans(i + arr[i],par);

	ll currans;

	if(a1 == -1 && a2 == -1){
		currans = -1;
	}

	else if(a1 == -1){
		currans = a2 + 1;
	}

	else if(a2 == -1){
		currans = a1 + 1;
	}
	else{
		currans = min(a1,a2) + 1;
	}

	ans[i] = currans;

	return currans;

}

ll printarr(){
	REP(i,n){
		cout<<ans[i]<<",";
	}
	cout<<endl;
}

int main() {

	cin>>n;

	
	REP(i,n){
		cin>>arr[i];
	}

	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));

	REP(i,n){
		if(vis[i] == 0){
			findans(i,arr[i]%2);
		}
		printarr();
	}

	REP(i,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;


	return 0;
}