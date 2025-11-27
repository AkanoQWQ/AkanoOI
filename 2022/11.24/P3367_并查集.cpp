#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 6;
int fa[MAXN]; 
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
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
int n,m;
int main(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	while(m--){
		int opt = read(),x = read(),y = read();
		if(opt == 1){
			fa[find(x)] = y;
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
