#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 22;
const int MAXS = (1<<18) + 1018 + 1108;
ll n,q,value[MAXN][MAXN],f[MAXS][MAXN],g[MAXS],h[MAXS];
inline int Lowbit(int x){
	return x & (-x);
}
inline int GetW(int x){
	int ret = 0;
	while(x){
		ret++;
		x >>= 1;
	}
	return ret;
}
inline void Solve(){
	const int maxs = (1<<n) - 1;
	h[0] = 1;
	for(int i = 1;i <= n;i++){
		f[1<<(i-1)][i] = 1;
	}
	for(int stat = 1;stat <= maxs;stat++){
		for(int u = 1;u <= n;u++){
			if(!(stat & (1<<(u-1))))continue;
			const int st = GetW(Lowbit(stat));
			for(int v = st+1;v <= n;v++){
				if(stat & (1<<(v-1)))continue;
				if(value[v][u] > value[v][v])continue;
				f[stat | (1<<(v-1))][v] += f[stat][u];
			}
			if(value[st][u] <= value[st][st]){
				g[stat] += f[stat][u];
			}
		}
	}
	for(int stat = 1;stat <= maxs;stat++){
		const int lbt = Lowbit(stat);
		for(int i = stat;i;i = (i-1) & stat){
			int oth = stat ^ i;
			if(!(i & lbt)){
				continue;//?
			}
			h[stat] += h[oth] * g[i];
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("gifts/gifts2.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int c;
			cin>>c;
			value[i][c] = j;
		}
	}
	Solve();
	cin>>q;
	const int maxs = (1<<n)-1;
	while(q--){
		string str;
		cin>>str;
		int nows = 0,len = str.length();
		for(int i = 0;i < len;i++){
			nows += (1<<i) * (str[i] == 'G');
		}
		cout<<h[nows] * h[maxs ^ nows]<<endl;
	}
	return not(Akano loves pure__Elysia);
}
//usaco feb22
