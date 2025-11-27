#include<bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
const int MN = 12589;
const int ME = 16411;
int head[MN],dis[MN],vis[MN],T,C,Ts,Te,cN,cV,cDis,cnt,i;
struct Edge{
	int next,v,dis;
}edge[ME];
void AddEdge(int n,int v,int dis){
	cnt++;
	edge[cnt].next = head[n];
	head[n] = cnt;
	edge[cnt].v = v;
	edge[cnt].dis = dis;
}
void DIJ(int BE){
	for(int i = 0;i <= T;i++){
		dis[i] = INF;
	}
	dis[BE] = 0;
	for(int i = 0;i <= T;i++){
		int TPoint = 0,TValue = INF;
		for(int j = 0;j <= T;j++){
			if(vis[j] == 0 && dis[j] < TValue){
				TValue = dis[j],TPoint = j;
			}
		}
		for(int j = head[TPoint];j != 0;j = edge[j].next){
			int OBJ = edge[j].v;
			if(dis[TPoint] + edge[j].dis < dis[OBJ]){
				dis[OBJ] = dis[TPoint] + edge[j].dis;
			}
		}
		vis[TPoint] = 1;
	}
}
int main(){
	//freopen("P1554.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T>>C>>Ts>>Te;
	for(i = 1;i <= C;i++){
		cin>>cN>>cV>>cDis;
		AddEdge(cN,cV,cDis);
		AddEdge(cV,cN,cDis);
	}
	DIJ(Ts);
	cout<<dis[Te]; 
	return 0;
}

