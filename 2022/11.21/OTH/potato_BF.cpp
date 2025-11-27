#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
int t,n,m;
vector<int> a[MAXN];
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
bool solve(int swpa,int swpb){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m;j++){
			int u = j;
			if(u == swpa){
				u = swpb;
			}else if(u == swpb){
				u = swpa;
			}
			int v = j+1;
			if(v == swpa){
				v = swpb;
			}else if(v == swpb){
				v = swpa;
			}
			if(a[i][u] > a[i][v])return 0;
		}
	}
	return 1;
}
int main(){
	freopen("potato.in","r",stdin);
	freopen("potato.ans","w",stdout);
	t = read();
	while(t--){
		n = read(),m = read();
		for(int i = 1;i <= n;i++){
			a[i].clear();
			a[i].push_back(114514);
			for(int j = 1;j <= m;j++){
				int inx = read();
				a[i].push_back(inx);
			}
		}
		bool fd = 0;
		if(solve(0,0)){
			puts("1 1");
			continue;
		}
		for(int i = 1;i <= m;i++){
			for(int j = i+1;j <= m;j++){
				if(solve(i,j)){
					printf("%d %d\n",i,j);
					fd = 1;
					break;
				}
			}
			if(fd)break;
		}
		if(fd == 0){
			puts("-1");
		}
	}
	return 0;
}
