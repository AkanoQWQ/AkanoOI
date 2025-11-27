#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int n,a[MAXN];
template<class Comp,int defaultVal>
class SegmentTree{
private:
	Comp cmper;
	int val[MAXN * 4];
	void Build(int p,int l,int r,int* arr){
		if(l == r){
			val[p] = arr[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid,arr),Build(p*2+1,mid+1,r,arr);
		val[p] = cmper(val[p*2],val[p*2+1]);
		return ;
	}
	int Query(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return val[p];
		}
		const int mid = (l + r) >> 1;
		int ret = defaultVal;
		if(mid >= OBJL)ret = cmper(ret,Query(p*2,l,mid,OBJL,OBJR));
		if(mid < OBJR)ret = cmper(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
		return ret;
	}
public:
	inline void Build(int* arr){
		Build(1,1,n,arr);
		return ;
	}
	inline int Query(int l,int r){
		return Query(1,1,n,l,r);
	}
};
class MinClass{
public:
	int operator()(int x1,int x2){
		return min(x1,x2);
	}
};
class MaxClass{
public:
	int operator()(int x1,int x2){
		return max(x1,x2);
	}
};
SegmentTree<MinClass,MAXN> ltr[22];
SegmentTree<MaxClass,1> rtr[22];
int l[22][MAXN],r[22][MAXN],nowl[MAXN],nowr[MAXN],qry[MAXN],saveL[MAXN],saveR[MAXN];
inline bool Judge(){
	for(int i = 0;i <= n+2;i++){
		qry[i] = n+1;
	}
	for(int u = 1;u <= n;u++){
		qry[u] = min(qry[u],qry[u-1]);
		if(nowl[u] > qry[u]){
			return false;
		}
		if(qry[nowr[u]+1] == n+1)qry[nowr[u]+1] = u;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("jump/jump3.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		l[0][i] = max(1,i - a[i]);
		r[0][i] = min(n,i + a[i]);
	}
	ltr[0].Build(l[0]),rtr[0].Build(r[0]);
	for(int i = 1;i <= 20;i++){
		for(int u = 1;u <= n;u++){
			l[i][u] = ltr[i-1].Query(l[i-1][u],r[i-1][u]);
			r[i][u] = rtr[i-1].Query(l[i-1][u],r[i-1][u]);
		}
		ltr[i].Build(l[i]),rtr[i].Build(r[i]);
	}
	int ans = 0;
	for(int u = 1;u <= n;u++){
		nowl[u] = nowr[u] = u;
	}
	for(int i = 20;i >= 0;i--){
		memcpy(saveL,nowl,sizeof(nowl)),memcpy(saveR,nowr,sizeof(nowr));//save
		for(int u = 1;u <= n;u++){
			int orgl = nowl[u],orgr = nowr[u];
			nowl[u] = ltr[i].Query(orgl,orgr);
			nowr[u] = rtr[i].Query(orgl,orgr);
		}
		if(Judge()){
			memcpy(nowl,saveL,sizeof(nowl)),memcpy(nowr,saveR,sizeof(nowr));//load
		}else{
			ans += (1<<i);
		}
	}
	cout<<ans+1<<endl;
	return not(Akano loves pure__Elysia);
}
