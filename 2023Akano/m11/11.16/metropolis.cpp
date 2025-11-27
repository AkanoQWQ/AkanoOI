#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 10 + 18;
constexpr int MAXM = 1e6 + 10 + 18;
constexpr ll INF = 200610181108;
constexpr int iINF = 1e9 + 1018 + 1108;
constexpr int NodeSize = 1.2e7;

bool _ST_; 

struct Edge{
	int nxt,to,val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}

int n,m;
int pos[MAXN];
vector<ll> dir2dis;

bool vis[MAXN];
vector<int> pre[MAXN];

inline void Dij(){
	priority_queue<pair<int,int> > q;
	int* dis = pos;
	for(int i = 1;i <= n;i++){
		dis[i] = iINF; 
	}
	dis[1] = 0,q.push({-dis[1],1});
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[u] + e[i].val < dis[v]){
				dis[v] = dis[u] + e[i].val;
				q.push({-dis[v],v});
				pre[v].clear();
				pre[v].push_back(u);
			}else if(dis[u] + e[i].val == dis[v]){
				pre[v].push_back(u);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		vis[i] = false;
	}
	queue<int> kueue;
	kueue.push(n),vis[n] = true;
	while(!kueue.empty()){
		const int u = kueue.front();
		kueue.pop();
		for(auto v : pre[u]){
			if(vis[v])continue;
			kueue.push(v),vis[v] = true;
		}
		pre[u].clear();
		pre[u].shrink_to_fit();
	}
	return ;
}
inline void Prepare(){
	int* dis = pos;
	for(int i = 1;i <= n;i++){
		if(vis[i]){
			dir2dis.push_back(dis[i]);
		}
	}
	sort(dir2dis.begin(),dir2dis.end());
	dir2dis.erase(unique(dir2dis.begin(),dir2dis.end()),dir2dis.end());
	for(int i = 1;i <= n;i++){
		if(vis[i]){
			pos[i] = lower_bound(dir2dis.begin(),dir2dis.end(),dis[i]) - dir2dis.begin() + 1;
		}else{
			pos[i] = -1;
		}
	}
	dir2dis.insert(dir2dis.begin(),-10181108);
	return ;
}
vector<int> way[MAXN],pdis[MAXN],farpos[MAXN];
vector<pair<int,int> > dir[MAXN];

