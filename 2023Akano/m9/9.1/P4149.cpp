#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXVAL = 1e6 + 1018 + 1108;
const int INF = 1e9;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
template<typename T,int SIZE>
class ClearableArray{
	private:
		bool vis[SIZE];
		queue<int> clearQueue;
		T content[SIZE];
	public:
		T& operator[](int x){
			if(!vis[x]){
				vis[x] = true,clearQueue.push(x);
			}
			return content[x];
		}
		inline void Clear(){
			while(!clearQueue.empty()){
				const int u = clearQueue.front();
				clearQueue.pop();
				vis[u] = false,content[u] = T();
			}
			return ;
		}
		inline void ClearWithVal(T _val){
			while(!clearQueue.empty()){
				const int u = clearQueue.front();
				clearQueue.pop();
				vis[u] = false,content[u] = _val;
			}
			return ;
		}
		inline void Set(T _val){
			for(int i = 0;i < SIZE;i++)content[i] = _val;
			return ;
		} 
};
ClearableArray<int,MAXVAL> vis;
bool solved[MAXN];
int n,k,siz[MAXN],mss[MAXN],root,ans = INF;
vector<pair<int,int> > dis;
void GetDis(int u,int fa,int nowdis,int edgeNum){
	if(nowdis > 1e6)return ;
	dis.push_back(make_pair(edgeNum,nowdis)); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v] || v == fa)continue;
		GetDis(v,u,nowdis + e[i].val,edgeNum+1);
	}
	return ;
}
inline void Calc(int u){
	vis.ClearWithVal(INF);
	vis[0] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dis.clear();
		GetDis(v,u,e[i].val,1);
		for(auto d : dis){
			if(d.second <= k)ans = min(ans,vis[k-d.second] + d.first);
		}
		for(auto d : dis){
			vis[d.second] = min(vis[d.second],d.first);
		}
	}
	return ;
}
void GetSize(int u,int fa){
	mss[u] = 0,siz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],cnt - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
void Solve(int u){
	Calc(u);
	solved[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		cnt = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vis.Set(INF);
	cin>>n>>k;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//BSOJ编号  B3989,下标从0开始 
		//u++,v++;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	mss[0] = 1e9;
	cnt = n,root = 0;
	GetSize(1,1);
	GetSize(root,root);
	Solve(root);
	if(ans >= INF)ans = -1;
	cout<<ans<<endl; 
	return not(Akano loves pure__Elysia);
}
