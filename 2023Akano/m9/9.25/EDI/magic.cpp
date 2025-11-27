#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int MAXN = 5e5 + 1018 + 1108;
int n,t,a[MAXN];
vector<pii> xy;
stack<int,vector<int> > stk;
bool Cmp(pii p1,pii p2){
	if(p1.first != p2.first)return p1.first > p2.first;
	return p1.second > p2.second;
}
struct Query{
	int l,r,id;
}ask[MAXN];
bool CmpAsk(Query q1,Query q2){
	if(q1.l != q2.l)return q1.l > q2.l;
	return q1.r > q2.r;
}
class SegmentTree{
	private:
		struct Node{
			ll mxval,ans,lazy;
		}node[MAXN * 4];
		inline void PushUp(int p){
			node[p].mxval = max(node[p*2].mxval,node[p*2+1].mxval);
			node[p].ans = max(node[p*2].ans,node[p*2+1].ans);
			return ;
		}
		inline void PushDown(int p){
			if(!node[p].lazy)return ;
			node[p*2].lazy = max(node[p*2].lazy,node[p].lazy);
			node[p*2+1].lazy = max(node[p*2+1].lazy,node[p].lazy);
			node[p*2].ans = max(node[p*2].ans,node[p*2].mxval + node[p].lazy);
			node[p*2+1].ans = max(node[p*2+1].ans,node[p*2+1].mxval + node[p].lazy);
			node[p].lazy = 0;
			return ;
		}
		void Build(int p,int l,int r){
			node[p].lazy = 0;
			if(l == r){
				node[p].mxval = node[p].ans = a[l];
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,ll _val){
			if(OBJL <= l && r <= OBJR){
				node[p].ans = max(node[p].ans,node[p].mxval + _val);
				node[p].lazy = max(node[p].lazy,_val);
				return ;
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,_val);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,_val);
			PushUp(p);
			return ;
		}
		ll Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return node[p].ans;
			}
			const int mid = (l + r) >> 1;
			ll ret = 0;
			PushDown(p);
			if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void Change(int l,int r,ll _val){
			if(l > r)return ;
			Change(1,1,n,l,r,_val);
			return ;
		}
		inline ll Query(int l,int r){
			return Query(1,1,n,l,r);
		}
}tr;
ll ans[MAXN];
inline void AddPair(pii pr){
	const int u = pr.first,v = pr.second;
	const int OBJ = v + (v - u);
	if(OBJ <= n)tr.Change(OBJ,n,a[u] + a[v]);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("magic/magic2.in","r",stdin);
	freopen("magic/magic2.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++){
		while(!stk.empty() && a[stk.top()] <= a[i]){
			const int tp = stk.top();
			xy.emplace_back(tp,i);
			stk.pop();
			if(!stk.empty())xy.emplace_back(stk.top(),tp);
		}
		stk.push(i);
	}
	while(stk.size() >= 2){
		const int tp = stk.top();
		stk.pop();
		xy.emplace_back(stk.top(),tp);
	}
	tr.Build();
	sort(xy.begin(),xy.end(),Cmp);
	cin>>t;
	for(int i = 1;i <= t;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+t+1,CmpAsk);
	auto it = xy.begin();
	for(int i = 1;i <= t;i++){
		while(it != xy.end() && it->first >= ask[i].l){
			AddPair(*it);
			it++;
		}
		ans[ask[i].id] = tr.Query(ask[i].l,ask[i].r);
	}
	for(int i = 1;i <= t;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
