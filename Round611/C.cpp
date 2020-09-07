#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

struct Tree
{
	ll pos;
	ll leftfree;
	ll rightfree;
};


struct compareleft
{
	bool operator()(Tree &t1, Tree &t2){
		return t1.leftfree > t2.leftfree;
	}
	
};

struct  compareright
{
	bool operator()(Tree &t1, Tree &t2){
		return t1.rightfree > t2.rightfree;
	}	
	
};


int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,m;
	cin>>n>>m;

	ll ans = 0;
	vector <ll> posans;

	//n trees and m people

	Tree trees[n];


	map <ll,ll> occupied; //

	REP(i,n){ //O(n)
		cin>>trees[i].pos;
		occupied[trees[i].pos] = 1;
	}

	REP(i,n){ //O(n)

		//find left and right free distance wrt position
		if(occupied[trees[i].pos -1]){
			trees[i].leftfree = -1;
		}
		else{
			trees[i].leftfree = 1;
		}

		if(occupied[trees[i].pos +1]){
			trees[i].rightfree = -1;
		}
		else{
			trees[i].rightfree = 1;
		}
	}

	


	priority_queue<Tree,vector<Tree>,compareleft> pql;
	priority_queue<Tree,vector<Tree>,compareright> pqr;

	REP(i,n){ //O(nlogn)
		if(trees[i].leftfree != -1){
			pql.push(trees[i]);
		}
		if(trees[i].rightfree != -1){
			pqr.push(trees[i]);
		}
	}

	// REP(i,n){
	// 	cout<<pql.top().leftfree<<endl;
	// 	cout<<pql.top().rightfree<<endl;
	// }

	while(m){
		//process left trees
		while(!pql.empty() && occupied[pql.top().pos - pql.top().leftfree]){
			pql.pop();
		}


		//process right trees
		while(!pqr.empty() && occupied[pqr.top().pos + pqr.top().rightfree]){
			pqr.pop();
		}

		if(pql.top().leftfree < pqr.top().rightfree){
			Tree t = pql.top();
			pql.pop();
			//get ans
			//cout<<"left"<<t.leftfree<<endl;
			ans += t.leftfree;
			posans.push_back(t.pos - t.leftfree);
			occupied[t.pos-t.leftfree] = 1;
			t.leftfree++;
			if(!occupied[t.pos-t.leftfree])
				pql.push(t);
		}
		else{
			Tree t = pqr.top();
			pqr.pop();
			//get ans
			//cout<<"right"<<t.rightfree<<endl;
			ans += t.rightfree;
			posans.push_back(t.pos + t.rightfree);
			occupied[t.pos+t.rightfree] = 1;
			t.rightfree++;
			if(!occupied[t.pos + t.rightfree])
				pqr.push(t);
		}

		m--;
	}

	cout<<ans<<endl;

	for(ll i = 0;i<posans.size();i++){
		cout<<posans[i]<<" ";
	}
	cout<<endl;



	return 0;
}