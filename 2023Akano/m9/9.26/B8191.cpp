#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 616;
pii seg[MAXN];
vector<int> vec;
int n,f[MAXN][MAXN],g[MAXN][MAXN],tot;
//g[i][j] 表示被 i,j 完泉覆盖的区间个数
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	tot = 2 * n;
	for(int i = 1;i <= n;i++){
		cin>>seg[i].first>>seg[i].second;
		vec.push_back(seg[i].first),vec.push_back(seg[i].second);
	}
	{
		sort(vec.begin(),vec.end());
		auto it = unique(vec.begin(),vec.end());
		vec.erase(it,vec.end());
		for(int i = 1;i <= n;i++){
			seg[i].first = lower_bound(vec.begin(),vec.end(),seg[i].first) - vec.begin() + 1;
			seg[i].second = lower_bound(vec.begin(),vec.end(),seg[i].second) - vec.begin() + 1;
		}
		tot = vec.size();
	}
	for(int i = 1;i <= n;i++){
		g[seg[i].first][seg[i].second]++;
	}
	for(int len = 2;len <= tot;len++){
		for(int l = 1;l + len - 1 <= tot;l++){
			int r = l + len - 1;
			g[l][r] += g[l+1][r] + g[l][r-1] - g[l+1][r-1];//二维前缀和求区间内的线段个数
		}
	}
	for(int len = 2;len <= tot;len++){
		for(int l = 1;l + len - 1 <= tot;l++){
			int r = l + len - 1;
			for(int k = l;k < r;k++){
				if(g[l][k] + g[k+1][r] < g[l][r]){
					//有至少一根被l,r完泉覆盖线段穿过了k
					f[l][r] = max(f[l][r],f[l][k] + f[k+1][r] + 1);
				}
			}
		}
	}
	cout<<f[1][tot]<<endl;
	return not(Akano loves pure__Elysia);
}
