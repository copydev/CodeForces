#include <bits/stdc++.h>
#define ll long long

using namespace std;

void gAns(ll n, int i){
    cout<<"Case #"<<i<<": "<<n<<endl;
}

int chk(ll k, ll arr[], int n, ll m){
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ans += k^arr[i];
    }
    cout<<ans<<endl;
    
    if(ans <= m){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int t;  
    cin>>t;
    for(int a = 1;a<=t;a++){
        ll n,m;
        cin>>n>>m;
        ll arr[n];
        for(int i = 0; i<n;i++){
            cin>>arr[i];
        }
        
        ll cntbit[51];
        memset(cntbit,0,sizeof(cntbit));
        
        for(int i = 0;i<n;i++){
            ll num = arr[i];
            int idx = 0;
            while(num > 0){
                if(num&1){
                    cntbit[idx]++;
                }
                num = num>>1;
                idx++;
            }
        }
        
        //Test
        // for(int i = 0;i<51;i++){
        //     cout<<cntbit[i]<<":"<<i<<endl;
        // }
        
        ll minnum = 0;
        for(int i = 0;i<=50;i++){
            if(cntbit[i] > (n - cntbit[i])){
                minnum += pow(2,i);
            }
        }
        
        cout<<"Min:"<<minnum<<endl;
        ll inichk = chk(minnum,arr,n,m);
        
        if(!inichk){
            gAns(-1,a);
            continue;
        }
        
    
        //Solve for max k
        ll k = 0;
        for(int i = 50;i>=0;i--){
            ll up = pow(2,i);
            k += up;
            cout<<"i:"<<i<<",k:"<<k<<endl;
            if(!chk(k,arr,n,m)){
                k -= up;
            }
            
        }
        
        gAns(k,a);
        
    }
    
    return 0;
}