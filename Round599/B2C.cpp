#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

//Ini Condition

bool condI(string a, string b){
	ll arr[26];
	memset(arr,0,sizeof(arr));

	REP(i,a.size()){
		arr[a[i] - 'a']++;
		arr[b[i] - 'a']++;
	}

	REP(i,26){
		if((arr[i] % 2) != 0){
			return false;
		}
	}

	return true;
}

int main() {

	int t;
	cin>>t;

	

	while(t--){

		ll n;
		cin>>n;

		string s, t;
		cin>>s>>t;

		if(!condI(s,t)){
			cout<<"No"<<endl;
			continue;
		}

		//Start with index 0 to n-1

		REP(i,n){
			if(s[i] == t[i]){
				continue;
			}

			ll index = -1;

			//find in t the best change
			for(ll j = i+1; j<n;j++){
				if(t[i] == t[j] && s[j] != t[j]){
					index = j;
					if(s[j] == s[i]){
						break;
					}
				}
			}

			if(index != -1){
				//swap
				swap(s[i],t[index]);
			}
			else{
				//find in s the best change
				index = -1;
				for(ll j = i+1; j<n;j++){
					if(t[i] == s[j] && s[j] != t[j]){
						index = j;
						if(s[i] == t[j]){
							break;
						}
					}
				}

				//if not found suitable component yet
				
		}


	}

	return 0;
}