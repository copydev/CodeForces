#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int totalone;
int n,k;
string s,revs;

ll getCnt(string & str,int i){
	
	string news = "";

	for(int j = i;j<str.length();j+=k){
		news += str[j];
	}


	int dp[news.length()+1] = {0};
	int total = 0;


	for(int j = 0;j<news.length();j++){

		if(news[j] == '1'){
			total ++;
			dp[j]++;
		}

		if(j!= 0){
			dp[j] += dp[j-1];
		}
	}

	// dp[news.length()] = total;

	int ans = INT_MAX;

	int dp2[news.length()] = {0};

	// cout<<news<<endl;

	for(int j = 0;j<news.length();j++){

		int curr = (news[j] != '1');

		if(j>0){
			dp2[j] = min(dp2[j-1] + curr, dp[j-1] + curr);
		}

		ans = min(ans, dp2[j] + total - dp[j]);

		// cout<<"i:"<<dp2[j]<<","<<ans<<endl;

	}

	return ans + totalone - total;

}




int main() {

	int t;
	cin>>t;

	while(t--){
		
		cin>>n>>k;

		cin>>s;

		revs = "";

		totalone = 0;

		REP(i,n){
			revs += s[n - 1 - i];
			if(s[i] == '1'){
				totalone++;
			}
		}

		// cout<<totalone<<endl;

		// cout<<revs<<endl;

		ll ans = n;

		for(int i = 0;i<k;i++){
			ans = min(ans,getCnt(s,i));
		// 	ans = min(ans,getCnt(revs,i));
		}

		cout<<ans<<endl;

	}

	return 0;
}