#include<bits/stdc++.h>
using namespace std;
char table[10][10];
int i,j,_x,_y,a,b,c,d,cache,ans;
int se(int px,int py,int xx,int yy){
	if(table[xx+px][yy+py] == 'W'){
		return se(px,py,xx+px,yy+py)+1;
	}else if(table[xx+px][yy+py] == 'B'){
		return 0;
	}
	return -100000;
}
int main(){
	freopen("lango.in","r",stdin);
	freopen("lango.out","w",stdout);
	for(i = 1;i <= 8;i++){
		for(j = 1;j <= 8;j++){
			cin>>table[i][j];
		}
	}
	for(_x = 1;_x <= 8;_x++){
		for(_y = 1;_y <= 8;_y++){
			if(table[_x][_y] != '.'){
				//cout<<0<<" ";
				continue;
			}
			a = se(-1,0,_x,_y);
			b = se(1,0,_x,_y);
			c = se(0,1,_x,_y);
			d = se(0,-1,_x,_y);
			a = max(a,0);
			b = max(b,0);
			c = max(c,0);
			d = max(d,0);
			cache = a + b + c + d;
			//cout<<cache<<" ";
			ans = max(cache,ans);
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}

