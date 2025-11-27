#include<bits/stdc++.h>
using namespace std;
const int MAXN = 302;
const int MAXW = 20;
const int MAXQ = 5e4 + 1018 + 1108;
const int MOD = 1e9 + 7;
struct Query{
	int l,id;
	Query(){}
	Query(int _l,int _id){l = _l,id = _id;}
};
bool Cmp4Query(Query q1,Query q2){
	if(q1.l != q2.l)return q1.l < q2.l;
	return q1.id < q2.id;
}
vector<Query> query[MAXN];
int n,arr[MAXN],q;
int f[MAXN][MAXW][MAXW][3],ans[MAXQ];
long long a,b,ed;
//0 默认  IsSmaller !IsSmaller  按照优先级排序 
int len,num[MAXW];
inline void Build(long long x){
	len = 0;
	while(x){
		num[++len] = x % 10;
		x /= 10;
	}
	reverse(num+1,num+len+1);
//	memset(f,-1,sizeof(f));
	for(int i = 0;i <= ed+1;i++){
		for(int l = 0;l <= len+1;l++){
			for(int r = max(0,l-1);r <= len+1;r++){
				f[i][l][r][0] = f[i][l][r][1] = f[i][l][r][2] = -1;
			}
		}
	}
	return ;
}
int dfs(int pos,int l,int r,int imp){
	if(f[pos][l][r][imp] != -1)return f[pos][l][r][imp];
	if(pos > ed){
		if(r != len)return 0;
		if(l > 1 || imp != 2)return 1;
		return 0;
	}
	int ret = 0;
	ret += dfs(pos+1,l,r,imp);
	if(ret >= MOD)ret -= MOD;
	if(l-1 >= 1){
		if(arr[pos] < num[l-1]){
			ret += dfs(pos+1,l-1,r,1);
		}else if(arr[pos] == num[l-1]){
			ret += dfs(pos+1,l-1,r,imp);
		}else{
			ret += dfs(pos+1,l-1,r,2);
		}
		if(ret >= MOD)ret -= MOD;
	}
	if(r+1 <= len){
		if(arr[pos] < num[r+1]){
			if(imp == 0){
				ret += dfs(pos+1,l,r+1,1);
			}else{
				ret += dfs(pos+1,l,r+1,imp);
			}
		}else if(arr[pos] == num[r+1]){
			ret += dfs(pos+1,l,r+1,imp);
		}else{
			if(imp == 0){
				ret += dfs(pos+1,l,r+1,2);
			}else{
				ret += dfs(pos+1,l,r+1,imp);
			}
		}
		if(ret >= MOD)ret -= MOD;
	}
	f[pos][l][r][imp] = ret;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	cin>>q;
	for(int i = 1;i <= q;i++){
		int l,r;
		cin>>l>>r;
		query[r].emplace_back(l,i);
	}
	for(int i = 1;i <= n;i++){
		if(query[i].empty())continue;
		ed = i;
		Build(b);
		for(auto nowq : query[i]){
			for(int j = 0;j <= len;j++){
				ans[nowq.id] = (1ll * ans[nowq.id] + dfs(nowq.l,j+1,j,0)) % MOD;
			}
		}
		Build(a-1);
		for(auto nowq : query[i]){
			for(int j = 0;j <= len;j++){
				ans[nowq.id] = (1ll * ans[nowq.id] - dfs(nowq.l,j+1,j,0)) % MOD;
			}
		}
	}
	for(int i = 1;i <= q;i++){
		ans[i] = ((1ll * ans[i] % MOD) + MOD) % MOD; 
		cout<<ans[i]<<'\n';
	}	
	return 0;
}
