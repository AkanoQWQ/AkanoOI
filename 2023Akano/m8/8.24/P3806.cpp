#include<bits/stdc++.h>
using namespace std;
const int MAXVAL = 1e7 + 1018 + 1108;
const int MAXN = 1e4 + 1018 + 1108; 
template<typename T,int SIZE>
class ClearableArray{
	private:
		T _content[SIZE];
		bool _vis[SIZE];
		queue<int> clearQueue;
	public:
		T& operator[](int _x){
			if(!_vis[_x]){
				_vis[_x] = true,clearQueue.push(_x);
			}
			return _content[_x];
		}
		inline T& at(int _x){
			assert(_x < SIZE && _x >= 0);
			return operator[](_x);
		}
		inline void Clear(){
			while(!clearQueue.empty()){
				const int _u = clearQueue.front();
				clearQueue.pop();
				_vis[_u] = false;
				_content[_u] = T();
			}
			return ;
		}
		inline int Size(){
			return clearQueue.size();
		}
};
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],ent;
inline void AddEdge(int from,int to,int val){
	e[++ent].to = to;
	e[ent].val = val;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
ClearableArray<bool,MAXVAL> cnt;
int n,q,k[MAXN];
bool ans[MAXN];
//µÌ∑€÷  
int siz[MAXN],mss[MAXN],root,sum;//maxSubtreeSize
bool solved[MAXN];
void GetSize(int u,int fa){
	siz[u] = 1,mss[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],sum - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
vector<int> dist;
void GetDis(int u,int fa,int val){
	if(val >= MAXVAL)return ;
	dist.push_back(val);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetDis(v,u,val + e[i].val);
	}
	return ;
}
inline void Calc(int u){
	cnt.Clear();
	cnt[0] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dist.clear();
		GetDis(v,u,e[i].val);
		for(auto dis : dist){
			for(int nowq = 1;nowq <= q;nowq++){
				if(k[nowq] >= dis){
					ans[nowq] |= cnt[k[nowq] - dis];
				}
			}
		}
		for(auto dis : dist)cnt[dis] = true;
	}
	return ;
}
void Solve(int u){
	solved[u] = true;
	Calc(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		sum = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root); 
	}
	return ;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	mss[0] = 1e9;
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	for(int i = 1;i <= q;i++){
		cin>>k[i];
	}
	sum = n;
	GetSize(1,1),GetSize(root,root);
	Solve(root);
	for(int i = 1;i <= q;i++){
		if(ans[i]){
			cout<<"AYE"<<endl;
		}else{
			cout<<"NAY"<<endl;
		}
	}
	return 0;
}
