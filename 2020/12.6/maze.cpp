#include<bits/stdc++.h>
using namespace std;

const int xx[5] = {0,-1,0,1,0};
const int yy[5] = {0,0,1,0,-1};

int nmap[26][26],ans = 20061108,m,n,i,j;
int way[26][26];

void go(int step,int x,int y){
	int i,x1,y1;
	for(i = 1;i <= 4;i++){
		x1 = x + xx[i];
		y1 = y + yy[i];
		
		if(x1 >= 1 && x1 <= m && y1 >= 1 && y1 <= n && nmap[x1][y1] == 0 && way[x1][y1] == 0){
			way[x1][y1] = 1;
			if((x1 == m) && (y1 == n)){
				if(step < ans){
					ans = step;
				}
			}else{
				if(step + 1 < ans){
					go(step+1,x1,y1);
				}
			}
			way[x1][y1] = 0;
		}
	}
}

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>m>>n;
	for(i = 1;i <= m;i++){
		for(j = 1;j <= n;j++){
			cin>>nmap[i][j];
		}
	}
	way[1][1] = 1;
	go(2,1,1);
	cout<<ans;
	return 0;
}
