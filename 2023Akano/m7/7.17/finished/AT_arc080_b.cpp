#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int n,m,k,dir,nowx = 1,nowy = 1,otp[MAXN][MAXN],left_kol;
inline void Fill(int& x,int& y,int kolor){
	int OX = x + dx[dir],OY = y + dy[dir];
	if(otp[OX][OY] != 0){
		dir = (dir + 1) % 4;
		OX = x + dx[dir],OY = y + dy[dir];
	}
	otp[x][y] = kolor;
	x = OX,y = OY;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>k;
	for(int i = 0;i <= max(n,m)+1;i++){
		otp[0][i] = otp[n+1][i] = otp[i][0] = otp[i][m+1] = -1;
	}
	for(int kol = 1;kol <= k;kol++){
		cin>>left_kol;
		while(left_kol--)Fill(nowx,nowy,kol);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<otp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

