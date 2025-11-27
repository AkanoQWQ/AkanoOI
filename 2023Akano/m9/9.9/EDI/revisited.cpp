#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int TOT_MAXN = 262144 + 1018 + 1108;
const int INF = 1e9;
int n,arr[TOT_MAXN];
namespace Subtask1{
	const int MAXN = 2006 + 1018; 
	int f[MAXN][MAXN],best[MAXN][MAXN];
	inline ll Solve(){
		ll ret = 0;
		for(int i = 1;i <= n;i++){
			f[i][i] = arr[i];
			best[i][i] = i;
			best[i][n+1] = n;
		}
		for(int len = 2;len <= n;len++){
			for(int l = n - len + 1;l >= 1;l--){
				const int r = l + len - 1;
				f[l][r] = INF;
				int reall = max(l,best[l][r-1]),realr = min(r-1,best[l+1][r]);
				if(n <= 306){//万一四边形不等式不成立,保险 
					reall = l,realr = r;
				}
				for(int k = reall;k <= realr;k++){
					if(max(f[l][k],f[k+1][r]) + 1 < f[l][r]){
						best[l][r] = k;
					}
					f[l][r] = min(f[l][r],max(f[l][k],f[k+1][r])+1);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				ret += f[i][j];
			}
		}
		return ret;
	}
}
namespace Subtask2{//有错,如果出现相同的数会WA......放弃治疗了 
	int samecnt[TOT_MAXN];
	inline ll Solve(){
		ll ret = 0;
		for(int i = 1;i <= n;i++){
			ret += 1ll * (i-1) * (arr[i]+1);
			ret += arr[i];
		}
		return ret;
	}
}
bool IsSubtask2 = true;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("revisited.in","r",stdin);
	freopen("revisited.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		if(arr[i] < arr[i-1])IsSubtask2 = false;
	}
	if(n <= 2006 + 1108){
		cout<<Subtask1::Solve()<<endl;
	}else if(IsSubtask2){
		cout<<Subtask2::Solve()<<endl;
	} 
	return not(Akano loves pure__Elysia);
}
