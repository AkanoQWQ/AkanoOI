#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 1018 + 1108;
int n,q,arr[MAXN];
int temp[3],clk;
inline void Shift(int nowarr[],int delta){
	for(int i = 0;i < 3;i++){
		temp[(i+delta)%3] = nowarr[i];
	}
	for(int i = 0;i < 3;i++){
		nowarr[i] = temp[i];
	}
	return ;
}
struct Node{
	int val[3],lazy;
};
class SegmentTree{
	private:
		int OBJL,OBJR,_val;
		Node node[MAXN * 4];
		inline void PushUp(int p){
			node[p].val[0] = node[p*2].val[0] + node[p*2+1].val[0];
			node[p].val[1] = node[p*2].val[1] + node[p*2+1].val[1];
			node[p].val[2] = node[p*2].val[2] + node[p*2+1].val[2];
			return ;
		}
		inline void PushDown(int p){
			if(!node[p].lazy)return ;
			Shift(node[p*2].val,node[p].lazy);
			Shift(node[p*2+1].val,node[p].lazy);
			node[p*2].lazy = (node[p*2].lazy + node[p].lazy) % 3;
			node[p*2+1].lazy = (node[p*2+1].lazy + node[p].lazy) % 3;
			node[p].lazy = 0;
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				node[p].val[arr[l]]++;
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p);
			return ; 
		}
		void ChangeInner(int p,int l,int r){
			if(OBJL <= l && r <= OBJR){
				Shift(node[p].val,_val);
				node[p].lazy = (node[p].lazy + _val) % 3;
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)ChangeInner(p*2,l,mid);
			if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		int QueryInner(int p,int l,int r){
			if(OBJL <= l && r <= OBJR){
				return node[p].val[_val];
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			int ret = 0;
			if(mid >= OBJL)ret += QueryInner(p*2,l,mid);
			if(mid < OBJR)ret += QueryInner(p*2+1,mid+1,r);
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r,int inval){
			OBJL = l,OBJR = r,_val = inval;
			ChangeInner(1,1,n);
			return ;
		}
		inline int Query(int l,int r,int inval){
			OBJL = l,OBJR = r,_val = inval;
			return QueryInner(1,1,n);
		}
		
}tr;
ll ans = 0;
inline int Find(int inL,int inR,int num,int OBJ){
	int l = inL,r = inR+1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(tr.Query(inL,mid,num) >= OBJ){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return r;
}
inline void BF(){
	ans = 0;
	for(int i = 1;i <= n;i++){
		int pos1 = Find(i,n,0,1),pos2 = Find(i,n,1,1),pos3 = Find(i,n,2,1);
		int pos = max(pos1,max(pos2,pos3));
		ans += n+1-pos;
	}
	return ;
}
int nxt[3];
inline ll GetAns(int l1,int r1,int l2,int r2){
	if(l1 > r1 || l2 > r2)return 0;
	ll ret = 0;
	for(int i = 0;i < 3;i++){
		clk -= clock();
		int tot = tr.Query(l1,r1,i);
		nxt[i] = Find(l1,r1,i,tot)+1;
		clk += clock();
	}
	sort(nxt,nxt+3);
	int now = l1;
	for(int t = 0;t < 3;t++){
		if(nxt[t] == now)continue;
		if(now > r1)break;
		int pos = l2;
		for(int i = 0;i < 3;i++){
			pos = max(pos,Find(now,r2,i,1));
		}
		ret += (r2+1-pos) * (nxt[t] - now);
		now = nxt[t];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("maintaining/maintaining4.in","r",stdin);
	freopen("maintaining.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	tr.Build();
	BF();
	cout<<ans<<'\n';
	for(int i = 1;i <= q;i++){
		int l,r;
		cin>>l>>r;
		//ll lst1 = GetAns(1,l-1,l,r),lst2 = GetAns(l,r,r+1,n),lst3 = GetAns(1,l-1,r+1,n);
		tr.Change(l,r,1);
		//ll delta = GetAns(1,l-1,l,r) + GetAns(l,r,r+1,n) + GetAns(1,l-1,r+1,n);
		//delta -= lst1 + lst2 + lst3;
		ans += delta;
		cout<<ans<<'\n';
	}
	cerr<<"end "<<clock()<<endl;
	cerr<<"used "<<clk<<endl;
	return not(Akano loves pure__Elysia);
}
