#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
const int MAXM = 4e5 + 6;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(int x){
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Edge{
	int nxt,to,w,from;
}e[MAXM];
int head[MAXN],ent = 0;
void AddEdge(int from,int to,int val){
	e[++ent].to = to;
	e[ent].w = val;
	e[ent].from = from;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
bool cmp(Edge a,Edge b){
	return a.w < b.w;
}
int n,m;
int fa[MAXN],ans,hb;
int getfa(int x){
	if(fa[x] == x)return x;
	fa[x] = getfa(fa[x]);
	return fa[x];
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int u = read(),v = read(),w = read();
		AddEdge(u,v,w);
	}
	sort(e+1,e+ent+1,cmp);
	for(int i = 1;i <= ent;i++){
		const int l = getfa(e[i].from),r = getfa(e[i].to);
		if(l != r){
			hb++;
			fa[l] = r;
			ans += e[i].w;
			if(hb >= n-1)break;
		}
	}
	if(hb < n-1){
		puts("orz");
	}else{
		write(ans);
	}
	return 0;
}
