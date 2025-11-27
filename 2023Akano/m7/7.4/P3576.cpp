#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
#define int long long
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 1e6 + 6;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],ine[MAXN],cnt;
inline void AddEdge(int from,int to){
	ine[from]++;
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,g,k,L[MAXN],R[MAXN],ant[MAXN],root1,root2,ans;
void dfs(int u,int fa){
	const int div = ine[u] - 1;
	if(div == 0){
		int ST = lower_bound(ant+1,ant+g+1,L[u]) - ant;
		int ED = upper_bound(ant+1,ant+g+1,R[u]) - ant - 1;
		int DELTA = ED - ST + 1;
		ans += DELTA;
		return ;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		L[v] = L[u] * div,R[v] = R[u] * div + div - 1;
		dfs(v,u);
	}
	return ;
}
signed main(){
	n = Read(),g = Read(),k = Read();
	for(int i = 1;i <= g;i++){
		ant[i] = Read();
	}
	sort(ant+1,ant+g+1);
	root1 = Read(),root2 = Read();
	ine[root1]++,ine[root2]++;
	for(int i = 2;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u); 
	}
	L[root1] = R[root1] = L[root2] = R[root2] = k;
	dfs(root1,root1),dfs(root2,root2);
	Write(ans*k);
	return 0;
}


