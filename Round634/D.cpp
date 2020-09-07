#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

	int t;
	cin>>t;

	while(t--){
		int arr[9][9];

		REP(i,9){
			string s;
			cin>>s;
			REP(j,9){
				arr[i][j] = s[j] - '0';
			}
		}

		int idx = 0;
		int jdx = 0;

		while(idx<9){

			for(int i = 0,j=0;i<3;i++,j+=3){

				if(arr[idx + i][j + jdx] == 1){
					arr[idx + i][j + jdx] = 2;
				} 
				else{
					arr[idx + i][j + jdx] = 1;
				}
			}

			idx+= 3;
			jdx+= 1;
		}

		REP(i,9){
			REP(j,9){
				cout<<arr[i][j];
			}
			cout<<endl;
		}


	}

	return 0;
}