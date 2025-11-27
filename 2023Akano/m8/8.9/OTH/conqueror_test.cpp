#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1018;
const int MAXANS = 5e3 + 1018 + 1108;
const int MAXA = 5e3;
int t,n,a,b,h[MAXN];
namespace Subtask1{
	int f[MAXN][MAXANS],up[MAXN];
	inline int Solve(){
		if(a < b)swap(a,b);//让a尽可能大 
		sort(h+1,h+n+1);//让小的h在前面,尽可能减小up总和
		for(int i = 1;i <= n;i++){
			up[i] = min(((h[i]-1) / a) + 1 + up[i-1],MAXA);
			for(int j = 0;j <= up[i];j++){
				f[i][j] = MAXANS;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0; j <= up[i-1];j++){
				for(int k = j;k <= up[i];k++){
					const int left = h[i] - (k-j) * a;
					const int cost = (left > 0) ? (((left-1) / b) + 1) : 0;
					f[i][k] = min(f[i][k],f[i-1][j] + cost);
				}
			}
		}
		int ret = MAXANS;
		for(int i = 0;i <= up[n];i++){
			ret = min(ret,max(i,f[n][i]));
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("conqueror.in","r",stdin);
//	freopen("conqueror.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		for(int i = 1;i <= n;i++)cin>>h[i];
		cout<<Subtask1::Solve()<<endl;//t <= 4,endl OK
	}
	return 0;
}
//二进制优化? 
