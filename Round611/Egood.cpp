#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)
#define sze 200010


int main() {

	ll n;
	cin>>n;

	ll arr[n];

	REP(i,n){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	ll places[n + 2];
	memset(places,0,sizeof(places));

	//big place

	ll maxans = 0;

	REP(i,n){
		if(places[arr[i]-1] == 0){
			places[arr[i]-1]++;
			maxans++;
			continue;
		}
		if(places[arr[i]] == 0){
			places[arr[i]]++;
			maxans++;
			continue;
		}

		if(places[arr[i]+1] == 0){
			maxans++;
		}
		places[arr[i]+1]++;

		// cout<<"i"<<endl;
	}

	// for min ans


	// unordered_map<ll,ll> minp;

	// n = removeDuplicates(arr,n);
	// ll minans = n;

	// REP(i,n){
	// 	cout<<arr[i]<<",";
	// }

	// for(ll i = 1;i<n-1;i++){
	// 	if((arr[i]-1) == arr[i-1] && (arr[i] + 1) == arr[i+1]){
	// 		//cout<<"i"<<i<<endl;
	// 		minp[arr[i]-1] = 1;
	// 		minp[arr[i]+1] = 1;
	// 		minp[arr[i]] = 1;
	// 		minans -= 2;
	// 		cout<<"i:"<<i<<endl;
	// 		i += 1;
	// 	}
	// }

	// //find doublets
	// for(ll i = 0;i<n-1;i++){
	// 	if(!minp[arr[i]]){
	// 		if(!minp[arr[i+1]]){
	// 			//cout<<i<<endl
	// 			if(arr[i+1] == (arr[i] + 1)){
	// 				minans--;
	// 				minp[arr[arr[i+1]]] = 1;
	// 			}
	// 			if(arr[i+1] == (arr[i] + 2)){
	// 				minans--;
	// 				i++;
	// 				minp[arr[arr[i+1]]] = 1;
	// 			}
	// 		}
	// 	}
	// }

	ll places2[n+2];

	ll minans = 0;

	memset(places2,0,sizeof(places2));

	REP(i,n){
		if(!places2[arr[i]]){
			places2[arr[i]] = 1;
		}	
	}

	REP(i,n+1){
		if(places2[i]){
			minans++;
			i+=2;
		}
	}


	cout<<minans<<" "<<maxans<<endl;

	return 0;
}
