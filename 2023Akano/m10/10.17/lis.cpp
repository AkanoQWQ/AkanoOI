#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
ll n,m,a[MAXN],b[MAXN],sum,prearr[MAXN],mxpos,nowans;
struct Segment{
	int l,r;
	ll val;
	Segment() = default;
	Segment(int _l,int _r,ll _val){
		l = _l,r = _r,val = _val;
		return ;
	}
};
Segment operator+(Segment segl,Segment segr){//记得分lr
	return Segment(segl.l,segr.r,segl.val + segr.val);
}
bool operator<(Segment seg1,Segment seg2){
	return seg1.val < seg2.val;
}
struct Node{//C++逆天语法,如果把这段代码放在 SegmentTree类中,会把 operator+ 识别为 Node 的成员函数!
	Segment pre,suf,tot,maxseg;
};
Node operator+(Node nl,Node nr){
	Node ret;
	ret.pre = max(nl.pre,nl.tot + nr.pre),ret.suf = max(nr.suf,nl.suf + nr.tot);
	ret.tot = nl.tot + nr.tot;
	ret.maxseg = max(max(nl.maxseg,nr.maxseg),nl.suf + nr.pre);
	return ret;
}
class SegmentTree{
private:
	Node now[MAXN * 4],inv[MAXN * 4];
	bool lazy[MAXN * 4];
	inline void PushUp(int p){
		now[p] = now[p*2] + now[p*2+1];
		inv[p] = inv[p*2] + inv[p*2+1];
		return ;
	}
	inline void PushDown(int p){
		if(!lazy[p])return ;
		swap(now[p*2],inv[p*2]),swap(now[p*2+1],inv[p*2+1]);
		lazy[p*2] ^= 1,lazy[p*2+1] ^= 1;
		lazy[p] = 0;
		return ;
	}
	void Build(int p,int l,int r){
		if(l == r){
			now[p].pre = now[p].suf = now[p].tot = now[p].maxseg = Segment(l,l,b[l]);
			inv[p].pre = inv[p].suf = inv[p].tot = inv[p].maxseg = Segment(l,l,-b[l]);
			lazy[p] = false;
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	void Reverse(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			swap(now[p],inv[p]);
			lazy[p] ^= 1;
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Reverse(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)Reverse(p*2+1,mid+1,r,OBJL,OBJR);
		PushUp(p);
		return ;
	}
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline void Reverse(int l,int r){
		if(l > r)return ;
		Reverse(1,1,n,l,r);
		return ;
	}
	inline Segment Query(){
		return now[1].maxseg;
	}
}tr;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
		if(a[i] == 1){
			sum += b[i];
			b[i] = -b[i];
		}
	}
	for(int i = 1;i <= n;i++){
		prearr[i] = prearr[i-1] + b[i];
		if(prearr[i] > prearr[mxpos])mxpos = i;
	}
	tr.Build();
	nowans = prearr[mxpos] + sum;
	cout<<nowans<<'\n';
	tr.Reverse(1,mxpos);
	cin>>m;
	for(int i = 1;i <= m;i++){
		auto seg = tr.Query();
		if(seg.val > 0){
			tr.Reverse(seg.l,seg.r);
			nowans += seg.val;
		}
		cout<<nowans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
