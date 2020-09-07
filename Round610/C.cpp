#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

struct question{
	ll type;
	ll time;
};

bool compareQuestion(question q1, question q2){
	if(q1.time == q2.time){
		return q1.type < q2.type;
	}

	return q1.time < q2.time;
}

int main() {

	ll m;
	cin>>m;

	while(m--){
		ll n, t, a, b;

		cin>>n>>t>>a>>b;

		ll easyleft = 0;

		question ques[n];

		REP(i,n){
			cin>>ques[i].type;
			if(ques[i].type == 0){
				easyleft++;
			}
		}

		REP(i,n){
			cin>>ques[i].time;
		}

		sort(ques,ques+n, compareQuestion);

		ll currt = 0;

		ll pts = 0;

		ll ans = 0;

		ll idx = 0;

		// ll valid = 1;

		while(currt < t && idx < n){

			// take a question
			question q = ques[idx];

			// cout<<"q:"<<q.time<<endl;
			// cout<<"q2:"<<q.type<<endl;
			

			// // take score at beginning
			// if(q.time >= currt){
			// 	ans = max(ans,pts);
			// }

			if(q.type == 0){
				currt += a;
				easyleft--;
			}
			else{
				//check how many easies can be done if left...
				ll time_left = q.time - currt - 1;
				// cout<<"easyleft"<<easyleft<<endl;
				// cout<<"time_left"<<time_left<<endl;

				if(time_left > 0 && easyleft > 0){
					ll temppts = pts;
					temppts += min(easyleft, time_left/a);
					// cout<<"tp:"<<temppts<<endl;
					ans = max(ans,temppts); 
				} 

				currt += b;
			}

			pts++;
			idx++;

			// cout<<"currt:"<<currt<<endl;
			// cout<<"nextt:"<<ques[idx].time<<endl;

			// take score at end
			if(currt >t){
				break;
			}
			if(ques[idx].time > currt || idx == n){
				// cout<<"pts"<<pts<<endl;
				ans = max(ans,pts);
			}

		}

		cout<<ans<<endl;

	}
	return 0;
}