#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
int nxt[MAXN],a[MAXN],n,q;
set<int> numPos[MAXN];
class SegmentTree{
private:
	struct Node{
		int farpos;
		ll ans;
	}node[MAXN * 4];
	ll FindAns(int p,int l,int r,int limitpos){
		if(l == r)return min(node[p].ans,ll(limitpos));
		const int mid = (l + r) >> 1;
		if(node[p*2+1].farpos > limitpos){
			return FindAns(p*2,l,mid,limitpos) + limitpos * (r - mid);
		}else{
			return node[p].ans - node[p*2+1].ans + FindAns(p*2+1,mid+1,r,limitpos);
		}
		return 10181108;
	}
	inline void PushUp(int p,int l,int r){
		node[p].farpos = min(node[p*2].farpos,node[p*2+1].farpos);
		const int mid = (l + r) >> 1;
		node[p].ans = FindAns(p*2,l,mid,node[p*2+1].farpos) + node[p*2+1].ans;
		return ;
	}
	void Build(int p,int l,int r){
		if(l == r){
			node[p].farpos = node[p].ans = nxt[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p,l,r);
		return ;
	}
	void Change(int p,int l,int r,int pos,int _nxt){
		if(l == r){
			node[p].ans = node[p].farpos = _nxt;
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= pos)Change(p*2,l,mid,pos,_nxt);
		if(mid < pos)Change(p*2+1,mid+1,r,pos,_nxt);
		PushUp(p,l,r);
		return ;
	}
	ll Query(int p,int l,int r,int OBJL,int OBJR,int& limitpos){
		if(OBJL <= l && r <= OBJR){
			ll res = FindAns(p,l,r,limitpos);
			limitpos = min(limitpos,node[p].farpos);
			return res;
		}
		const int mid = (l + r) >> 1;
		ll ret = 0;
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR,limitpos);//这个顺序是因为需要用右边的farpos限制左边的右端点
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR,limitpos);
		return ret;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Change(int pos,int _nxt){
		if(not(1 <= pos && pos <= n))return ;
		Change(1,1,n,pos,_nxt);
		return ;
	}
	inline ll Query(int l,int r){
		int limitpos = r + 1;
		return Query(1,1,n,l,r,limitpos);
	}
}tr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		numPos[a[i]].insert(i);
		numPos[i].insert(0),numPos[i].insert(n+1);
	}
	for(int i = 1;i <= n;i++){
		nxt[i] = *(++numPos[a[i]].find(i));
	}
	tr.Build();
	for(int i = 1,opt,x,y;i <= q;i++){
		cin>>opt>>x>>y;
		if(opt == 1){
			int pre = *(--numPos[a[x]].find(x)),_nxt = *(++numPos[a[x]].find(x));
			tr.Change(pre,_nxt);
			numPos[a[x]].erase(x);
			a[x] = y;
			numPos[a[x]].insert(x);
			pre = *(--numPos[a[x]].find(x)),_nxt = *(++numPos[a[x]].find(x));
			tr.Change(pre,x),tr.Change(x,_nxt);
		}else if(opt == 2){
			cout<<tr.Query(x,y) - 1ll * (x + y) * (y - x + 1) / 2<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
