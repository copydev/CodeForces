#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n;
	cin>>n;

	ll a[n];

	REP(i,n){
		cin>>a[i];
	}
	ll possible = 1;
	vector<ll> ans;

	ll empinside = 0;

	map<ll,ll> mp;

	REP(i,n){
		//cout<<"i"<<i<<endl;
		if(a[i] > 0){
			if(mp[a[i]] == 0){
				mp[a[i]] = 1;
				empinside++;
			}
			else{
				possible = 0;
				break;
			}
		}
		else{
			a[i] = -1 * a[i];
			if(mp[a[i]] == 1){
				mp[a[i]] = 2;
				empinside--;
			}
			else{
				possible = 0;
				break;
			}
		}

		if(empinside == 0){
			//make partition
			mp.clear();
			ans.push_back(i);
		}
	}
	//cout<<empinside<<endl;
	if(empinside != 0 || possible == 0){
		cout<<-1<<endl;
	}
	else{
		cout<<ans.size()<<endl;
		ll k = 0;
		REP(i,ans.size()){
			cout<< ans[i] - k + 1<<" ";
			k = ans[i] + 1;
		}
		cout<<endl;
	}

	return 0;
}