#include <bits/stdc++.h>
#define ll long long 
#define inf 100000


using namespace std;

ll * arr;
ll * seg;
ll * lazy;

void apply(ll ss, ll val){
	seg[ss] += val;
	lazy[ss] += val;
}

void pull(ll ss){
	seg[ss] = min(seg[2*ss + 1],seg[2*ss + 2]);	
	// cout<<"1:"<<seg[2*ss+1]<<"2:"<<seg[2*ss+2]<<endl;
	// cout<<"ss: "<<ss<<",val: "<<seg[ss]<<endl;
}

void push(ll ss){
	if(lazy[ss] != 0){
		apply(2*ss +1, lazy[ss]);
		apply(2*ss +2, lazy[ss]);
		lazy[ss] = 0;
	}
}

void build_segtree(ll ni, ll ne, ll ss){
	if(ni == ne){
		seg[ss] = arr[ni]; 
	}
	else{
		ll mid = (ni + ne)/2;
		build_segtree(ni,mid,2*ss + 1);
		build_segtree(mid+1,ne,2*ss + 2);

		seg[ss] = min(seg[2*ss + 1],seg[2*ss + 2]);	
	}
}

ll last_zero(ll ni, ll ne, ll ss){
	if(ni == ne){
		return ni;
	}

	push(ss);

	ll mid = (ni + ne)/2;

	ll res;

	if(seg[2*ss + 2] == 0){
		//cout<<"r"<<endl;
		res = last_zero(mid + 1,ne,2*ss + 2);
	}
	else{
		//cout<<"l"<<endl;
		res = last_zero(ni, mid,2*ss + 1);
	}

	pull(ss);
	return res;
}

void update_range(ll ri, ll re, ll ni, ll ne , ll ss, ll val){
	if(re < ni || ne < ri){
		return;
	}

	if(ri <= ni && ne <= re){
		apply(ss,val);
		return;
	}

	push(ss);

	ll mid = (ni + ne)/2;

	update_range(ri,re,ni,mid,2*ss + 1,val);
	update_range(ri,re,mid+1,ne,2*ss + 2,val);

	pull(ss);
}


int main() {
	ll n;
	cin>>n;
	arr = new ll[n];
	seg = new ll[4*n];
	lazy = new ll[4*n];

	memset(lazy,0,sizeof(lazy));
	memset(seg,0,sizeof(lazy));


	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}	

	build_segtree(0,n-1,0);

	ll ans[n];

	// for(ll i = 0;i<2*n-1;i++){
	// 	cout<<seg[i]<<" ";
	// }
	// cout<<endl;

	for(ll i =0;i<n;i++){
		ll idx = last_zero(0,n-1,0);
		//cout<<idx<<endl;
		ans[idx] = i +1;

		update_range(idx,idx,0, n-1,0,inf);

		update_range(idx+1,n-1,0,n-1,0,-(i+1));

	}
	
	// ll idx = last_zero(0,n-1,0);
	// cout<<"idx"<<idx<<endl;
	//update_range(0,0,0, n-1,0,INT_MAX);

	for(ll i = 0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	// for(ll i = 0;i<2*n-1;i++){
	// 	cout<<seg[i]<<" ";
	// }
	// cout<<endl;

	return 0;
	
}

