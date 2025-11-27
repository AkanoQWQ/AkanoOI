#include<bits/stdc++.h>
using namespace std;
const int MAXN = 77;
const int INF = 1047483647;
int n,m,k,q,maxrel;
int dis[MAXN][MAXN][MAXN];//a_b_c:a to b,relax c times
int main(){
	freopen("Auto.in","r",stdin);
	freopen("Auto.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0;i <= n+1;i++){
		for(int j = 0;j <= n+1;j++){
			for(int k = 0;k <= n+1;k++){
				dis[i][j][k] = INF;
			}
		}
		dis[i][i][1] = 0;
		dis[i][i][0] = 0;
	}
	for(int i = 1;i <= m;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		dis[a][b][1] = min(dis[a][b][1],t);
	}
	scanf("%d%d",&k,&q);
	maxrel = min(k,n+1);
	for(int s = 1;s <= maxrel;s++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int k = 1;k <= n;k++){
					if(i == k || k == j)continue;
					if(dis[i][k][s] + dis[k][j][1] < dis[i][j][s+1]){
						dis[i][j][s+1] = dis[i][k][s] + dis[k][j][1];
					}
				}
			}
		}
	}
	while(q--){
		int c,d,ans = INF;
		scanf("%d%d",&c,&d);
		for(int i = 1;i <= maxrel;i++){
			ans = min(ans,dis[c][d][i]);
		}
		if(ans != INF){
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
