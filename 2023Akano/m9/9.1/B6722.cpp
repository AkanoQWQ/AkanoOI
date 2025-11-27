#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e4 + 1018 + 1108;
const int MAXM = 106;
const int MAXVAL = 1e7 + 1018 + 1108; 
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
};
ClearableArray<bool,MAXVAL> vis;
bool solved[MAXN],ans[MAXM];
int n,q,ask[MAXM],siz[MAXN],mss[MAXN],root;
vector<int> dis;
void GetDis(int u,int fa,int nowdis){
	if(nowdis > 1e7)return ;
	dis.push_back(nowdis); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v] || v == fa)continue;
		GetDis(v,u,nowdis + e[i].val);
	}
	return ;
}
inline void Calc(int u){
	vis.Clear();
	vis[0] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dis.clear();
		GetDis(v,u,e[i].val);
		for(auto d : dis){
			for(int i = 1;i <= q;i++){
				if(ask[i]-d >= 0 && vis[ask[i]-d])ans[i] = true;
			}
		}
		for(auto d : dis){
			vis[d] = true;
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
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i];
	}
	mss[0] = 1e9;
	cnt = n,root = 0;
	GetSize(1,1);
	GetSize(root,root);
	Solve(root);
	for(int i = 1;i <= q;i++){
		if(ans[i]){
			cout<<"AYE"<<endl;
		}else{
			cout<<"NAY"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
