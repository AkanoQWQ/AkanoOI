#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n,dis[MAXN][MAXN],f[MAXN][(1<<MAXN)+3],maxstat;
inline int read(){
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
void write(int x){
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int main(){
//	freopen("P1171.in","r",stdin);
	n = read();
	maxstat = (1<<n) - 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			dis[i][j] = read();
		}
	}
	memset(f,0x7f,sizeof(f));
	f[0][0] = 0;
	for(int stat = 0;stat <= maxstat;stat++){
		for(int i = 0;i < n;i++){
			if(((1<<i) & stat == 0) && stat != i){
				continue;
			}
			for(int j = 0;j < n;j++){
				if(((1<<j) & stat) || (i == j))continue;
				f[j][(1<<j) | stat] = min(f[j][(1<<j) | stat],f[i][stat] + dis[i][j]);
			}
		}
	}
	write(f[0][maxstat]);
	return 0;
}
