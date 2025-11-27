#include<bits/stdc++.h>
using namespace std;
const int MAXSTRS = 15;
const int MAXN = 10006;//remember to edit
const int MAXM = 20006;
const int st = 0;
const int ed = 10000;
const int preed = 9999;
const int INF = 0x7fffffff;
struct Edge{
	int to,v,nxt,cost;
}e[MAXM];
int head[MAXN],ent = 1;
void AddEdge(int from,int to,int v,int cost){
	e[++ent].to = to;
	e[ent].v = v;
	e[ent].cost = cost;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
void awa(int from,int to,int v,int cost){
	AddEdge(from,to,v,cost);
	AddEdge(to,from,0,-cost);
	return ;
}
int n;
string strs[MAXSTRS];
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
int maxflow = 0,mincost = 0;
int incf[MAXN],pre[MAXN],dis[MAXN];
bool inq[MAXN];
queue<int> q;
bool SPFA(){
	while(!q.empty())q.pop();
	memset(incf,0,sizeof(incf));
	memset(pre,0,sizeof(pre));
	memset(inq,0,sizeof(inq));
	for(int i = 0;i < MAXN;i++){
		dis[i] = INF;
	}
	incf[st] = INF;
	dis[st] = 0;
	inq[st] = 1;
	q.push(st);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		//cout<<"vis "<<u<<" "<<dis[u]<<" from "<<e[pre[u]^1].to<<endl;
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(e[i].v <= 0)continue;
			if(dis[v] > dis[u] + e[i].cost){
				pre[v] = i;
				incf[v] = min(incf[u],e[i].v);
				dis[v] = dis[u] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return (pre[ed] != 0);
}
void Dinic(){
	maxflow = 0,mincost = 0;
	while(SPFA()){
		mincost += incf[ed] * dis[ed];
		maxflow += incf[ed];
		int pos = ed;
		while(pos != st){
			e[pre[pos]].v -= incf[ed];
			e[pre[pos]^1].v += incf[ed];
			pos = e[pre[pos]^1].to;
		}
	}
	return ;
}
int a[22],minc = 0x7fffffff;
int cnte[MAXN],tail,nxt[22],ne[22];
int tr[22],trt = 0;
bool vis[22];
void solve(bool phuan){
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		bool tg = 0;
		if(phuan == 0){
			for(int j = 1;j <= n;j++){
				if(nxt[j] == i)tg = 1;
			}
		}
		if(tg)continue;
		int pos = i;
		trt = 0;
		bool huan = 0;
		minc = 0x7fffffff;
		int dpos = 0;
		while(pos != 0){
			if(vis[pos]){
				huan = 1;
				break;
			}
			vis[pos] = 1;
			tr[++trt] = pos;
			if(ne[pos] < minc){
				minc = ne[pos];
				dpos = trt;
			}
			pos = nxt[pos];
		}
		if(huan){
			pos = dpos + 1;
			if(pos >= trt + 1){
				pos = 1;
			}
			while(1){
				const int m = tr[pos];
				const int ouput_len = strs[m].length() - ne[m];
				for(int i = 0;i < ouput_len;i++){
					cout<<strs[m][i];
				}
				pos++;
				if(pos >= trt + 1){
					pos = 1;
				}
				if(pos == dpos + 1){
					break;
				}
			}
		}else{
			for(int k = 1;k <= trt;k++){
				const int m = tr[k];
				const int ouput_len = strs[m].length() - ne[m];
				for(int i = 0;i < ouput_len;i++){
					cout<<strs[m][i];
				}
			}
		}
	}
	return ;
}
int bb[16][16];
namespace BF{
	int s[15],c[15];
	void solveBF(){
		int aans = 0x7fffffff,slen = 0;
		for(int i = 1;i <= n;i++){
			s[i] = i;
			slen += strs[i].length();
		}
		do{
			int ret = 0;
			for(int i = 1;i < n;i++){
				ret += bb[s[i]][s[i+1]];
			}
			if(slen - ret < aans){
				for(int j = 1;j <= n;j++){
					c[j] = s[j];
				}
				aans = slen - ret;
			}else if(slen - ret == aans){
				if(strs[c[1]] > strs[s[1]]){
					for(int j = 1;j <= n;j++){
						c[j] = s[j];
					}
				}
			}
		}while(next_permutation(s+1,s+n+1));
		for(int i = 1;i < n;i++){
			const int llen = strs[c[i]].length() - bb[c[i]][c[i+1]];
			for(int j = 0;j < llen;j++){
				cout<<strs[c[i]][j];
			}
		}
		cout<<strs[c[n]];
		return ;
	}
}
int main(){ 
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>strs[i];
		awa(st,i,1,0);
		awa(i,ed,1,strs[i].length());
		awa(i+n,ed,1,0);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			int tog = calc(i,j);
			bb[i][j] = tog;
			cnte[++tail] = ent + 1;
			awa(i,j+n,1,strs[i].length()-tog);
		}
	}
	Dinic();
	for(int i = 1;i <= tail;i++){
		if(e[cnte[i]].v == 0){//该后继被用 
			const int u = e[cnte[i]^1].to;
			nxt[u] = e[cnte[i]].to-n;
			ne[u] = int(strs[u].length())-e[cnte[i]].cost;
		}
	}
	if(n <= 10){
		BF::solveBF();
		return 0;
	}
	solve(0);
	solve(1);
	return 0;
}
