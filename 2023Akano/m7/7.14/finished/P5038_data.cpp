#include<bits/stdc++.h>
#include "comp.h"
using namespace std;
using ll = long long;
const int MAXN = 6666;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int t = 1,n = 6,m = 7;
ll OBJ = 0,DOBJ = 0,val[MAXN][MAXN];
mt19937 rng(GetTime());
inline bool Judge(int x,int y){
	return (x >= 1 && x <= n) && (y >= 1 && y <= m);
}
int main(){
	freopen("P5038.in","w",stdout);cin.clear(),cout.clear();
	n = rd(5,6,rng);
	m = rd(5,6,rng);
	OBJ = rd(1e9,1e9,rng);
	DOBJ = rd(1,1e8,rng);
	cout<<t<<endl;//t == 1
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)val[i][j] = OBJ;
	}
	for(int D = 1;D <= DOBJ;D++){
		int x = rd(1,n,rng),y = rd(1,m,rng);
		int k = rd(0,3,rng);
		int ox = x + dx[k],oy = y + dy[k];
		while((x == 1 && y == 1) || (ox == 1 && oy == 1) ||(x == ox && y == oy) || (val[x][y] <= 0 || val[ox][oy] <= 0) || (!Judge(x,y) || !Judge(ox,oy))){
			x = rd(1,n,rng),y = rd(1,m,rng);
			k = rd(0,3,rng);
			ox = x + dx[k],oy = y + dy[k];
		}
		val[x][y]--,val[ox][oy]--;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<val[i][j]<<" ";
		}
		cout<<endl;
	}
	freopen("P5038.ans","w",stdout);cin.clear(),cout.clear();
	cout<<DOBJ<<flush;
	freopen("P5038.chk","w",stdout);cin.clear(),cout.clear();
	cout<<OBJ<<" "<<DOBJ<<flush;
	return 0;
}
