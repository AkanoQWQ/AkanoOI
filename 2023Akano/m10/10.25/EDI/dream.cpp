#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1018 + 1108;
struct Node{
	int l,r,fa;
}node[MAXN],save[MAXN];
int n;
inline void LinkSonL(int u,int v){
	node[node[v].l].fa = 0;
	if(u == node[node[u].fa].l){
		node[node[u].fa].l = 0;
	}else if(u == node[node[u].fa].r){
		node[node[u].fa].r = 0;
	}
	node[u].fa = v;
	node[v].l = u;
	return ;
}
inline void LinkSonR(int u,int v){
	node[node[v].r].fa = 0;
	if(u == node[node[u].fa].l){
		node[node[u].fa].l = 0;
	}else if(u == node[node[u].fa].r){
		node[node[u].fa].r = 0;
	}
	node[u].fa = v;
	node[v].r = u;
	return ;
}
inline void Rotate(int x){
	const int orgfa = node[x].fa,par = node[orgfa].fa;
	if(x == node[orgfa].l){
		LinkSonL(node[x].r,orgfa);
		if(orgfa == node[par].l){
			LinkSonL(x,par);
		}else if(orgfa == node[par].r){
			LinkSonR(x,par);
		}
		LinkSonR(orgfa,x);
	}else if(x == node[orgfa].r){
		LinkSonR(node[x].l,orgfa);
		if(orgfa == node[par].l){
			LinkSonL(x,par);
		}else if(orgfa == node[par].r){
			LinkSonR(x,par);
		}
		LinkSonL(orgfa,x);
	}
	return ;
}
inline void Zig(int x){
	Rotate(x);
	return ;
}
inline void Zigzig(int x){
	int p = node[x].fa;
	Rotate(p),Rotate(x);
	return ;
}
inline void Zigzag(int x){
	Rotate(x),Rotate(x);
	return ;
}
ll dep[MAXN];
void dfs(int u,int nowdep){
	if(!u)return ;
	dep[u] += nowdep;
	dfs(node[u].l,nowdep+1),dfs(node[u].r,nowdep+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>node[i].l>>node[i].r;
		if(node[i].l)node[node[i].l].fa = i;
		if(node[i].r)node[node[i].r].fa = i;
	}
	memcpy(save,node,sizeof(save));
	for(int choice = 1;choice <= n;choice++){
		for(int i = 1;i <= n;i++)node[i] = save[i];
		while(node[choice].fa != 0){
			if(node[node[choice].fa].fa == 0){
				Zig(choice);
			}else{
				const int nowfa = node[choice].fa;
				bool xISL = (choice == node[nowfa].l);
				bool faISL = (nowfa == node[node[nowfa].fa].l);
				if(xISL != faISL){
					Zigzig(choice);
				}else{
					Zigzag(choice);
				}
			}
		}
		dfs(choice,0);
	}
	for(int i = 1;i <= n;i++){
		cout<<dep[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
