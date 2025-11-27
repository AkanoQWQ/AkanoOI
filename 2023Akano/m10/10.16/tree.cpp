#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 306;
const int MOD = 1e9 + 7;
int tid,T,n,l[MAXN],r[MAXN];
ll f[MAXN][MAXN][MAXN];//前 i 个节点,剩下 j 个"上接口"(就是有 j 个子树),留了 k 个"下接口"(可以挂 k 个儿子)
inline void Add(ll& x,ll val){
	x += val;
	x %= MOD;
	return ;
}
inline ll Solve(){
	memset(f,0,sizeof(f));
	f[1][0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= n;k++){
				if(l[i] <= 0 && 0 <= r[i]){
					//自立子树
					Add(f[i+1][j+1][k],f[i][j][k]);
					//接在上面
					if(k >= 1)Add(f[i+1][j][k-1],f[i][j][k] * k);
				}
				if(l[i] <= 1 && 1 <= r[i]){
					//它的儿子可以是左子树或者右子树
					//自立子树
					Add(f[i+1][j+1][k+1],f[i][j][k] * 2);
					//接在上面
					if(k >= 1)Add(f[i+1][j][k-1+1],f[i][j][k] * 2 * k);
				}
				if(l[i] <= 2 && 2 <= r[i]){
					//自立子树
					Add(f[i+1][j+1][k+2],f[i][j][k]);
					//接在上面
					if(k >= 1)Add(f[i+1][j][k-1+2],f[i][j][k] * k);
					//上面两个转移没有乘以2,因为出现了两个新的接口,在后面选择的时候他们的 *k 会计算左子树和右子树的
					//把之前没有父亲的接在下面且自立子树
					if(j >= 1)Add(f[i+1][j-1+1][k+1],f[i][j][k] * 2 * j);
					//把之前没有父亲的接在下面且作为儿子接在前面
					if(j >= 1)Add(f[i+1][j-1][k-1+2-1],f[i][j][k] * 2 * k * (j-1));
				}
			}
		}
	}
	return f[n+1][1][0];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>tid>>T;
	while(T--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>l[i]>>r[i];
		}
		cout<<Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
