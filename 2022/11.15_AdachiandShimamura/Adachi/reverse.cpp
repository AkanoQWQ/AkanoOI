#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 100006;
int n,k,m,s,ans[MAXN],d[MAXN];
bool est[MAXN];
queue<pair<int,int> > q;
EXCUTE_ST
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&m,&s);
	for(int i = 1;i <= m;i++){
		int x;
		scanf("%d",&x);
		est[x] = 1;
	}
	for(int i = 1;i <= n;i++){
		ans[i] = -1;
	}
	for(int i = 1;i <= k;i++){
		d[i] = abs(i - (k-i+1));
	}
	ans[s] = 0;
	q.push(make_pair(s,0));
	while(!q.empty()){
		const int u = q.front().first;
		const int nowd = q.front().second;
		q.pop();
		for(int i = 1;i <= k/2;i++){
			const int v = u + d[i];
			if(v < 1 || v > n)continue;
			if(ans[v] != -1 || est[v])continue;
			ans[v] = nowd + 1;
			q.push(make_pair(v,ans[v]));
		}
		for(int i = 1;i <= k/2;i++){
			const int v = u - d[i];
			if(v < 1 || v > n)continue;
			if(ans[v] != -1 || est[v])continue;
			ans[v] = nowd + 1;
			q.push(make_pair(v,ans[v]));
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d ",ans[i]);
	}
FILE_ED_And_excute
