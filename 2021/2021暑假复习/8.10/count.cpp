#include<bits/stdc++.h>
using namespace std;
struct ball{
	int c,s;
}bs[1261108];
int i,j,n,tail,maxs,minc = 9999999;
char m[1006][1006];
void creat_ball(int x,int y,int num){
	if(m[x][y] == '#'){
		bs[num].s++;
		m[x][y] = '!';
		creat_ball(x+1,y,num);
		creat_ball(x-1,y,num);
		creat_ball(x,y+1,num);
		creat_ball(x,y-1,num);
	}else if(m[x][y] == '.'){
		bs[num].c++;
	} 
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			cin>>m[i][j];
		}
	}
	for(i = 0;i <= n;i++){
		m[i][0] = '.';
		m[0][i] = '.';
		m[n+1][i] = '.';
		m[i][n+1] = '.';
	}
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			if(m[i][j] == '#'){
				creat_ball(i,j,tail);
				tail++; 
			} 
		}
	}
	for(i = 0;i < tail;i++){
		if(bs[i].s > maxs){
			maxs = bs[i].s;
			minc = bs[i].c;
		}else if(bs[i].s == maxs){
			minc = min(minc,bs[i].c);
		}
	}
	cout<<maxs<<" "<<minc;
	return 0;
}

