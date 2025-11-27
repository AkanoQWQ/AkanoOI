#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 616;
const double startT = 20000 + 2006 + 1018 + 1108;
const double endT = 0.00000000000010181108;
const double deltaT = 0.997;
pii seg[MAXN];
vector<int> vec;
int n;
class SegmentTree{
private:
	typedef bitset<306> VIS;
	VIS node[MAXN * 4];
	int lazy[MAXN * 4];
	inline void PushUp(int p){
		node[p] = node[p*2] | node[p*2+1];
		return ;
	}
	inline void Assign(int p,int kol){
		node[p] = 0;
		node[p][kol] = true;
		return ;
	}
	inline void PushDown(int p){
		if(lazy[p] == 0)return ;
		Assign(p*2,lazy[p]);
		Assign(p*2+1,lazy[p]);
		lazy[p*2] = lazy[p*2+1] = lazy[p];
		lazy[p] = 0;
		return ;
	}
	void Build(int p,int l,int r){
		lazy[p] = 0;
		if(l == r){
			node[p] = 0;
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR,int kol){
		if(OBJL <= l && r <= OBJR){
			Assign(p,kol);
			lazy[p] = kol;
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,kol);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,kol);
		PushUp(p);
		return ;
	}
public:
	inline void Build(){
		Build(1,1,2*n);
		return ;
	}
	inline void Change(int l,int r,int kol){
		Change(1,1,2*n,l,r,kol);
		return ;
	}
	inline int Query(){
		return node[1].count();
	}
}tr;
inline int Calc(){
	tr.Build();
	for(int i = 1;i <= n;i++){
		tr.Change(seg[i].first,seg[i].second,i);
	}
	return tr.Query();
}
mt19937 rng(time(0));
int ans;
inline void SA(){
	double temp = startT;
	ans = Calc();
	while(temp > endT){
		int rd1 = (rng() % n) + 1,rd2 = (rng() % n) + 1;
		swap(seg[rd1],seg[rd2]);
		int newAns = Calc();
		if(newAns > ans){
			ans = newAns;
		}else if(exp(-(ans - newAns) / temp) * UINT_MAX > rng()){
			
		}else{
			swap(seg[rd1],seg[rd2]);
		}
		temp *= deltaT;
	}
	return ;
}
bool CmpByLen(pii p1,pii p2){
	return p1.second - p1.first > p2.second - p2.first;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("B8191/B8191.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>seg[i].first>>seg[i].second;
		vec.push_back(seg[i].first),vec.push_back(seg[i].second);
	}
	{
		sort(vec.begin(),vec.end());
		auto it = unique(vec.begin(),vec.end());
		vec.erase(it,vec.end());
		for(int i = 1;i <= n;i++){
			seg[i].first = lower_bound(vec.begin(),vec.end(),seg[i].first) - vec.begin() + 1;
			seg[i].second = lower_bound(vec.begin(),vec.end(),seg[i].second) - vec.begin() + 1;
		}
	}
	sort(seg+1,seg+n+1,CmpByLen);
	for(int i = 1;i <= 3;i++)SA();
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
