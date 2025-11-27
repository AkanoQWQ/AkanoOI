#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MOD = 1e9 + 7;
int n,m,a[MAXN],q,l,r;
struct Node{
	int val[22];
	inline void Print(){
		for(int i = 0;i < m;i++)cerr<<val[i]<<",";
		return ;
	}
	Node(){
		for(int i = 1;i < m;i++)val[i] = 0;
		val[0] = 1;
		return ;
	}
};
Node operator+(const Node &a, const Node &b) {
	Node ret;
	ret.val[0] = 0;
	for(int i = 0;i < m;i++){
		if(a.val[i] == 0)continue;
		for(int j = 0;j < m;j++){
			int OBJ = i + j;
			if(OBJ >= m)OBJ -= m;
			ret.val[OBJ] = (ret.val[OBJ] + 1ll * a.val[i] * b.val[j]) % MOD;
		}
	}
	return ret;
}
class SegmentTree{
private:
	Node nodes[MAXN * 8];
	void Build(int l,int r,int p){
		if(l == r){
			nodes[p].val[a[l]]++;
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(l,mid,p*2),Build(mid+1,r,p*2+1);
		nodes[p] = nodes[p*2] + nodes[p*2+1];
		return ;
	}
	Node Find(int l,int r,int p,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR)return nodes[p];
		Node ret;
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)ret = ret + Find(l,mid,p*2,OBJL,OBJR);
		if(mid+1 <= OBJR)ret = ret + Find(mid+1,r,p*2+1,OBJL,OBJR);
		return ret;
	}
public:
	inline void Build(){
		Build(1,n,1);
		return ;
	}
	inline int Find(int l,int r){
		Node ret;
		ret = Find(1,n,1,l,r);
		return ret.val[0];
	}
}tr;
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i] %= m;
	}
	tr.Build();
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<tr.Find(l,r)<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
