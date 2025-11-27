#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
//咱真的是......无语了
//矩阵快速幂模板题写了两个小时没写出来，一直WA，你猜为什么？
//数组开小导致内存覆写了，而且是 WA 不是 RE，这谁能看得出来啊！
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 152;
constexpr int MAXK = 1018;
constexpr int MAXLG = 56;
constexpr ll INF = 1e16 + 10181108;
ll n,t,Tk[MAXN],Ty[MAXN],h[MAXN][MAXK],g[MAXN][MAXK],maxw,ans;
struct Matrix{
	ll _c[MAXN][MAXN];
	Matrix(){
		memset(_c,0,sizeof(_c));
		return ;
	}
	Matrix(ll _val){
		SetINF();
		for(int i = 1;i <= n;i++){
			_c[i][i] = _val;
		}
		return ;
	}
	inline void SetINF(){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				_c[i][j] = INF;
			}
		}
		return ;
	}
	ll* operator[](int _x){
		return _c[_x];
	}
	const ll* operator[](int _x)const{
		return _c[_x];
	}
}opt[MAXLG],nowopt;
inline Matrix operator*(const Matrix& mtx1,const Matrix& mtx2){
	Matrix ret;
	ret.SetINF();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				ret[i][j] = min(ret[i][j],mtx1[i][k] + mtx2[k][j]);
			}
		}
	}
	return ret;
}
inline Matrix MakeOPT(){
	Matrix mtx;
	mtx.SetINF();
	for(int u = 1;u <= n;u++){
		for(int i = 1;i <= Tk[u];i++){
			const int v = g[u][i];
			mtx[u][v] = min(mtx[u][v],h[u][i] + Ty[u]);
		}
	}
	return mtx;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("kawaii.in","r",stdin);
	freopen("kawaii.out","w",stdout);
	cin>>n>>t;
	for(int i = 1;i <= n;i++){
		cin>>Tk[i]>>Ty[i];
		for(int j = 1;j <= Tk[i];j++){
			cin>>g[i][j];
		}
		for(int j = 1;j <= Tk[i];j++){
			cin>>h[i][j];
		}
	}
	opt[0] = MakeOPT();
	for(int i = 1;(1ll << i) <= t;i++){
		maxw = i;
		opt[i] = opt[i-1] * opt[i-1];
	}
	nowopt = Matrix(0);
	for(int i = maxw;i >= 0;i--){
		Matrix saveOPT = nowopt;
		nowopt = nowopt * opt[i];
		bool OK = false;
		for(int u = 1;u <= n;u++){
			for(int v = 1;v <= n;v++){
				if(nowopt[u][v] <= t)OK = true;
			}
		}
		if(OK){
			ans += 1ll<<i;
		}else{
			nowopt = saveOPT;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
