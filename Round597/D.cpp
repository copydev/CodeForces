#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int n;
	cin>>n;

	pair<ll,ll> cityxy[n];
	ll fac[n];
	ll wire[n];

	REP(i,n){
		cin>>cityxy[i].first>>cityxy[i].second;
	}

	REP(i,n){
		cin>>fac[i];
	}

	REP(i,n){
		cin>>wire[i];
	}

	ll vis[n];
	memset(vis,-1,sizeof(vis));

	pair<ll,ll> maybe[n];

	REP(i,n){
		maybe[i].first = -1;
		maybe[i].second = -1;
	}

	vector<ll> powerans;
	vector<pair<ll,ll>> wireans;

	ll cvis = n;

	while(cvis){
		ll minidx = -1;
		ll minval = 10000000000;

		REP(i,n){
			if(vis[i] == -1){
				if(fac[i] < minval){
					minval = fac[i];
					minidx = i;
				}
			}
		}

		vis[minidx] = 1;
		//add result of maybe pair in fixed pair
		if(maybe[minidx].first == -1){
			powerans.push_back(minidx+1);
		}
		else{
			wireans.push_back({maybe[minidx].first+1,maybe[minidx].second+1});
		}

		REP(i,n){
			if(vis[i] == -1){
				ll dis = abs(cityxy[i].first - cityxy[minidx].first) + abs(cityxy[i].second - cityxy[minidx].second);
				ll wire_cost = (dis * (wire[i]+ wire[minidx]));
				if(fac[i] > wire_cost){
					fac[i] = wire_cost;
					// Add the pair in maybe pair
					maybe[i].first = minidx;
					maybe[i].second = i; 

				}
			}
		}
		--cvis;
	}


	ll sumans = 0;
	REP(i,n){
		sumans += fac[i];
	}

	cout<<sumans<<endl;

	cout<<powerans.size()<<endl;

	REP(i,powerans.size()){
		cout<<powerans[i]<<" ";
	}

	cout<<endl;

	cout<<wireans.size()<<endl;

	REP(i,wireans.size()){
		cout<<wireans[i].first<<" "<<wireans[i].second<<endl;
	}


	return 0;
}