#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
const int MAXN = 1e5 + 6;
const int LSZ = 22;//LCA size
const int LRG = 20;//LCA range
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,val;
}e[MAXN * 2],e2[MAXN * 2];
int head[MAXN],cnt,c2,h2[MAXN];
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
class Stack{
	private:
		int c[MAXN],tail;
	public:
		inline int Top(){
			return c[tail];
		}
		inline void Push(const int& _x){
			c[++tail] = _x;
			return ;
		}
		inline void Pop(){
			if(!tail)return ;
			--tail;
			return ;
		}
		inline int Kth(int u){
			if(tail-u < 0)return 0;
			return c[tail-u];
		}
		inline void Clear(){
			tail = 0;
			return ;
		}
		inline int Size(){
			return tail;
		}
		inline void Print(){
			for(int i = 1;i <= tail;i++){
				Write(c[i]),putchar(' ');
			}
			putchar('\n');
			return ;
		}
}stk,estk,kue;
inline void AE2(int from,int to,int val){
	kue.Push(from);
	e2[++c2].to = to;
	e2[c2].val = val;
	e2[c2].nxt = h2[from];
	h2[from] = c2;
	return ;
}
int n,q,dep[MAXN],dfn[MAXN],dnt,fa[MAXN][LSZ],dis[MAXN];
void dfs(int u){
	dfn[u] = ++dnt;
	for(int i = 1;i <= LRG;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		fa[v][0] = u,dep[v] = dep[u] + 1,dis[v] = dis[u] + e[i].val;
		dfs(v);
	}
	return ;
}
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = LRG;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = LRG;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
bool cmp(int ia,int ib){
	return dfn[ia] < dfn[ib];
}
int Tans,T[MAXN];
bool EST[MAXN];
void DP(int u,int father){
	T[u] = 0;
	if(EST[u]){
		T[u] = 1;
		Tans += dis[u];
	}
	for(int i = h2[u];i;i = e2[i].nxt){
		const int v = e2[i].to;
		if(v == father)continue ;
		DP(v,u);
		T[u] += T[v];
	}
	Tans -= (T[u]-1) * dis[u];
	T[u] = 1;
	return ;
}
inline void Clear(){
	while(estk.Size() >= 1){
		EST[estk.Top()] = false;
		estk.Pop();
	}
	while(kue.Size() >= 1){
		h2[kue.Top()] = 0;
		kue.Pop();
	}
	c2 = 0;
	return ;
}
int main(){
	n = Read();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read(),w = Read();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	fa[1][0] = 1;
	dfs(1);
	q = Read();
	while(q--){
		int k = Read();
		vi imp;imp.reserve(k);
		while(k--)imp.push_back(Read());
		sort(imp.begin(),imp.end(),cmp);
		stk.Clear();
		stk.Push(1);
		for(auto i : imp){//Add i
			EST[i] = true;estk.Push(i);
			const int lc = LCA(i,stk.Top());
			if(lc == stk.Top()){
				stk.Push(i);
				continue;
			}
			if(dfn[lc] >= dfn[stk.Kth(1)]){
				const int u = lc,v = stk.Top();
				AE2(u,v,dis[v] - dis[u]);
				AE2(v,u,dis[v] - dis[u]);
				stk.Pop();
				if(lc != stk.Top())stk.Push(lc);
				stk.Push(i);
				continue;
			}
			while(dep[lc] < dep[stk.Kth(1)]){
				const int u = stk.Kth(1),v = stk.Top();
				AE2(u,v,dis[v] - dis[u]);
				AE2(v,u,dis[v] - dis[u]);
				stk.Pop();
			}
			if(dfn[lc] >= dfn[stk.Kth(1)]){//SIT 2
				const int u = lc,v = stk.Top();
				AE2(u,v,dis[v] - dis[u]);
				AE2(v,u,dis[v] - dis[u]);
				stk.Pop();
				if(lc != stk.Top())stk.Push(lc);
				stk.Push(i);
				continue;
			}
			stk.Print();
		}
		while(stk.Size() >= 2){
			const int u = stk.Kth(1),v = stk.Top();
			AE2(u,v,dis[v] - dis[u]);
			AE2(v,u,dis[v] - dis[u]);
			stk.Pop();
		}
		DP(1,1);
		Clear();
		Write(Tans),putchar('\n');Tans = 0;
	}
	return 0;
}


