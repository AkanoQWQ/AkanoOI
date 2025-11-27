#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 106;
const int MAXM = 2006 + 1018;
const int MAXA = 1e4 + 14;
ll n,m,a,b,up,w[MAXN][MAXM],f[MAXN][MAXA][10],value[MAXN][MAXM],cntf[MAXN];
vector<ll> vec;
inline void ReadIn(){
	cin>>n>>m>>a>>b;
	up = 2 * b + 1;
	vec.reserve(m+2);
	for(int i = 1;i <= n;i++){
		vec.clear();
		cntf[i] = cntf[i-1];
		for(int j = 1;j <= m;j++){
			cin>>w[i][j];
			vec.push_back(w[i][j]);
			value[i][0] += w[i][j];
			if(w[i][j] < 0)cntf[i]++;
			
		}
		sort(vec.begin(),vec.end());
		for(int j = 1;j <= m;j++){
			if(vec[j-1] < 0){
				value[i][j] = value[i][j-1] - vec[j-1];
			}else{
				value[i][j] = value[i][j-1];
			}
		}
	}
	return ;
}
namespace Subtask1{
	inline ll Solve(){
		ll ret = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= a;j++){
				for(int s = 2;s <= up;s++){
					if((s & 1) == 0){//要选
						for(int k = 0;k <= j;k++){
							f[i][j][s] = max(f[i][j][s],f[i-1][k][s] + value[i][j-k]);
							f[i][j][s] = max(f[i][j][s],f[i-1][k][s-1] + value[i][j-k]);
						}
					}else{//不选
						f[i][j][s] = max(f[i-1][j][s],f[i-1][j][s-1]);
					}
				}
			}
		}
		for(int i = 0;i <= a;i++){
			for(int s = 1;s <= up;s++){
				ret = max(ret,f[n][i][s]);
			}
		}
		return ret;
	}
}
namespace Subtask2{
	inline ll Solve(){
		ll ret = 0;
		for(int i = 1;i <= n;i++){
			int best[10] = {0};
			for(int j = 0;j <= min(cntf[i],a);j++){
				for(int s = 2;s <= up;s++){
					if((s & 1) == 0){//要选
						for(int k = max(best[s],int(j - m));k <= j;k++){
							f[i][j][s] = max(f[i][j][s],f[i-1][k][s] + value[i][j-k]);
							f[i][j][s] = max(f[i][j][s],f[i-1][k][s-1] + value[i][j-k]);
							if(f[i][j][s] == max(f[i-1][k][s] + value[i][j-k],f[i-1][k][s-1] + value[i][j-k])){
								best[s] = k;
							}
						}
					}else{//不选
						f[i][j][s] = max(f[i-1][j][s],f[i-1][j][s-1]);
					}
				}
			}
		}
		for(int i = 0;i <= a;i++){
			for(int s = 1;s <= up;s++){
				ret = max(ret,f[n][i][s]);
			}
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ReadIn();
	if(m <= 106 && a <= 506){
		cout<<Subtask1::Solve()<<endl;
	}else{
		cout<<Subtask2::Solve()<<endl;
	}
	return not(Akano loves pure__Elysia);
}
