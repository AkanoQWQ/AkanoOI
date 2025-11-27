#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXLG = 20;
vector<int> vec;
int n,m,tail,now = 1;
ll pre = 1;
struct Node{
	int l,r,tot;
	ll sum;
};
class PersistentSegmentTree{
	private:
		Node node[MAXN*MAXLG*2];
		int tot;
		inline void PushUp(int p){
			node[p].tot = node[node[p].l].tot + node[node[p].r].tot;
			node[p].sum = node[node[p].l].sum + node[node[p].r].sum;
			return ;
		}
		int Insert(int u,int l,int r,int pos,int val){
			int p = ++tot;
			node[p] = node[u];
			if(l == r){
				node[p].tot += val,node[p].sum += 1ll * vec[pos-1] * val;
				return p;
			}
			const int mid = (l + r) >> 1;
			if(mid >= pos)node[p].l = Insert(node[p].l,l,mid,pos,val);
			if(mid < pos)node[p].r = Insert(node[p].r,mid+1,r,pos,val);
			PushUp(p);
			return p;
		}
		ll Query(int u,int l,int r,int k){
			if(!u)return 0;
//			cerr<<u<<" LR "<<l<<","<<r<<" tot "<<node[u].tot<<" sum "<<node[u].sum<<" query Kth "<<k<<endl;
//			cerr<<"nodeLR "<<node[u].l<<","<<node[u].r<<endl;
			if(node[u].tot <= k)return node[u].sum;
			if(l == r){
				return min(k,node[u].tot) * vec[l-1];
			}
			const int mid = (l + r) >> 1;
			ll ret = Query(node[u].l,l,mid,k);
			k -= node[node[u].l].tot;
			if(k > 0)ret += Query(node[u].r,mid+1,r,k);
			return ret;
		}
	public:
		int root[MAXN];
		inline void Insert(int oldVersion,int newVersion,int pos,int val){
//			cerr<<"ins "<<oldVersion<<" of "<<pos<<" val "<<val<<endl;
			root[newVersion] = Insert(root[oldVersion],1,m,pos,val);
			return ;
		}
		inline ll Query(int version,int k){
			return Query(root[version],1,m,k);
		}
}tr;
struct Operation{
	int myTime,val;
}opt[MAXN * 2];
bool Cmp(Operation op1,Operation op2){
	if(op1.myTime != op2.myTime)return op1.myTime < op2.myTime;
	return op1.val < op2.val;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for(int i = 1;i <= m;i++){
		int st,ed,val;
		cin>>st>>ed>>val;
		opt[++tail] = {st,val};
		opt[++tail] = {ed+1,-val};
		vec.push_back(val);
	}
	
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= tail;i++){
		if(opt[i].val > 0){
			opt[i].val = lower_bound(vec.begin(),vec.end(),opt[i].val) - vec.begin() + 1;
		}else{
			opt[i].val = -(lower_bound(vec.begin(),vec.end(),-opt[i].val) - vec.begin() + 1);
		}
	}
	
	sort(opt+1,opt+tail+1,Cmp);
	for(int i = 1;i <= n;i++){
		tr.root[i] = tr.root[i-1];
		while(now <= tail && opt[now].myTime == i){
			if(opt[now].val > 0){
				tr.Insert(i,i,opt[now].val,1);
			}else{
				tr.Insert(i,i,-opt[now].val,-1);
			}
			now++;
		}
	}
	for(int i = 1;i <= n;i++){
		int x,a,b,c;
		cin>>x>>a>>b>>c;
		int k = 1 + ((a * pre + b) % c);
		pre = tr.Query(x,k);
		cout<<pre<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
