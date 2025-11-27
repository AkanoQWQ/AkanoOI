#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1506;
int n,m,STX,STY;
bool mp[MAXN][MAXN];
int vis[MAXN][MAXN];
const int movex[4] = {0,1,0,-1};//rig dow lef upp
const int movey[4] = {1,0,-1,0};
const int crossx[4] = {-1,0,-1,1};//-1²»±ä 0:1   1:n/m 
const int crossy[4] = {0,-1,1,-1};
bool OK = 0;
int cnt;
pair<int,int> p[MAXN];
map<pair<int,int>,int> lsh;
void add(int x,int y){
	lsh[make_pair(x,y)] = ++cnt;
	p[cnt] = make_pair(x,y);
	return ;
}
void dfs(int x,int y,int Lp,int Rp){
	if(OK)return ;
	if(lsh[make_pair(Lp,Rp)] == 0){
		add(Lp,Rp);
	}
	if(vis[x][y] != 0){
		if(vis[x][y] == lsh[make_pair(Lp,Rp)]){
			return ;
		}else{
			OK = 1;
			return ;
		}
	}
	vis[x][y] = lsh[make_pair(Lp,Rp)];
	for(int i = 0;i < 4;i++){
		int OX = x + movex[i];
		int OY = y + movey[i];
		if(OX == 0 || OY == 0 || OX == n+1 || OY == m+1){
			if(crossx[i] == 0){
				OX = 1;
			}else if(crossx[i] == 1){
				OX = n;
			}
			if(crossy[i] == 0){
				OY = 1;
			}else if(crossy[i] == 1){
				OY = m;
			}
			if(mp[OX][OY] == 1)continue;
			dfs(OX,OY,Lp+movex[i],Rp+movey[i]);
		}else{
			if(mp[OX][OY] == 1)continue;
			dfs(OX,OY,Lp,Rp);
		}
	}
}
string s;
int main(){
	//freopen("P1363_1.in","r",stdin);
	while(cin>>n>>m){
		memset(vis,0,sizeof(vis));
		OK = 0;
		lsh.clear();
		cnt = 0;
		add(0,0);
		for(int i = 1;i <= n;i++){
			cin>>s;
			for(int j = 1;j <= m;j++){
				char c = s[j-1];
				mp[i][j] = (c == '#');
				if(c == 'S'){
					STX = i,STY = j;
				}
			}
		}
		dfs(STX,STY,0,0);
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
