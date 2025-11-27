#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 22;
bool e[MAXN][MAXN],OK = true;
int n,d[MAXN],tot,now,ans[MAXN * MAXN];
int st,cnt;
void dfs(int u,int step){
	if(step == tot+2){
		for(int i = 1;i <= tot;i++){
			cout<<ans[i]<<"->";
		}
		cout<<ans[tot+1]<<endl;
		exit(0);
	}
	for(int v = 1;v <= n;v++){
		if(e[u][v]){
			e[u][v] = e[v][u] = false;
			ans[step] = v;
			dfs(v,step+1);
			e[u][v] = e[v][u] = true;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>e[i][j];
			if(e[i][j]){
				tot++;
				d[j]++;
			}
		}
	}
	tot /= 2;
	st = 1;
	for(int i = n;i >= 1;i--){ 
		if(d[i] & 1){
			st = i;
			cnt++;
		}
	}
	if(cnt != 0 && cnt != 2){
		cout<<"No Solution!"<<endl;
	}else{
		ans[1] = st;
		dfs(st,2);
	}
	return not(Akano loves pure__Elysia);
}
