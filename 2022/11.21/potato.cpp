#include<bits/stdc++.h>
using namespace std;
const int OK = 30;
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
vector<int> edi;
bool ine[MAXN];
void INIT(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m;j++){
			if(a[i][j] > a[i][j+1]){
				if(ine[j] == 0){
					ine[j] = 1;
					edi.push_back(j);
				}
				if(ine[j+1] == 0){
					ine[j+1] = 1;
					edi.push_back(j+1);
				}
				if(edi.size() > OK)return ;
			}
		}
	}
	return ;
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
//	freopen("potato.in","r",stdin);
//	freopen("potato.out","w",stdout);
	t = read();
	while(t--){
		edi.clear();
		for(int i = 0;i <= m+2;i++)ine[i] = 0;
		n = read(),m = read();
		for(int i = 1;i <= n;i++){
			a[i].clear();
			a[i].push_back(114514);
			for(int j = 1;j <= m;j++){
				int inx = read();
				a[i].push_back(inx);
			}
		}
		INIT();
		if(edi.size() > OK){
			puts("-1");
			continue;
		}
		if(edi.size() == 0){
			puts("1 1");
			continue;
		}
		bool fd = 0;
		for(int i = 0;i < edi.size();i++){
			for(int j = i+1;j < edi.size();j++){
				if(solve(edi[i],edi[j])){
					printf("%d %d\n",edi[i],edi[j]);
					fd = 1;
					break;
				}
			}
			if(fd == 1)break;
		}
		if(fd == 0){
			puts("-1");
		}
	}
	return 0;
}
