#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018 + 1108;
const int INF = 1e9 + 2006 + 1018 + 1108;
int n,m,a[MAXN][MAXN],f[MAXN][MAXN],mn = INF,mx,ans = INF;
int lowerMx[MAXN][MAXN],upperMx[MAXN][MAXN];
int lowerMn[MAXN][MAXN],upperMn[MAXN][MAXN];
int g[MAXN][MAXN];//前缀和 
pair<int,int> mnPos,mxPos;
/*
契约:
右方为 JOI,左方为 IOI,f_i_j 表示 第 i 行 IOI 的"长度"为 j 的最小答案
长度单调不降 
或者看作第 i 列的高度也行,但是就倒过来了,下面会用这个角度分析("上下")(直观) 
先默认 mx 在 JOI 方,mn 在 IOI 方,后反过来 
*/ 
inline void Solve(){
	for(int i = 1;i <= n;i++){
		lowerMn[i][0] = INF;
		for(int j = 1;j <= m;j++){
			lowerMn[i][j] = min(lowerMn[i][j-1],a[i][j]);
			lowerMx[i][j] = max(lowerMx[i][j-1],a[i][j]);
		}
		upperMn[i][m+1] = INF;
		for(int j = m;j >= 1;j--){//边界? 
			upperMn[i][j] = min(upperMn[i][j+1],a[i][j]);
			upperMx[i][j] = max(upperMx[i][j+1],a[i][j]);
		}
	}
	//mx在上,mn在下 
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			f[i][j] = max(mx - upperMn[i][j+1],lowerMx[i][j] - mn);//f_i_j 应该大于0
			f[i][j] = max(f[i][j],g[i-1][j]);
			g[i][j] = f[i][j];
			if(j > 0)g[i][j] = min(g[i][j],g[i][j-1]);
		}
		if(i == mxPos.first){
			for(int j = mxPos.second;j <= m;j++){
				f[i][j] = INF;
			}
		}
		if(i == mnPos.first){
			for(int j = 0;j < mnPos.second;j++){
				f[i][j] = INF;
			}
		}
	}
	for(int i = 0;i <= m;i++){
		ans = min(ans,f[n][i]);
	}
	//mn在上,mx在下 
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			f[i][j] = max(upperMx[i][j+1] - mn,mx - lowerMn[i][j]);//f_i_j 应该大于0
			f[i][j] = max(f[i][j],g[i-1][j]);
			g[i][j] = f[i][j];
			if(j > 0)g[i][j] = min(g[i][j],g[i][j-1]);
		}
		if(i == mnPos.first){
			for(int j = mnPos.second;j <= m;j++){
				f[i][j] = INF;
			}
		}
		if(i == mxPos.first){
			for(int j = 0;j < mxPos.second;j++){
				f[i][j] = INF;
			}
		}
	}
	for(int i = 0;i <= m;i++){
		ans = min(ans,f[n][i]);
	}
	return ;
}
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j] < mn){
				mn = a[i][j];
				mnPos = make_pair(i,j);
			}
			if(a[i][j] > mx){
				mx = a[i][j];
				mxPos = make_pair(i,j);
			}
		}
	}
	return ;
}
inline void SwapMap(){//把地图反过来 
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m-j+1;j++){
			swap(a[i][j],a[i][m-j+1]);
		}
	}
	mnPos.second = m - mnPos.second + 1;
	mxPos.second = m - mxPos.second + 1;//坐标也要反过来 
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	SwapMap();
	Solve();//反过来再跑一次 
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
/*
思考
Thinking 1
对于最小值 mn 和 mx,我们绝不会使得他们在同一个省内
这样肯定是最坏的情况
把它们分开,不考虑有多个 mn,mx 的情况下,显然更优 
我们钦定 mn 在 JOI 中,mx 在 IOI 中,显然只需要考虑 JOI的最大值 和 IOI的最小值 

Thinking 2
暴力是 n^3 的,前缀和优化? 

算法可能的缺陷
当最小值最大值多次出现的时候,选取的点可能不是最优的 
*/
