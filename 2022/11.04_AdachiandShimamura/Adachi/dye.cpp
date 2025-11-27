#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
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
inline char readc(){
	char ch = getchar();
	while(ch != 'C' && ch != 'Q'){
		ch = getchar();
	}
	return ch;
}
struct Edge{
	int nxt,to;
}e[MAXN*4];
int head[MAXN],tot = 1;
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int n,q,koloro[MAXN],dep[MAXN],fa[MAXN];
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	fa[u] = father;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != father)dfs(e[i].to,u);
	}
	return ;
}
void write(int x){
    if(x > 9)write(x / 10);
    putchar(x % 10 + '0');
    return ;
}
void change(int x,int y,int c){
	koloro[x] = c,koloro[y] = c;
	while(x != y){
		if(dep[x] > dep[y]){
			x = fa[x];
			koloro[x] = c;
		}else{
			y = fa[y];
			koloro[y] = c;
		}
	}
	return ;
}
int query(int x,int y){
	int ret = 2;
	int kx = koloro[x],ky = koloro[y];
	while(x != y && fa[x] != y && fa[y] != x){
		if(dep[x] > dep[y]){
			x = fa[x];
			if(koloro[x] != kx){
				ret++;
				kx = koloro[x];
			}
		}else{
			y = fa[y];
			if(koloro[y] != ky){
				ret++;
				ky = koloro[y];
			}
		}
	}
	if(kx == ky)ret--;
	return ret;
}
int main(){
	freopen("dye.in","r",stdin);
	freopen("dye.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++){
		koloro[i] = read();
	}
	for(int i = 1;i < n;i++){
		int a = read(),b = read();
		AddEdge(a,b);
		AddEdge(b,a);
	}
	dfs(1,1);
	while(q--){
		char opt = readc();
		int x = read(),y = read(),c;
		if(opt == 'C'){
			c = read();
			change(x,y,c);
		}else{
			write(query(x,y)),putchar('\n');
		}
	}
	return 0;
}
//很裸的树剖,**但是咱不会染色线段树!!!** 
//线段树和树剖写炸了( XD 
