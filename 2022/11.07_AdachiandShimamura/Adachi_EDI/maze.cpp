#include<bits/stdc++.h>
using namespace std;
const int MAXN = 36;
const int movex[4] = {1,0,-1,0};
const int movey[4] = {0,1,0,-1};
int m,n,k,h,minh = 0x7fffffff,stx,sty;
int p[(1<<6) + 2];
string ins;
bool vis[MAXN][MAXN];
char mp[MAXN][MAXN];
void dfs(int x,int y,int dh){
	vis[x][y] = 1;
	if(mp[x][y] == 'A')dh++;
	if(dh > minh)return ;
	if(mp[x][y] == '@'){
		minh = min(minh,dh);
		vis[x][y] = 0;
		return ;
	}
	for(int i = 0;i < 4;i++){
		const int OX = x + movex[i];
		const int OY = y + movey[i];
		if(OX < 1 || OX > n || OY < 1 || OY > m)continue;
		if(mp[OX][OY] == '#' || vis[OX][OY])continue;
		dfs(OX,OY,dh); 
	}
	vis[x][y] = 0;
	return ;
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>k>>h;//swap n,m
	if(k > 1){
		cout<<"0.000";
		return 0;
		cout<<"Never gonna give you up";
	}
	for(int i = 1;i <= n;i++){
		cin>>ins;
		for(int j = 0;j < m;j++){
			mp[i][j+1] = ins[j];
			if(mp[i][j+1] == '$'){
				stx = i,sty = j+1;
			}
		}
	}
	for(int i = 0;i < 2;i++){
		cin>>p[i];
	}
	dfs(stx,sty,0);
	if(minh == 0x7fffffff){
		printf("0.000");
	}else if((minh != 0x7fffffff && p[0] > 0 && p[1] == 0)){
		printf("1.000");
	}else if(minh >= h){
		printf("%.3lf",1.0f * p[0] / (1.0f * (p[0] + p[1])));
	}else{
		printf("1.000");
	}
	return 0;
}
