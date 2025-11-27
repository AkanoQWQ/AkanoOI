#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN = 2e5 + 6;
int n,q,mod,org[MAXN];
struct Node{
	int val,mul_tag,add_tag,l,r;
};
struct Segment_tree{
	int objl,objr,k,c;
	Node tr[MAXN*5];
	void Build(int l,int r,int p){
		tr[p].mul_tag = 1,tr[p].l = l,tr[p].r = r;
		if(l == r){
			tr[p].val = org[l] % mod;
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(l,mid,p*2);
		Build(mid+1,r,p*2+1);
		return ;
	}
	inline void Push_down(int p){
		tr[p*2].val *= tr[p].mul_tag;
		tr[p*2].val += (tr[p].add_tag * (tr[p*2].r - tr[p*2].l + 1));
		tr[p*2+1].val *= tr[p].mul_tag;
		tr[p*2+1].val += (tr[p].add_tag * (tr[p*2+1].r - tr[p*2+1].l + 1));
		tr[p*2].val %= mod,tr[p*2+1].val %= mod;
		tr[p*2].mul_tag = (tr[p*2].mul_tag * tr[p].mul_tag) % mod;
		tr[p*2+1].mul_tag = (tr[p*2+1].mul_tag * tr[p].mul_tag) % mod;
		tr[p*2].add_tag = (tr[p*2].add_tag * tr[p].mul_tag + tr[p].add_tag) % mod;
		tr[p*2+1].add_tag = (tr[p*2+1].add_tag * tr[p].mul_tag + tr[p].add_tag) % mod;
		tr[p].mul_tag = 1,tr[p].add_tag = 0;
		return ; 
	}
	inline void Push_up(int p){
		if(tr[p].l != tr[p].r)tr[p].val = tr[p*2].val + tr[p*2+1].val;
		tr[p].val %= mod;
		return ;
	}
	void Update_mul(int p){
		if(objl <= tr[p].l && tr[p].r <= objr){
			tr[p].mul_tag *= k,tr[p].add_tag *= k,tr[p].val *= k;
			tr[p].mul_tag %= mod,tr[p].add_tag %= mod,tr[p].val %= mod;
			return ;
		}
		Push_down(p);
		const int mid = (tr[p].l + tr[p].r) >> 1;
		if(mid >= objl)Update_mul(p*2);
		if(mid < objr)Update_mul(p*2+1);
		Push_up(p);
		return ;
	}
	void Update_add(int p){
		if(objl <= tr[p].l && tr[p].r <= objr){
			tr[p].add_tag += c,tr[p].val += c * (tr[p].r - tr[p].l + 1);
			tr[p].add_tag %= mod,tr[p].val %= mod;
			return ;
		}
		Push_down(p);
		const int mid = (tr[p].l + tr[p].r) >> 1;
		if(mid >= objl)Update_add(p*2);
		if(mid < objr)Update_add(p*2+1);
		Push_up(p);
		return ;
	}
	int Query(int p){
		if(objl <= tr[p].l && tr[p].r <= objr){
			return tr[p].val;
		}
		Push_down(p);
		const int mid = (tr[p].l + tr[p].r) >> 1;
		int ret = 0;
		if(mid >= objl)ret = Query(p*2);
		if(mid < objr)ret += Query(p*2+1);
		return ret % mod;
	}
}seg;
signed main(){
	freopen("P3373_1.in","r",stdin);
	freopen("P3373_1.oo","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q>>mod;
	for(int i = 1;i <= n;i++){
		cin>>org[i];
	}
	seg.Build(1,n,1);
	while(q--){
		int opt,v;
		cin>>opt>>seg.objl>>seg.objr;
		if(opt == 1){
			cin>>seg.k;
			seg.Update_mul(1);
		}else if(opt == 2){
			cin>>seg.c;
			seg.Update_add(1);
		}else{
			cout<<seg.Query(1)%mod<<"\n";
		}
/*		for(int i = 1;i <= n;i++){
			seg.objl = i,seg.objr= i;
			cout<<seg.Query(1)<<" ";
		}
		cout<<endl;*/
	}
	return 0;
}
