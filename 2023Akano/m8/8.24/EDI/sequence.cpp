#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int blk = 101811080;
const int database[5] = {1,239507339,222677047,776020743,62711072};
ll type,n,k;
string str;
namespace Subtask1{
	const int MAXN = 25;
	const int MAXS = (1<<24) + 1018 + 1108;
	unordered_map<int,int> f[2];
	inline int str2num(string s){
		int ret = 0;
		for(int i = 0;i < n;i++){
			ret += (s[i] - '0') * (1<<i);
		}
		return ret;
	}
	inline bool GetW(int num,int w){
		return (num >> (w-1)) & 1;
	}
	inline int F(int num,int w){
		if(GetW(num,w)){
			return num - (1<<(w-1));
		}else{
			return num + (1<<(w-1));
		}
	}
	inline vector<int> Add(int stat){
		vector<int> ret;
		for(int st = 1;st <= n;st++){
			int nxt = F(stat,st);
			if(GetW(nxt,st))continue;
			ret.push_back(nxt);
			for(int ed = st+1;ed <= n;ed++){
				nxt = F(nxt,ed);
				if(GetW(nxt,ed) == GetW(nxt,ed-1))break;
				if((ed - st) & 1)continue;
				ret.push_back(nxt);
			}
		}
		return ret;
	}
	inline int MainSolve(int Gstat){
		const int maxs = 1<<n;
		int now = 0,nxt = 1;
		f[nxt][Gstat] = 1;
		for(int i = 1;i <= k;i++){
			swap(now,nxt);
			f[nxt].clear();
			for(auto j : f[now]){
				const int u = j.first,val = j.second;
				vector<int> e = Add(u);
				for(auto v : e){
					f[nxt][v] += val;
					if(f[nxt][v] >= MOD)f[nxt][v] -= MOD;
				}
			}
		}
		int ret = 0;
		for(int i = 0;i < maxs;i++){
			ret += f[nxt][i];
			if(ret >= MOD)ret -= MOD;
		}
		return ret;
	}
	inline int Solve(){
		cin>>str;
		return MainSolve(str2num(str));
	}
}
namespace Subtask2{
	const int MAXN = 144;
	ll f[MAXN][MAXN],g[MAXN][MAXN],C[MAXN][MAXN];
	inline void Pre(){
		for(int i = 0;i <= n+1;i++){
			C[i][0] = 1;
		}
		for(int i = 1;i <= n+1;i++){
			for(int j = 1;j <= n+1;j++){
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
			}
		}
		return ;
	}
	inline ll Solve(){
		Pre();
		f[0][0] = g[0][0] = 1;//?
		for(int i = 1;i <= n+1;i++){//n+1,因为"交替序列"的1的个数为n+1? 
			f[i][0] = g[i][0] = 1;
			for(int j = 1;j <= i;j++){//OK?
				for(int firx = 1;firx <= i;firx++){//first x,y
					for(int firy = 1;firy <= j;firy++){
						g[i][j] += (((f[firx-1][firy-1] * f[i-firx][j-firy]) % MOD) * C[j][firy]) % MOD;
						g[i][j] %= MOD;//C(j,firy)表示步骤顺序不确定? 
					}
				}
				for(int k = 0;k <= i;k++){
					f[i][j] += g[k][j];//什么意思? 
					f[i][j] %= MOD;
				}
			}
		}
		return f[n+1][k];
	}
}
namespace Subtask3{
	inline int Solve(){
		if(n >= 499122177)return 0;
		int pre = n / blk;
		ll ret = database[pre],now = 3 + blk * pre * 2;
		n -= pre * blk;
		for(ll i = 1;i <= n;i++){
			ret = (ret * now) % MOD;
			now += 2;
			if(now >= MOD)now -= MOD;
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("sequence.in","r",stdin);
	cin>>type>>n>>k;
	if(type == 1){
		cout<<Subtask1::Solve()<<endl;
	}else if(k != n+1){
		cout<<Subtask2::Solve()<<endl;
	}else{
		cout<<Subtask3::Solve()<<endl;
	}
	return 0;
}
