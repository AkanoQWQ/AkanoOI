#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,t;
namespace Subtask1{
	const int MAXN = 1018;
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,1,0,-1};
	bool kol[MAXN * 2][MAXN * 2],vis[MAXN * 2][MAXN * 2];
	int blk,wht;
	void dfs(int x,int y){
		vis[x][y] = true;
		for(int k = 0;k < 4;k++){
			const int OX = x + dx[k],OY = y + dy[k];
			if(kol[x][y]){
				if(1 <= OX && OX < 2*n && 1 <= OY && OY < 2*n && kol[OX][OY] == kol[x][y] && !vis[OX][OY]){
					dfs(OX,OY);
				}
			}else{
				if(0 <= OX && OX <= 2*n && 0 <= OY && OY <= 2*n && kol[OX][OY] == kol[x][y] && !vis[OX][OY]){
					dfs(OX,OY);
				}
			}
		}
		return ;
	}
	inline void Solve(){
		for(int i = 1;i <= n;i++){
			int _x1,_y1,_x2,_y2;
			cin>>_x1>>_y1>>_x2>>_y2;
			for(int i = _x1;i < _x2;i++){
				for(int j = _y1;j < _y2;j++){
					kol[i][j] = !kol[i][j];
				}
			}
		}
		for(int i = 1;i < 2*n;i++){
			for(int j = 1;j < 2*n;j++){
				if(!vis[i][j]){
					if(kol[i][j]){
						blk++;
					}else{
						wht++;
					}
					dfs(i,j);
				}
			}
		}
		if(t == 1){
			cout<<blk+wht<<endl;
		}else{
			cout<<wht<<" "<<blk<<endl;
		}
		return ;
	}
}
namespace Subtask2{
	inline void Solve(){
		if(t == 1){
			cout<<n+1<<endl;
		}else{
			cout<<1<<" "<<n<<endl;
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("rectangles.in","r",stdin);
	freopen("rectangles.out","w",stdout);
	cin>>n>>t;
	if(n <= 1018){
		Subtask1::Solve();
	}else{
		Subtask2::Solve();
	}
	return not(Akano loves pure__Elysia);
}
