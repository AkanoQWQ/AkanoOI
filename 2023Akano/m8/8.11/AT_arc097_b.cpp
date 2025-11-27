#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int fa[MAXN],n,m,val,pos[MAXN],ans;
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>val;
		pos[val] = i;
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		u = GetFa(u),v = GetFa(v);
		fa[u] = v;
	}
	for(int i = 1;i <= n;i++){
		ans += (GetFa(pos[i]) == GetFa(i));
	}
	cout<<ans<<endl;
	return 0;
}
