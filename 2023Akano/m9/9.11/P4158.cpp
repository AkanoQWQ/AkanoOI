#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 66;
const int MAXT = 2006 + 1018;
int n,m,t,f[MAXT],ans,one[MAXN],g[MAXN][MAXN],item[MAXN];//f 背包 g 截止 i 用了 j 次最多获得的贡献 
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;
	for(int i = 1;i <= n;i++){
		cin>>str;
		for(int j = 1;j <= m;j++){
			one[j] = one[j-1] + str[j-1] - '0';
			item[j] = 0;
		}
		for(int j = 1;j <= m;j++){
			for(int z = 1;z <= m;z++){
				g[j][z] = 0;
			}
			for(int k = 0;k < j;k++){//1 ~ k and k+1 ~ j
				for(int z = 1;z <= m;z++){
					g[j][z] = max(g[j][z],g[k][z-1] + one[j] - one[k]);//k -> j 刷 1
					g[j][z] = max(g[j][z],g[k][z-1] + (j - k) - (one[j] - one[k]));//k -> j 刷 0
				}
			}
			for(int z = 1;z <= m;z++){
				item[z] = max(item[z],g[j][z]);
			}
		}
		for(int k = t;k >= 1;k--){//转移顺序!只能选一件物品! 
			for(int j = 1;j <= min(m,k);j++){
				f[k] = max(f[k],f[k-j] + item[j]);
			}
		}
	}
	for(int i = 1;i <= t;i++){
		ans = max(ans,f[i]);
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
