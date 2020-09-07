#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

ll removeDuplicates(ll arr[], ll n) 
{ 
    // Return, if array is empty 
    // or contains a single element 
    if (n==0 || n==1) 
        return n; 
  
    ll temp[n]; 
  
    // Start traversing elements 
    ll j = 0; 
    for (ll i=0; i<n-1; i++) 
  
        // If current element is not equal 
        // to next element then store that 
        // current element 
        if (arr[i] != arr[i+1]) 
            temp[j++] = arr[i]; 
  
    // Store the last element as whether 
    // it is unique or repeated, it hasn't 
    // stored previously 
    temp[j++] = arr[n-1]; 
  
    // Modify original array 
    for (ll i=0; i<j; i++) 
        arr[i] = temp[i]; 
  
    return j; 
}

int main() {

	ll n;
	cin>>n;

	ll arr[n];

	REP(i,n){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	//find max
	ll maxans = 0;
	unordered_map<ll,ll> maxp;


	REP(i,n){
		if(maxp[arr[i]-1] == 0){
			maxp[arr[i]-1] = 1;
			maxans++;
			continue;
		}

		if(maxp[arr[i]] == 0){
			maxp[arr[i]] = 1;
			maxans++;
			continue;
		}

		maxp[arr[i]+1] = 1;
		maxans++;
	}

	//find min
	ll minans = 0;
	
	//remove duplicate
	// sort(arr,arr+n);

	n = removeDuplicates(arr,n);
	minans = n;

	unordered_map<ll,ll> minp;

	//find triplets
	for(ll i = 1;i<n-1;i++){
		if((arr[i]-1) == arr[i-1] && (arr[i] + 1) == arr[i+1]){
			//cout<<"i"<<i<<endl;
			minp[arr[i]-1] = 1;
			minp[arr[i]+1] = 1;
			minp[arr[i]] = 1;
			minans -= 2;
			i += 1;
		}
	}

	//find doublets
	for(ll i = 0;i<n-1;i++){
		if(!minp[arr[i]]){
			if(!minp[arr[i+1]]){
				//cout<<i<<endl
				if(arr[i+1] == (arr[i] + 1)){
					minans--;
					minp[arr[arr[i+1]]] = 1;
				}
				if(arr[i+1] == (arr[i] + 2)){
					minans--;
					i++;
					minp[arr[arr[i+1]]] = 1;
				}
			}
		}
	}

	cout<<minans<<" "<<maxans<<endl;


	return 0;
}