#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define REP(i,n) for(ll i = 0;i<n;++i)

vector<vector<ll>> input;
ll n, m;

vector<ll> makebool(ll mid){
	map<ll,ll> mp;
	vector<ll> boolans;

	//cout<<"mid:"<<mid<<endl;

	REP(i,n){

		ll numbool = 0;

		REP(j,m){

			numbool = numbool << 1;

			if(mid <= input[i][j]){
				numbool |= 1;
			}

		}

		if(mp[numbool] == 0){
			//cout<<numbool<<endl;
			mp[numbool] = 1;
			boolans.push_back(numbool);
		}


	}

	return boolans;
}

int checkbool(vector<ll> &boolans){

	ll lim = (1 << m) - 1;



	ll size = boolans.size();
	REP(i,size){
		for(ll j = i;j<size;j++){

			ll res = boolans[i] | boolans[j];

			if(res == lim){
				//cout<<res<<endl;
				//cout<<i<<" "<<j<<endl; 
				return 1;
			} 

		}
	}

	return 0;
}

void printans(ll mid){

	map<ll,ll> mp;
	vector<ll> boolans;


	REP(i,n){

		ll numbool = 0;

		REP(j,m){

			numbool = numbool << 1;

			if(mid <= input[i][j]){
				numbool |= 1;
			}

		}

		if(mp[numbool] == 0){
			//cout<<numbool<<endl;
			//cout<<numbool<<endl;
			mp[numbool] = i;
			boolans.push_back(numbool);
		}
	}

	ll lim = (1 << m) - 1;

	ll size = boolans.size();
	REP(i,size){
		for(ll j = i;j<size;j++){

			ll res = boolans[i] | boolans[j];

			if(res == lim){

				cout<<mp[boolans[i]]+1<<" "<<mp[boolans[j]]+1<<endl; 
				return;
			} 

		}
	}


}


int main() {

	cin>>n>>m;

	input.resize(n,vector<ll>(m));

	REP(i,n){
		REP(j,m){
			cin>>input[i][j];
		}
	}


	ll low = 0, high = 1000000000;

	while(low < high){
		
		ll mid = (high + low)/2 + 1;

		// make bool vector
		vector<ll> boolans = makebool(mid);

		//check bool

		int chk = checkbool(boolans);

		if(chk){
			low = mid;
		}
		else{
			high = mid -1;
		}
	}

	//find pair ans

	vector<ll> temp = makebool(low);



	if(!checkbool(temp)){
		return 0;
	}

	printans(low);



	return 0;
}