#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 6;
int fa[MAXN]; 
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	while(m--){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt == 1){
			fa[find(x)] = find(y);
		}else{
			if(find(x) == find(y)){
				puts("Y");
			}else{
				puts("N");
			}
		}
	}
	return 0;
}
