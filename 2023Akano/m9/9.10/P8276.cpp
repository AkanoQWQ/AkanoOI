#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 2e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,IN[MAXN],belong[MAXN],nxt[MAXN];
vector<int> control[MAXN];
bitset<MAXN> alive;
//把一个点和它的所有出边的控制点的关系建成边得到图为controlEdge
//一个点到某个控制点的路径可能不止一条,所以这个图的边可能会出现很多次 
unordered_map<int,int> controlEdge[MAXN];
int controlOut[MAXN];//新图中的出度,为 1 则说明它被某点(后继nxt)控制
bool vis[MAXN];//这个vis拿来干嘛暂时没搞清 
inline void Update(int u,int oldV,int newV,queue<int>& q){
	//注意,此处有 belong[u] == oldV
	//说白了,就是u自己修改belong导致它的出边也会跟着改
	//记住,这里是反边,因为是反向更新 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		controlEdge[v][oldV]--;
		if(controlEdge[v][oldV] == 0)controlOut[v]--;
		if(controlEdge[v][newV] == 0)controlOut[v]++;
		controlEdge[v][newV]++;
		if(controlOut[v] == 1){
			vis[v] = true;
			q.push(v);
		}
	}
	belong[u] = newV;//自己也改颜色了 
	return ;
}
inline void Merge(int u,int v,queue<int>& q){
	//暂时没看懂这一句是为什么,难道不应该此时 belong[u] = u吗 
	u = belong[u],v = belong[v];
	if(u == v)return ;
	if(control[u].size() < control[v].size())swap(u,v);
	for(auto i : control[v]){
		Update(i,v,u,q);//修改使得在controlEdge图上的 i->belong[v] 边变成 i->belong[u]
		//注意这里的u,v 已经变为 belong[u,v] 了 
		control[u].push_back(i); 
	}
	control[v].clear();
	return ;
}
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(v,u);//建反向边
		IN[u]++; 
	}
	return ;
}
inline void Remake(){
	queue<int> q;
	vector<pair<int,int> > saveEdge;
	for(int i = 1;i <= n;i++){
		alive[i] = true;//初始化
		if(IN[i] == 0)q.push(i);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		alive[u] = false;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			IN[v]--;
			if(IN[v] == 0)q.push(v);
		}
	}
	for(int u = 1;u <= n;u++){
		if(!alive[u])continue;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(!alive[v])continue;
			saveEdge.push_back(make_pair(u,v));
			//不能把边反回来!看Update,新图依旧是反边 
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : saveEdge){
		AddEdge(i.first,i.second);
	}
	return ;
}
inline void Pre(){
	queue<int> q;
	for(int u = 1;u <= n;u++){
		if(!alive[u])continue;
		belong[u] = u;
		control[u].push_back(u);//自己当然控制自己了 
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			//nxt表示一个点的后继,如果它的出边颜色只有一种,那么一定和它的后继的颜色一样
			//nxt可以初始化为任意一个连向的点,反正如果所有出边颜色相同,那么随便选一个都行 
			
			//记住,这里是反边! 
			nxt[v] = u;
			if(controlEdge[v][u] == 0)controlOut[v]++;
			controlEdge[v][u]++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(alive[i] && controlOut[i] == 1){
			vis[i] = true;//为什么原题解没有这句话?不过加不加都能过 
			q.push(i);
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		Merge(u,nxt[u],q);
	}
	return ;
}
inline void Solve(){
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		if(!alive[u] || !alive[v]){
			cout<<"B";
		}else if(belong[u] != belong[v]){
			cout<<"H";
		}else{
			cout<<"B";
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Remake();
	Pre();
	Solve();
	return not(Akano loves pure__Elysia);
}
