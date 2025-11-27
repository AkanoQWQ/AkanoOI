#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const int MOD = 998244353;
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
int n,root = 2;
ll f[MAXN][2],eval[MAXN],temp[2];//0朝下,1朝上 
bool Cmp(int i1,int i2){
	return eval[i1] < eval[i2];
}
void dfs(int u,int fa){
	vector<int> vec;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		eval[v] = e[i].val;
		dfs(v,u);
		vec.push_back(v);
	}
	sort(vec.begin(),vec.end(),Cmp);
	temp[0] = 1,temp[1] = 0;//0没有朝上的,1已经有朝上的了
	//当前选择朝上 
	for(auto v : vec){
		ll nxt0 = 0,nxt1 = 0;
		//选择朝下
		nxt0 += temp[0] * f[v][0];
		//选择朝上
		if(eval[v] > eval[u] || eval[u] == -1){
			nxt1 += temp[0] * f[v][1];
			nxt1 += temp[1] * f[v][1];
		}
		temp[0] = nxt0 % MOD,temp[1] = nxt1 % MOD;
	}
	f[u][1] = (temp[0] + temp[1]) % MOD;
	
	temp[0] = 1,temp[1] = 0;//0没有朝上的,1已经有朝上的了
	//当前选择朝下 
	for(auto v : vec){
		ll nxt0 = 0,nxt1 = 0;
		//选择朝下
		if(eval[v] < eval[u] || eval[u] == -1){
			nxt0 += temp[0] * f[v][0];
		}
		//选择朝上
		nxt1 += temp[0] * f[v][1];
		nxt1 += temp[1] * f[v][1];
		temp[0] = nxt0 % MOD,temp[1] = nxt1 % MOD;
	}
	f[u][0] = (temp[0] + temp[1]) % MOD;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("direction.in","r",stdin);
	freopen("direction.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v,i),AddEdge(v,u,i);
	}
	eval[root] = -1;
	dfs(root,root);
	cout<<f[root][0]<<endl;
	return not(Akano loves pure__Elysia);
}
