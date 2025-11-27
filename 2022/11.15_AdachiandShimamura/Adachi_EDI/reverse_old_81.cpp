#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#pragma GCC optimize(2)
FILE_ST
const int MAXN = 100006;
int n,k,m,s,ans[MAXN],d[MAXN],xx[MAXN];
bool est[MAXN];
queue<int> q;
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
EXCUTE_ST
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	n = read();
	k = read();
	m = read();
	s = read();
	for(int i = 1;i <= m;i++){
		int x;
		x = read();
		est[x] = 1;
	}
	for(int i = 1;i <= n;i++){
		ans[i] = -1;
	}
	for(int c = 1;c <= k;c++){
		d[c] = abs(c - (k-c+1));
	}
	ans[s] = 0;
	q.push(s);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = 1;i <= k/2;i++){
			for(int f = -1;f <= 1;f += 2){
				const int v = u + d[i] * f;
				int c = i;
				if(f == -1){
					c = k - i + 1;
				}
				if((u-c+1 <= 0 || u-c+k >= n+1)){
					continue;
				}
				if(v < 1 || v > n)continue;
				if(ans[v] != -1 || est[v])continue;
				ans[v] = ans[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d ",ans[i]);
	}
FILE_ED_And_excute