struct Segment{
	int k;
	ll b;
	Segment(){
		k = 0,b = -INF;
		return ;
	}
	Segment(ll _k,ll _b){
		k = _k,b = _b;
		return ;
	}
	inline ll Calc(ll x){
		return k * dir2dis[x] + b;
	}
};
struct Node{
	Segment lazy;
	int l,r;
}node[NodeSize];
int tot;
class LiChaoSegmentTree{
private:
	int root;
	void PushDown(int& p,int l,int r,Segment v){
		if(!p)p = ++tot;
		Segment& u = node[p].lazy;
		const int mid = (l + r) >> 1;
		if(v.Calc(mid) > u.Calc(mid))swap(u,v);
		if(l == r)return ;//²»¼ÌÐøPushDownÁË 
		if(v.Calc(l) > u.Calc(l)){
			PushDown(node[p].l,l,mid,v);
		}
		if(v.Calc(r) > u.Calc(r)){
			PushDown(node[p].r,mid+1,r,v);
		}
		return ;
	}
	ll Query(int p,int l,int r,int OBJ){
		if(!p)return -INF;
		ll ret = node[p].lazy.Calc(OBJ);
		if(l == r){
			return ret;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)ret = max(ret,Query(node[p].l,l,mid,OBJ));
		if(mid < OBJ)ret = max(ret,Query(node[p].r,mid+1,r,OBJ));
		return ret;
	}
	void Change(int& p,int l,int r,int OBJL,int OBJR,Segment seg){
		if(!p)p = ++tot;
		if(OBJL <= l && r <= OBJR){
			PushDown(p,l,r,seg);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Change(node[p].l,l,mid,OBJL,OBJR,seg);
		if(mid < OBJR)Change(node[p].r,mid+1,r,OBJL,OBJR,seg);
		return ;
	}
public:
	inline void Insert(Segment seg){
		return PushDown(root,1,n,seg);
	}
	inline ll Query(ll x){
		return Query(root,1,n,x);
	}
	inline void Clear(){
		root = 0;
		return ;
	}
}tr[MAXN];

ll f[MAXN];
vector<int> dpqueue;
bool CmpByDis(int u,int v){
	return pos[u] < pos[v];
}

bool _ED_;

int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
//	freopen("metropolis.in","r",stdin); 
//	freopen("metropolis.out","w",stdout);
	cerr<<(&_ST_ - &_ED_) / 1024. / 1024.<<" MiB used"<<endl;
	cerr<<sizeof(node) / 1024. / 1024.<<" MiB used"<<endl;
	cin>>n>>m;
	for(int i = 1,siz;i <= m;i++){
		cin>>siz;
		way[i].resize(siz + 3),pdis[i].resize(siz + 3);
		
		vector<int>& nowway = way[i];
		vector<int>& nowdis = pdis[i];
		
		for(int j = 1;j <= siz;j++){
			cin>>nowway[j]>>nowdis[j]; 
			dir[nowway[j]].emplace_back(i,j);
			if(j > 1){
				AddEdge(nowway[j-1],nowway[j],nowdis[j-1]);
			}
		}
		cin>>nowway[siz + 1];
		dir[nowway[siz + 1]].emplace_back(i,siz + 1);
		AddEdge(nowway[siz],nowway[siz+1],nowdis[siz]);
	}
	Dij();
	Prepare();
	for(int pathNo = 1;pathNo <= m;pathNo++){
		int siz = way[pathNo].size() - 3;
		farpos[pathNo].resize(siz + 3);
		vector<int>& nowway = way[pathNo];
		vector<int>& nowdis = pdis[pathNo];
		vector<int>& nowfar = farpos[pathNo];
		const int nowsize = siz;
		nowfar[nowsize + 1] = pos[nowway[nowsize + 1]];
		for(int i = siz;i >= 1;i--){
			if(dir2dis[pos[nowway[i]]] + nowdis[i] == dir2dis[pos[nowway[i+1]]]){
				nowfar[i] = nowfar[i+1];
			}else{
				nowfar[i] = -1;
			}
			nowfar[i] = max(nowfar[i],pos[nowway[i]]);
		}
	}
	for(int i = 1;i <= n;i++){
		f[i] = -INF;
		if(!vis[i])continue;
		dpqueue.push_back(i);
	}
	f[1] = 0;
	sort(dpqueue.begin(),dpqueue.end(),CmpByDis);
	for(auto u : dpqueue){
		for(auto inWhere : dir[u]){
			const int pathNo = inWhere.first;
			f[u] = max(f[u],tr[pathNo].Query(pos[u]) + 1ll * dir2dis[pos[u]] * dir2dis[pos[u]]);
		}
		for(auto inWhere : dir[u]){
			const int pathNo = inWhere.first,pathPos = inWhere.second;
			vector<int>& nowway = way[pathNo];
			vector<int>& nowdis = pdis[pathNo];
			vector<int>& nowfar = farpos[pathNo];
			if(dir2dis[pos[nowway[pathPos]]] + nowdis[pathPos] != dir2dis[pos[nowway[pathPos+1]]]){
				tr[pathNo].Clear();
			}else if(nowfar[pathPos] > pos[u]){ 
				tr[pathNo].Insert(Segment(-2 * dir2dis[pos[u]],1ll * dir2dis[pos[u]] * dir2dis[pos[u]] + f[u]));
			}
		}
	}
	cout<<dir2dis[pos[n]]<<" "<<f[n]<<endl;
	return 0;
}
