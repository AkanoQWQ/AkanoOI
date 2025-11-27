#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018;
const int MAXM = 2006 + 1018 + 1108;
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
int n,a1,b1,l1,a2,b2,l2;
int dis[MAXN];//1µÄ¸öÊý 
inline void ReadIn(){
	cin>>n>>a1>>b1>>l1>>a2>>b2>>l2;
	for(int i = 1;i <= n;i++){
		if(i - l1 + 1 >= 0){
			AddEdge(i,i-l1,b1-l1);
			AddEdge(i-l1,i,l1-a1);
		}
		if(i > 1){
			AddEdge(i,i-1,0);
			AddEdge(i-1,i,1);
		}
	}
	for(int i = 1;i <= n;i++){
		if(i - l2 >= 0){
			AddEdge(i,i-l2,-a2);
			AddEdge(i-l2,i,b2);
		}
	}
	AddEdge(0,1,1); 
	return ;
}
int way[MAXN];
bool inq[MAXN];
inline bool SPFA(){
	queue<int> q; 
	for(int i = 0;i <= n;i++){
		dis[i] = i;
		inq[i] = true;
		q.push(i);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				way[v] = way[u] + 1;
				if(way[v] > n)return false;
				if(!inq[v]){
					inq[v] = true;
					q.push(v);
				} 
			} 
		}
	}
	return true;
}
inline int Output(){
	return dis[n];
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	bool OK = SPFA();
	if(!OK){
		cout<<-1<<endl;
	}else{
		cout<<Output()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
