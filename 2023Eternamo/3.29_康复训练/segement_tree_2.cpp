#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 6;
inline ll Read(){
	ll ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(ll inx){
	if(inx > 9){
		Write(inx / 10);
	}
	putchar((inx % 10) + '0');
	return ;
}
ll n,q,inputs[MAXN],MOD;
struct Segement_tree{
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
			val[p] = inputs[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(l,mid,p*2);
		Build(mid+1,r,p*2+1);
		PushUp(p);
		return ;
	}
	inline bool Judge(int l,int r){
		return (objl <= l) && (r <= objr);
	}
	void Update(int l,int r,int p){
		if(Judge(l,r)){
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
		if(Judge(l,r)){
			return val[p];
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(objl <= mid)ret = Query(l,mid,p*2);
		if(objr > mid)ret += Query(mid+1,r,p*2+1);
		PushUp(p);
		return ret;
	}
	inline ll Ask(int l,int r){
		objl = l,objr = r;
		return Query(1,n,1) % MOD;
	}
	inline void Change(int l,int r,int k,char type){
		objl = l,objr = r,nowk = k;
		if(type == 'a'){
			opt = 1;
		}else if(type == 'm'){
			opt = 2;
		}
		Update(1,n,1);
		return ;
	}
}tr;
int main(){
	n = Read(),q = Read(),MOD = Read();
	for(int i = 1;i <= n;i++){
		inputs[i] = Read();
	}
	tr.Build(1,n,1);
	while(q--){
		ll op = Read(),l = Read(),r = Read(),k;
		if(op == 1){
			k = Read();
			tr.Change(l,r,k,'m');
		}else if(op == 2){
			k = Read();
			tr.Change(l,r,k,'a');
		}else{
			Write(tr.Ask(l,r)),putchar('\n');
		}
	}
	return 0;
}
