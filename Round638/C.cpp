#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

struct CompareStr { 
    bool operator()(string const& p1, string const& p2) 
    { 	
    	int len = min(p1.length(),p2.length());

    	for(ll i = 0;i<len;i++){
    		if(p1[i] > p2[i]){
    			return true;
    		}
    		else if(p1[i] < p2[i]){
    			return false;
    		}
    	}

    	if(p1.size() == 0){
    		return false;
    	}

    	if(p2.size() == 0){
    		return true;
    	}

    	if(p1.size() < p2.size()){
    		return true;
    	}
    	else{
    		return false;
    	}
       
    } 
}; 

int main() {

	int t;
	cin>>t;

	while(t--){

		// priority_queue< string, vector<string>, CompareStr> pq;
		ll n,k;
		cin>>n>>k;

		string inp;
		cin>>inp;

		ll alpha[26] = {0};
		ll distinct = 0;

		REP(i,n){
			int num = inp[i] - 'a';
			if(alpha[num] == 0){
				distinct++;
			}
			alpha[num]++;
		}

		string ans = "";

		int getStarted = 0;

		ll stk = k;

		ll idx = -1;

		REP(i,26){
			idx++;
			if(alpha[i] == 0){
				continue;
			}

			// cout<<"i:"<<i<<endl;

			
			if(alpha[i] >= k && stk == k){
				ans += 'a' + i;
				alpha[i] -= k;
				getStarted = 1;
				break;
			}
			if(alpha[i] >= stk){
				ans += 'a' + i;
				alpha[i] -= stk;
				break;
			}
			

			
			stk -= alpha[i];
			distinct--;
			
			
		}


		if(getStarted){
			if(alpha[idx] == 0){
				
				distinct--;
			}
			if(distinct == 0){
				cout<<ans<<endl;
				continue;
			}
			//set idx then
			while(alpha[idx] == 0){
				idx++;
			}
			if(distinct == 1){
				double number = alpha[idx];
				double knum = k;
				ll num = ceil(number/knum);
				REP(i,num){
					ans += 'a' + idx;

				}
			}
			else{
				while(idx < 26){
					REP(j,alpha[idx]){
						ans += 'a' + idx;
					}
					idx++;
				}
			}

			cout<<ans<<endl;
		}
		else{
			// cout<<0<<endl;
			cout<<ans<<endl;
		}

		// REP(i,k){
		// 	string s = "";
		// 	pq.push(s);
		// }

		// int arr[n];
		// REP(i,n){
		// 	arr[i] = inp[i] - 'a';
		// }

		// sort(arr,arr+n);

		// REP(i,n){
		// 	char c = 'a' + arr[i];

		// 	string mins = pq.top();
		// 	pq.pop();

		// 	mins += c;

		// 	// cout<<mins<<endl;

		// 	pq.push(mins);
		// }

		// string ans = "";

		// while(!pq.empty()){
		// 	ans = pq.top();
		// 	cout<<ans<<endl;
		// 	pq.pop();
		// }

		// cout<<"ANS:"<<ans<<endl;

		
	}

	return 0;
}