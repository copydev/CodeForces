#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

vector<int> find_step(int arr[], int n){
	vector<int> ans;
	for(int i = 0;i<n-1;i++){
		if(arr[i] == 1 && arr[i+1] == 0){
			ans.push_back(i);
		}
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k;

	cin>>n>>k;

	string s;
	cin>>s;

	int arr[s.length()];

	REP(i,s.length()){
		if(s[i] == 'R'){
			arr[i] = 1;
		}
		else{
			arr[i] = 0;
		}
	}

	int maxi = 0;

	int mini = 0;

	int last = 0;
	int cnt = 0;

	for(int i = n-1; i>=0;i--){
		if(arr[i] == 0){
			cnt++;
		}
		else{
			maxi += cnt;
			mini = min(cnt,last+1);
			last = mini;
		}
	}

	// cout<<mini<<","<<maxi<<endl;

	if(maxi < k || mini > k){
		cout<<-1<<endl;
		return 0;
	}

	bool min_reach = false;

	vector<int> min_step;

	for(int i = 0;i<k;++i){
		
		if(!min_reach){
			vector<int> steps = find_step(arr,n);
			vector<int> ans;
			ll ptr = 0;
			while(maxi > (k - i - 1) && ptr < steps.size()){

				ans.push_back(steps[ptr]);

				arr[steps[ptr]] = 0;
				arr[steps[ptr]+1] = 1;

				// REP(m, n){
				// 	cout<<arr[m]<<",";
				// }
				// cout<<endl;


				maxi--;
				ptr++;
			}

			//print ans

			cout<<ans.size()<<" ";
			REP(l,ans.size()){
				cout<<ans[l]+1<<" ";
			}
			cout<<endl;

			if(maxi == k -i - 1){
				min_step = find_step(arr,n);
				// REP(m, n){
				// 	cout<<arr[m]<<",";
				// }
				// cout<<endl;
				min_reach = true;
			}
		}
		else{
			// cout<<"i:"<<i<<endl;
			
			ll idx= min_step[min_step.size() - 1];

			// cout<<"idx"<<min_step[idx]<<endl;
			cout<<1<<" "<<idx+1<<endl;
		
			arr[idx] = 0;
			arr[idx+1] = 1;
			
			min_step.pop_back();
			
			if(idx>0 && arr[idx-1] == 1){
				min_step.push_back(idx-1);
			}
			if(idx<n-2 && arr[idx+2] == 0){
				min_step.push_back(idx+1	);
			}
		}
	}

	return 0;
}