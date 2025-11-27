#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
struct Subset{
	int a,b,c;
}st[MAXN];
bool Cmp(Subset st1,Subset st2){
	if(st1.a != st2.a)return st1.a < st2.a;
	if(st1.b != st2.b)return st1.b < st2.b;
	return st1.c < st2.c;
}
bool CmpByB(Subset st1,Subset st2){
	if(st1.b != st2.b)return st1.b < st2.b;
	if(st1.a != st2.a)return st1.a < st2.a;
	return st1.c < st2.c;
}
int n;
struct Node{
	int l,r,val;
}node[MAXN * 400];
int tot;
class SegmentTree{
private:
	int root,OBJ,OBJL,OBJR,_val;
	inline void Pushup(int p){
		node[p].val = node[node[p].l].val + node[node[p].r].val;
		return ;
	}
	int Change(int p,int l,int r){
		if(!p)p = ++tot;
		if(l == r){
			node[p].val += _val;
			return p;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)node[p].l = Change(node[p].l,l,mid);
		if(mid < OBJ)node[p].r = Change(node[p].r,mid+1,r);
		Pushup(p);
		return p;
	}
	int Query(int p,int l,int r){
		if(!p)return 0;
		if(node[p].val == 0)return 0;
		if(OBJL <= l && r <= OBJR){
			return node[p].val;
		}
		const int mid = (l + r) >> 1;
		int ret = 0;
		if(mid >= OBJL)ret += Query(node[p].l,l,mid);
		if(mid < OBJR)ret += Query(node[p].r,mid+1,r);
		return ret;
	}
public:
	inline void Change(int pos,int __val){
		OBJ = pos,_val = __val;
		root = Change(root,1,n);
		return ;
	}
	inline int Query(int l,int r){
		OBJL = l,OBJR = r;
		return Query(root,1,n);
	}
	inline void Clear(){
		root = 0;
		return ;
	}
	inline int Root(){
		return node[root].val;
	}
};
class SegmentTreePlus{
private:
	SegmentTree sgt[MAXN * 8];
	int OBJ,pos,OBJL,OBJR,_val,queryL,queryR;
	void ChangeInner(int p,int l,int r){
		sgt[p].Change(pos,_val);
		if(l == r)return ;
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)ChangeInner(p*2,l,mid);
		if(mid < OBJ)ChangeInner(p*2+1,mid+1,r);
		return ;
	}
	int Query(int p,int l,int r){
		if(OBJL <= l && r <= OBJR){
			return sgt[p].Query(queryL,queryR);
		}
		const int mid = (l + r) >> 1;
		int ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
		return ret;
	}
public:
	inline void Change(int _OBJ,int _pos,int __val){
		OBJ = _OBJ,pos = _pos,_val = __val;
		ChangeInner(1,1,n);
		return ;
	}
	inline int Query(int l,int r,int _queryL,int _queryR){
		OBJL = l,OBJR = r,queryL = _queryL,queryR = _queryR;
		return Query(1,1,n);
	}
};
SegmentTreePlus tr;
SegmentTree sgt;
inline ll Solve(){
	ll ret = 0,A = 0,B = 0,X = 0;
	//CASE1 : 单个组成,一定成立
	ret += n;
	//CASE2 : 两个组成,排除一个完泉比另外一个大的
	ret += 1ll * n * (n-1) / 2;
	for(int i = 1;i <= n;i++){
		ll mn = tr.Query(1,st[i].b,1,st[i].c);
		A += mn * (mn-1) / 2;
		ret -= mn;
		tr.Change(st[i].b,st[i].c,1);
	}
	//CASE3 : 三个组成,分两种情况
	ret += 1ll * n * (n-1) * (n-2) / 6;
	//先排除有一个比另外两个都泉部更大,即A
	//已经在上面顺便计算了
	
	//一个的AB都要更大
	for(int i = 1;i <= n;i++){
		ll mn = sgt.Query(1,st[i].b);
		X += (mn) * (mn-1) / 2;
		sgt.Change(st[i].b,1);
	}
	//一个的AC都要更大
	sgt.Clear();
	for(int i = 1;i <= n;i++){
		ll mn = sgt.Query(1,st[i].c);
		X += (mn) * (mn-1) / 2;
		sgt.Change(st[i].c,1);
	}
	//一个的BC都要更大
	sgt.Clear();
	sort(st+1,st+n+1,CmpByB);
	for(int i = 1;i <= n;i++){
		ll mn = sgt.Query(1,st[i].c);
		X += (mn) * (mn-1) / 2;
		sgt.Change(st[i].c,1);
	}
	B = X - 3 * A;
	ret -= A + B;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subset/subset1.in","r",stdin);
//	freopen("subset.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>st[i].a;
	for(int i = 1;i <= n;i++)cin>>st[i].b;
	for(int i = 1;i <= n;i++)cin>>st[i].c;
	sort(st+1,st+n+1,Cmp);
	cout<<Solve()<<endl;
	return not(Akano loves pure__Elysia);
}
