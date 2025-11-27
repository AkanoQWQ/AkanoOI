#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 63;
const int INF = 2006 + 1018 + 1108;
string mp[MAXN];
int n;
int pre[MAXN][MAXN];
inline int QueryPre(int upper,int l,int lower,int r){
	return pre[lower][r] - pre[upper-1][l] - pre[upper][l-1] + pre[upper-1][l-1];
}
int f[MAXN][MAXN][MAXN][MAXN];
inline void Update(int& x,int val){
	x = min(x,val);
	return ;
}
inline void Trans(int upper,int l,int lower,int r){//返回是否泉空
	if(f[upper][l][lower][r] == 0){
		return ;
	}
	//左右切割
	for(int k = l;k < r;k++){//左半部分包括到k 
		Update(f[upper][l][lower][r],f[upper][l][lower][k] + f[upper][k+1][lower][r]);
		if(f[upper][k+1][lower][r] == 0)break;
	}
	//上下切割
	for(int k = upper;k < lower;k++){//上半部分包括到k
		Update(f[upper][l][lower][r],f[upper][l][k][r] + f[k+1][l][lower][r]);
		if(f[k+1][l][lower][r] == 0)break;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("detection.in","r",stdin);
	freopen("detection.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>mp[i];
		mp[i] = "." + mp[i];
		for(int j = 1;j <= n;j++){
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (mp[i][j] == 'T');
		}
	}
	for(int i = 0;i <= n+1;i++){
		for(int j = 0;j <= n+1;j++){
			for(int i2 = 0;i2 <= n+1;i2++){
				for(int j2 = 0;j2 <= n+1;j2++){
					f[i][j][i2][j2] = INF;
					if(i2 >= i && j2 >= j){
						f[i][j][i2][j2] = max(i2-i+1,j2-j+1);
						if(QueryPre(i,j,i2,j2) == 0)f[i][j][i2][j2] = 0;
					}
				}
			}
		}
	}
	for(int xLen = 1;xLen <= n;xLen++){
		for(int yLen = 1;yLen <= n;yLen++){
			for(int x = n - xLen + 1;x >= 1;x--){
				for(int y = n - yLen + 1;y >= 1;y--){
					Trans(x,y,x + xLen - 1,y + yLen - 1);
				}
			}
		}
	}
	cout<<f[1][1][n][n]<<endl;
	return not(Akano loves pure__Elysia);
}
