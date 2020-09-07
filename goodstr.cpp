#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 200005

unordered_map<ll,string> bstrings; 
unordered_map<ll,ll> zeros;

ll countFreq(string &pat, string &txt) 
{ 
    ll M = pat.length(); 
    ll N = txt.length(); 
    ll res = 0; 
    
    /* A loop to slide pat[] one by one */
    for (ll i = 0; i <= N - M; i++) 
    {  
        /* For current index i, check for  
           pattern match */
        ll j; 
        for (j = 0; j < M; j++) 
            if (txt[i+j] != pat[j]) 
                break; 
   
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
} 

string bintostr(ll i){
	string ans = "";
	ll len = i;

	while(i>0){
		if(i%2 == 0){
			ans = "0" + ans;
		}
		else{
			ans = "1" + ans;
		}
		i/=2;
	}

	ll size = ans.length();
	while(size < len){
		ans = "0"+ans;
		size++;
	}
	return ans;
}

int main() {

	for(ll i = 1;i<20;i++){
		bstrings[i] = bintostr(i);
		//out<<bstrings[i]<<endl;
	}


	ll t;
	cin>>t;
	while(t--){
		string s;
		ll ans= 0;
		cin>>s;
		for(int i = 1;i<25;i++){
			string snum = bstrings[i];
			ans += countFreq(snum,s);
		  
		}
		cout<<ans<<endl;

	}

	return 0;
}
