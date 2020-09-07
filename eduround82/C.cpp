#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)


string s;


ll findidx(char a){
	return a - 'a';
}


int main() {

	int t;
	cin>>t;

	while(t--){
		
		set <ll> chk[26];

		for(ll i = 0;i<26;i++){

		}

		cin>>s;

		ll size = s.length();

		REP(i,size){
			ll idx = findidx(s[i]);
			if(i != 0){
				ll nextidx = findidx(s[i-1]);
				chk[idx].insert(nextidx);
			}
			if(i != (size-1)){
				ll nextidx = findidx(s[i+1]);
				chk[idx].insert(nextidx);
			}
		}

		ll ifposs = 1;
		set <ll> twocounts;
		ll start = -1;

		REP(i,26){
			// cout<<"i:"<<i<<chk[i].size()<<endl;
			if(chk[i].size() > 2){
				ifposs = 0;
				break;
			}
			else if (chk[i].size() == 1){
				twocounts.insert(i);
			}

		}

		if(twocounts.size() != 2){
			// cout<<"broke"<<endl;
			ifposs = 0;
		}

		for (auto itr = twocounts.begin(); itr != twocounts.end(); ++itr) 
	    { 
	        start = *itr; 
	    	
	    }

	    char gt = 'a';

	    if(ifposs){
	    	//cout<<start<<endl;
	    	int ans[26];
	    	memset(ans,-1,sizeof(ans));

	    	//find idx;
	    	ans[0] = start;

	    	ll idx;

	    	ll keyidx = 0;

	    	REP(i,size){
	    		if(findidx(s[i]) == start){
	    			idx = start;
	    			break;
	    		}
	    	}

	    	for(ll i = 1;i < size;i++){
	    		if(keyidx != 0 && )

	    	}



	    }
	    else{
	    	cout<<"NO"<<endl;
	    }




	}

	return 0;
}