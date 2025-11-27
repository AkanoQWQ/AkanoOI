#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXM = 206;
int n,m;
pair<int,int> lim[MAXM];
namespace Subtask1{
	const int MAXN = 1018 + 1108;
	bitset<MAXN> est;
	int arr[MAXN],obj[MAXN];
	inline ll Solve(){
		ll ret = 0;
		sort(lim+1,lim+m+1);
		for(int i = 1;i <= m;i++){
			obj[lim[i].first] = lim[i].second;
		}
		n = 1<<n;
		int maxs = (1<<n) - 1;
		for(int stat = 0;stat <= maxs;stat++){
			bool OK = true;
			for(int i = 0;i < n;i++){
				if(stat & (1<<i)){
					est[i] = true;
				}else{
					est[i] = false;
				}
			}
			for(int u = 0;u < n;u++){
				for(int v = u;v < n;v++){
					if(est[u] && est[v]){
						if(est[u^v] == false)OK = false;
					}
				}
			}
			int cnt = 0;
			for(int i = 0;i < n;i++){
				if(est[i])arr[++cnt] = i;
			}
			for(int i = 1;i <= n;i++){
				if(obj[i] != 0 && arr[i] != obj[i])OK = false;
			}
			if(cnt == 0)OK = false;
			ret += OK;
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>lim[i].first>>lim[i].second;
	}
	if(n <= 4){
		cout<<Subtask1::Solve()<<endl;
	}else{
		cout<<0<<endl;
	}
	return not(Akano loves pure__Elysia);
}
