#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 1e14;
struct Segment{
	ll k,b;
	Segment(){
		k = 0,b = -INF;
		return ;
	}
	Segment(ll _k,ll _b){
		k = _k,b = _b;
		return ;
	}
	inline ll Calc(ll x){
		return k * x + b;
	}
};
ostream& operator<<(ostream& os,Segment seg){
	os<<"("<<seg.k<<"*x+"<<seg.b<<")";
	return os;
}
inline bool Cmp(Segment s1,Segment s2,ll x){
	ll _y1 = s1.Calc(x),_y2 = s2.Calc(x);
	return _y1 > _y2;//还是说要反过来?
}
ll n,a[MAXN];
class LiChaoSegmentTree{
private:
	Segment lazy[MAXN * 4];
	struct SaveNode{
		Segment seg;
		int point;
		SaveNode() = default;
		SaveNode(Segment _seg,int _point){
			seg = _seg,point = _point;
			return ;
		}
	};
	stack<SaveNode> history;
	inline void Save(int p,Segment seg){
		history.push(SaveNode(seg,p));
		return ;
	}
	void PushDown(int p,int l,int r,Segment v){
		Segment& u = lazy[p];
		const int mid = (l + r) >> 1;
		if(Cmp(v,u,mid)){
			Save(p,u);
			swap(u,v);
		}
		bool psdL = Cmp(v,u,l),psdR = Cmp(v,u,r);
		if(psdL)PushDown(p*2,l,mid,v);
		if(psdR)PushDown(p*2+1,mid+1,r,v);
		return ;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR,Segment v){
		if(OBJL <= l && r <= OBJR){
			PushDown(p,l,r,v);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,v);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,v);
		return ;
	}
	ll Query(int p,int l,int r,int pos){
		ll ret = lazy[p].Calc(pos);
		if(l == r)return ret;
		const int mid = (l + r) >> 1;
		if(mid >= pos)ret = max(ret,Query(p*2,l,mid,pos));
		if(mid < pos)ret = max(ret,Query(p*2+1,mid+1,r,pos));
		return ret;
	}
public:
	inline void Change(int l,int r,Segment v){
		Change(1,1,n,l,r,v);
		return ;
	}
	inline ll Query(int pos){
		return Query(1,1,n,pos);
	}
	inline int GetHistorySize(){
		return history.size();
	}
	inline bool Load(){
		if(history.empty())return false;
		SaveNode node = history.top();
		history.pop();
		lazy[node.point] = node.seg;
		return true;
	}
}tr;
stack<pair<int,int> > version;//first记录版本对应的下标,second记录版本大小
ll pre[MAXN],suf[MAXN];
inline void Execute(ll* f){
	while(!version.empty())version.pop();
	bool suc = tr.Load();
	while(suc){
		suc = tr.Load();
	}
	for(int i = 1;i <= n;i++){
		while(!version.empty() && a[version.top().first] >= a[i]){//为什么有等于号?因为不如以现在为起点
			while(tr.GetHistorySize() > version.top().second){
				tr.Load();
			}
			version.pop();
		}
		const int lst = (version.empty()) ? (0) : (version.top().first);
		version.push(make_pair(i,tr.GetHistorySize()));
		tr.Change(1,n,Segment(a[i],-a[i] * lst));//这里要注意long long......把a数组开成ll就过了......
		f[i] = max(tr.Query(i),f[i-1]);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("B8301.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	Execute(pre);
	reverse(a+1,a+n+1);
	Execute(suf);
	reverse(suf+1,suf+n+1);
	for(int i = 1;i <= n;i++){
		cout<<max(pre[i-1],suf[i+1])<<'\n';
	}
	return 0;
}
