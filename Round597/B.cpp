#include <bits/stdc++.h>
using namespace std;
#define ll int
#define REP(i,n) for(int i = 0; i<n;++i)

int main() {

	int t;
	cin>>t;
	while(t--){
		float n;
		cin>>n;
		ll a,b,c;
		cin>>a>>b>>c;

		ll win = 0;

		char wins[int(n)];

		// cout<<win<<endl;

		for(int i = 0;i<n;i++){
			wins[i] = 't';
		}

		for(int i = 0;i<n;i++){
			char m;
			cin>>m;

			if(m == 'R'){
				if(b>0){
					b--;
					win++;	
					wins[i] = 'P';
				}
			}
			else if(m == 'P'){
				if(c>0){
					c--;
					win++;
					wins[i] = 'S';
				}
			}
			else if(m== 'S'){
				if(a>0){
					a--;
					win++;
					wins[i] = 'R';
				}
			}

		}

		float tar = float(n)/2;
		tar = ceil(tar);
		

		// cout<<ceil(tar)<<endl; 
		// cout<<win<<endl;


		if(win >= tar){

			cout<<"YES"<<endl;

			for(int i = 0;i<n;i++){

				if(wins[i] == 't'){
					if(a > 0){
						wins[i] = 'R';
						a--;
					}
					else if(b > 0){
						wins[i] = 'P';
						b--;
					}
					else if(c > 0){
						wins[i] = 'S';
						c--;
					}
				}
			}

			for(int i = 0;i<n;i++){
				cout<<wins[i];
			}
			cout<<endl;


		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}