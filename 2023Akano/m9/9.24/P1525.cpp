#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e4 + 1018 + 1108;
const int MAXM = 1e5 + 1018 + 1108;
struct Edge{
	int u,v,w;
}e[MAXM];
bool Cmp(Edge e1,Edge e2){
	return e1.w > e2.w;
}
int n,m,bel[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,Cmp);
	for(int i = 1;i <= m;i++){
		const int u = e[i].u,v = e[i].v;
		if(bel[u] == 0 && bel[v] == 0){
			bel[u] = 
		}
	}
	return not(Akano loves pure__Elysia);
}
