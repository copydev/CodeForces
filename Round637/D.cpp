#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int memo[2005][2005];

int binary_to_decimal(string s){
	// cout<<"s:"<<s<<endl;
	int num = 0;
	int idx = 0;

	for(int i = s.length()-1;i>=0;i--){
		if(s[i] == '1'){
			num += pow(2,idx);
		}
		idx++;
	}

	return num;
}

int n;


vector<int> num;
vector<int> numinp;

int dp(int idx, int k){

	if(idx == n && k == 0){
		return 0;
	}

	if(idx == n && k != 0){
		return -1;
	}

	if(memo[idx][k] != -2){
		return memo[idx][k];
	}

	int illegal = 1;
	int numi = 0;

	REP(i,10){
		if((num[i] ^ numinp[idx]) == 0){
			numi = i;
			illegal = 0;
			break;
		}
	}

	int ans = 0;

	for(int i = numi;i<10;i++){
		// cout<<num[i]<<","<<numinp[idx]<<endl;
		if((num[i] | numinp[idx]) == num[i]){
			
			int diffk = __builtin_popcount(num[i]) - __builtin_popcount(numinp[idx]);
			// cout<<"i:"<<i<<"df"<<diffk<<endl;
			if(diffk <= k){
				int tempans = dp(idx+1,k-diffk);
				// cout<<"temp:"<<tempans<<endl;
				if(tempans != -1){
					ans = tempans;
					numi = i;
					illegal= 0;
				}
			} 
		}
	}

	ll final;	



	if(illegal == 1){
		final = -1;
	}

	else{
		final = ans + pow(10,n-idx-1) * numi;
	}

	memo[idx][k] = final;

	return final;

}

int main() {

	int k;

	REP(i,2005){
		REP(j,2005){
			memo[i][j] = -2;
		}
	}

	num.push_back(119);
	num.push_back(18);
	num.push_back(93);
	num.push_back(91);
	num.push_back(58);
	num.push_back(107);
	num.push_back(111);
	num.push_back(82);
	num.push_back(127);
	num.push_back(123);

	
	cin>>n>>k;

	string inp;
	

	REP(i,n){
		cin>>inp;
		numinp.push_back(binary_to_decimal(inp));
		// cout<<numinp[i]<<endl;
	}


	int ans = dp(0,k);

	cout<<ans<<endl;


	return 0;
}