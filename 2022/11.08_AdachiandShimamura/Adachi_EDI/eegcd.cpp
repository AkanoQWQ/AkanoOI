#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 6;
const int MAXM = 2e5 + 6;
const int SINF = 0x7fffffff / 8;
const int MAX_VIS = 50;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,q;
struct Edge{
	int nxt,to,a,b;
}e[MAXM];
int head[MAXN],tot = 1;
void AddEdge(int from,int to,int a,int b){
	e[++tot].to = to;
	e[tot].a = a;
	e[tot].b = b;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int qa,qb,obj;
int vis[MAXN];
bool OK = 0;
void dfs(int u,int suma,int sumb,int mina,int minb){
	if(OK)return ;
	if(suma > qa * mina)return ;
	if(sumb > qb * minb)return ;
	if(u == obj){
		if(qa * mina == suma && qb * minb == sumb){
			OK = 1;
			return ;
		}
	}
	vis[u]++;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v] <= MAX_VIS){
			const int newa = min(mina,e[i].a);
			const int newb = min(minb,e[i].b);
			for(int j = 1;j <= 9999;j += 2){
				const int nsa = suma + j * e[i].a;
				const int nsb = sumb + j * e[i].b;
				if(1.0f * nsa / newa > qa)break ;
				if(1.0f * nsb / newb > qb)break ;
				dfs(v,nsa,nsb,newa,newb);
			}
		}
	}
	vis[u]--;
	return ;
}
string query(int u,int v,int a,int b){
	qa = a,qb = b,obj = v,OK = 0;
	dfs(u,0,0,SINF,SINF);
	if(OK)return "Yes";
	return "No";
}
int main(){
	freopen("eegcd.in","r",stdin);
	freopen("eegcd.out","w",stdout);
	n = read(),m = read();
	while(m--){
		int u = read(),v = read(),a = read(),b = read();
		AddEdge(u,v,a,b);
		AddEdge(v,u,a,b);
	}
	q = read();
	while(q--){
		int u = read(),v = read(),a = read(),b = read();
		if(n > 1000){
			puts("No");
			continue;
		}
		puts(query(u,v,a,b).c_str());
	}
	return 0;
}
