#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
#define ll long long
using namespace std;
const int MAXN = 1e5 + 6;

ll n,q,arr[MAXN],MOD;
class SegmentTree{
private:
	ll val[MAXN*8],lazy[MAXN*8],mul[MAXN*8],len[MAXN*8],objl,objr,nowk,opt;
	inline void PushUp(int p){
		val[p] = (val[p*2] + val[p*2+1]);
		return ;
	}
	inline void PushDown(int p){
		for(int child = p*2;child <= p*2+1;child++){
			val[child] = (val[child] * mul[p] + lazy[p] * len[child]) % MOD;
			mul[child] = (mul[child] * mul[p]) % MOD;
			lazy[child] = (lazy[child] * mul[p] + lazy[p]) % MOD;
		}
		lazy[p] = 0;
		mul[p] = 1;
		return ;
	} 
	void Build(int l,int r,int p){
		len[p] = r - l + 1,mul[p] = 1;
		if(l == r){
			val[p] = arr[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(l,mid,p*2),Build(mid+1,r,p*2+1);
		PushUp(p);
		return ;
	}
	void Update(int l,int r,int p){
		if((objl <= l) && (r <= objr)){
			if(opt == 1){//ADD
				lazy[p] = (lazy[p] + nowk) % MOD;
				val[p] = (val[p] + nowk * len[p]) % MOD;
			}else if(opt == 2){//MUL
				mul[p] = (mul[p] * nowk) % MOD;
				lazy[p] = (lazy[p] * nowk) % MOD;
				val[p] = (val[p] * nowk) % MOD;
			}
			return ; 
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(objl <= mid)Update(l,mid,p*2);
		if(objr > mid)Update(mid+1,r,p*2+1);
		PushUp(p);
		return ;
	}
	ll Query(int l,int r,int p){
		ll ret = 0;
		if((objl <= l) && (r <= objr)){
			return val[p];
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(objl <= mid)ret = Query(l,mid,p*2);
		if(objr > mid)ret += Query(mid+1,r,p*2+1);
		PushUp(p);
		return ret;
	}
public:
	inline void Build(){
		Build(1,n,1);
		return ;
	}
	inline ll Query(int l,int r){
		objl = l,objr = r;
		return Query(1,n,1) % MOD;
	}
	inline void Update(int l,int r,int k,char type){
		objl = l,objr = r,nowk = k;
		if(type == 'a'){
			opt = 1;
		}else if(type == 'm'){
			opt = 2;
		}
		Update(1,n,1);
		return ;
	}
};
SegmentTree tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q>>MOD;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	tr.Build();
	while(q--){
		ll op,l,r,k;
		cin>>op>>l>>r;
		if(op == 1){
			cin>>k;
			tr.Update(l,r,k,'m');
		}else if(op == 2){
			cin>>k;
			tr.Update(l,r,k,'a');
		}else{
			cout<<tr.Query(l,r)<<'\n';
		}
	}
	cout<<flush;
	return not(Akano loves pure__Elysia);
}