#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
const int MAXM = 150006;
const int INF = 0x7fffffff;
int n,m,s = 0,t = 2000,tot = 1,head[MAXN],mincost,maxflow;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct Edge{
	int to,cap,cost,nxt;	
}e[MAXM];
void AddEdge(int u,int v,int cap,int cost){
	e[++tot].cap = cap;
	e[tot].to = v;
	e[tot].cost = cost;
	e[tot].nxt = head[u];
	head[u] = tot;
	return ;
}
void awa(int from,int to,int v,int cost){
	AddEdge(from,to,v,cost);
	AddEdge(to,from,0,-cost);
	return ;
}
bool inq[MAXN];
int pre[MAXN],incf[MAXN],dis[MAXN];
queue<int> q;
bool SPFA(int st,int ed){
	memset(incf,0,sizeof(incf));
	memset(pre,0,sizeof(pre));
	for(int i = 1;i <= 2000;i++)dis[i] = INF;
	inq[st] = 1,dis[st] = 0,incf[st] = INF;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		cout<<"vis "<<u<<" "<<dis[u]<<" from "<<e[pre[u]^1].to<<endl;
		inq[u] = 0;
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			if(e[i].cap <= 0)continue;
			const int v = e[i].to;
			if(dis[u] + e[i].cost < dis[v]){
				dis[v] = dis[u] + e[i].cost;
				pre[v] = i;
				incf[v] = min(incf[u],e[i].cap);
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return (pre[ed] != 0);
}
void Dinic(int st,int ed){
	while(SPFA(st,ed)){
		int pos = ed;
		maxflow += incf[ed];
		mincost += incf[ed] * dis[ed]; 
		while(pos != st){
			e[pre[pos]].cap -= incf[ed];
			e[pre[pos]^1].cap += incf[ed];
			pos = e[pre[pos]^1].to;
		}
	}
	return ;
}
string strs[20];
int calc(int x,int y){
	const int lenx = strs[x].length();
	const int leny = strs[y].length();
	const int len = min(lenx,leny);
	for(int i = len;i >= 1;i--){
		bool com = 1;
		for(int s = 0;s <= i-1;s++){
			if(strs[x][lenx-1-s] != strs[y][i-s-1]){
				com = 0;
				break;
			}
		}
		if(com)return i;
	}
	return 0;
}
int main(){
	freopen("substr.in","r",stdin);
	//freopen("substr.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>strs[i];
		awa(s,i,1,strs[i].length());
		awa(i,i+n,1,-strs[i].length());
		awa(i,t,INF,0);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			int tog = calc(i,j);
			awa(i+n,j,INF,strs[i].length()-tog);
		}
	}
	Dinic(s,t);
	cout<<maxflow<<" "<<mincost;
	return 0;
}
