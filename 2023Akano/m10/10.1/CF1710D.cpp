#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018 + 1108;
int T,n,fa[MAXN];//连通块左端点
int Find(int x){
	if(fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
string str[MAXN];
inline void Solve(){
	cin>>n;
	for(int u = 1;u <= n;u++){
		cin>>str[u];
		str[u] = "." + str[u];
		fa[u] = u;
	}
	for(int v = 1;v <= n;v++){//终点
		for(int u = v-1;u >= 1;u--){//顺序很重要
			const int len = v - u + 1;
			if(str[u][len] == '0' || Find(v) <= u)continue;//不连通或者已经连通
			
			cout<<u<<" "<<v<<endl;//既然[u,v]是同一连通块内，那么连上他们肯定不会更劣
			if(Find(Find(v) - 1)> u){//否则 v 所在连通块已经连通u，就不用继续连了
				cout<<u<<" "<<Find(v) - 1<<endl;//先把 u 和 (u,v) 间最右边的连通块连起来，然后依次连上v
				for(int k = Find(Find(v) - 1) - 1;k > u;k--){//在 [u,v] 中间的连通块
					if(Find(k) == k){//只连左端点
						cout<<k<<" "<<v<<endl;
					}
				}
			}
			for(int i = u;i <= v;i++)fa[i] = Find(u);//区间内泉部归到左端点上
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	Solve();
	return not(Akano loves pure__Elysia);
}
