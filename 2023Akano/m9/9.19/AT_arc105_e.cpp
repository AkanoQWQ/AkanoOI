#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
int t,n,m;
int fa[MAXN],siz[MAXN];
int Find(int x){
	if(fa[x] == x)return x;
	return (fa[x] = Find(fa[x]));
}
inline void Merge(int u,int v){
	u = Find(u),v = Find(v);
	if(u == v)return ;
	if(u == 1 || u == n)swap(u,v);
	fa[u] = v,siz[v] += siz[u];
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1;i <= n;i++)fa[i] = i,siz[i] = 1;
		for(int i = 1;i <= m;i++){
			int u,v;
			cin>>u>>v;
			Merge(u,v);
		}
		//n * (n-1) / 2 - m - n * (n-k)
		if((n & 1) == 1){//? - ÒÑÖª - Å¼ 
			bool is2 = not((n * ll(n-1) / 2 - m) & 1);
			if(is2){
				cout<<"Second"<<'\n';
			}else{
				cout<<"First"<<'\n';
			}
		}else{
			if((siz[1] & 1) == (siz[n] & 1)){
				bool is2 = not((n * ll(n-1) / 2 - m - ll(siz[n]) * ll(siz[1])) & 1);
				if(is2){
					cout<<"Second"<<'\n';
				}else{
					cout<<"First"<<'\n';
				}
			}else{
				cout<<"First"<<'\n';
			}
		}
	}
	
	return not(Akano loves pure__Elysia);
}
