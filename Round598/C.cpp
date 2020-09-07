#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	ll n, m , d;
	cin>>n>>m>>d;

	ll planks[m];

	REP(i,m){
		cin>>planks[i];
	}

	//CHeck if possible or not?

	// int pos = 0;
	// int pi = 0;
	// while(pos < n && pi < m){
	// 	pos += d;
	// 	pos += planks[pi] - 1; 
	// 	pi++;
	// }

	// pos += d;

	// if(pos < n){
	// 	cout<<"NO"<<endl;
	// }
	// else{
	// 	cout<<"YES"<<endl;
		//Make the planks;
	ll sump = 0;
	REP(i,m){
		sump += planks[i];
	}

	ll currpos = 0;
	ll endpos = n+1;

	ll nearppos = n+1 - sump;
	ll planki = 0;

	ll ans[n+2];
	memset(ans,0,sizeof(ans));

	int chk = 1;

	while(currpos<endpos){

		//cout<<"curr"<<currpos<<endl;
		if(currpos + d >= nearppos){
			//cout<<"Endcase"<<endl;
			//Make Plank
			for(ll i = planki; i<m;i++){
				for(ll j = 0;j<planks[i];j++){
					ans[nearppos] = i+1;
					nearppos++;
				}
			}
			break;
		}
		else{
			if(planki >= m){
				chk = 0;
				break;
			}
			//Shift Planki
			for(ll i = 0; i<planks[planki];i++){
				ans[currpos+d+i] = planki+1;
			}
			//Update nearppos and currpos and planki
			nearppos += planks[planki];
			currpos = currpos+ d + planks[planki] - 1;
			planki++;
		}

	}

	//Check for ans if else

	if(chk){
		cout<<"YES"<<endl;
		for(ll i = 1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}
	else{
		cout<<"NO"<<endl;
	}


	return 0;
}