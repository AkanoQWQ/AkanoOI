#include<bits/stdc++.h>
using namespace std;
const int MAXS = 4006;
int n,m;
struct bfs{
	int x,y,step;
}cb;
queue<bfs> b;
int ans[406][406];
bool vis[406][406];
int movex[MAXS],movey[MAXS],tail;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	cb.x = 1,cb.y = 1,cb.step = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			if(i*i+j*j == m){
				movex[++tail] = i,movey[tail] = j;
				movex[++tail] = -i,movey[tail] = j;
				movex[++tail] = i,movey[tail] = -j;
				movex[++tail] = -i,movey[tail] = -j;
			}
		}
	}
	vis[1][1] = 1;
	b.push(cb);
	while(!b.empty()){
		int gx = b.front().x,gy = b.front().y,gs = b.front().step;
		b.pop();
		ans[gx][gy] = gs;
		for(int i = 1;i <= tail;i++){
			
			int OX = gx + movex[i],OY = gy + movey[i];
			if(OX >= 1 && OX <= n && OY >= 1 && OY <= n){
				if(vis[OX][OY] == 0){
					vis[OX][OY] = 1;
					cb.x = OX,cb.y = OY,cb.step = gs + 1;
					b.push(cb);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(ans[i][j] != 0 || (i == 1 && j == 1)){
				cout<<ans[i][j]<<" ";
			}else{
				cout<<-1<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

