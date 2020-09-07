#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i = 0;i<n;++i)

int main() {

  ll n;

  cin>>n;

  ll a[n];

  REP(i,n){
    cin>>a[i];
  }

  ll t[n];

  REP(i,n){
    cin>>t[i];
  }

  pair<ll,ll> arr[n+1];

  REP(i,n){
    arr[i] = {a[i],t[i]};
  }

  n++;
  arr[n-1] = {200000000000,0};

  sort(arr,arr+n);

  multiset<ll> left;

  ll last = 0, sum = 0, ans = 0;

  for(ll i = 0;i<n;i++){

    ll acurr = arr[i].first;
    ll tcurr = arr[i].second;

    while(acurr > last && !left.empty()){
      last++;
      auto it = prev(left.end()); // check
      sum -= *it;
      left.erase(it);
      ans += sum;
    }

    last = acurr;
    left.insert(tcurr);
    sum += tcurr;
  }

  cout<<ans<<endl;


  return 0;
}