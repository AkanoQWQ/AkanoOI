#include<bits/stdc++.h>
using namespace std;
const int MAXS = (1<<11) + 1018 + 1108;
int n,m,maxstat,edge[16],f[MAXS];
int dfs(int stat){
	if(f[stat] != 0)return f[stat];
	if(stat == 0)return 0;
	int ret = 1018;
	for(int nxt = 1;nxt <= maxstat;nxt++){
		if((nxt & stat) != nxt)continue;//stat not include nxt
		bool OK = true;
		for(int j = 1;j <= m;j++){
			if((nxt & edge[j]) == edge[j]){//nxt include edge
				OK = false;
				break;
			}
		}
		if(!OK)continue;
		ret = min(ret,dfs(stat - nxt) + 1);
	}
	f[stat] = ret;
	return ret;
}
inline int Solve(){
	maxstat = (1<<n) - 1;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		edge[i] = (1<<(u-1)) + (1<<(v-1));
	}
	return dfs(maxstat);
}
int main(){
	//freopen("./datas/bomb/mydata_bomb.in","r",stdin);
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n <= 16 && m <= 16){
		cout<<Solve()<<endl;
	}else{//TREE??
		if(m == 0){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	return 0;
}
