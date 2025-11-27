#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,ans,r,c,f[106][106],h[106][106],xx,yy,cache,nx,ny,tmp,t;
int dx[6] = {0,1,0,-1,0};
int dy[6] = {0,0,1,0,-1};
int search(int x,int y){
	int i,t,tmp,nx,ny;
	if(f[x][y] > 0){
		return f[x][y];
	}
	
	t = 1;
	
	for(i = 1;i <= 4;i++){
		nx = x + dx[i];
		ny = y + dy[i];
		if((nx > 0) && (nx <= r) && (ny > 0) && (ny <= c) &&(h[nx][ny] > h[x][y])){
			tmp = search(nx,ny) + 1;
			if(tmp > t){
			t = tmp;
			}
		}
	}
	f[x][y] = t;
	return t;
}
int main(){
	freopen("ski.in","r",stdin);
	//freopen("ski.out","w",stdout);
	cin>>r>>c;
	for(i = 1;i <= r;i++){
		for(j = 1;j <= c;j++){
			cin>>h[i][j];
		}
	}
	for(xx = 1;xx <= r;xx++){
		for(yy = 1;yy <= c;yy++){
			cache = search(i,j);
			if(cache > ans){
				ans = cache;
			}
		}
	}
	cout<<ans;
	return 0;
}
