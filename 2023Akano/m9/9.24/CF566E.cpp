#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1018;
using Edge = bitset<MAXN>;
Edge e[MAXN],con[MAXN],f[MAXN];
vector<int> leaf,nleaf;
int n,d[MAXN];
bool est[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n == 2){
		cout<<1<<" "<<2<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(int u = 1;u <= n;u++){
		cin>>d[u];
		for(int j = 1;j <= d[u];j++){
			int v;
			cin>>v;
			e[u][v] = true;
		}
	}
	bool OK = false;
	for(int i = 1;i <= n;i++){
		if(d[i] != n)OK = true;
	}
	if(OK == false){
		for(int i = 2;i <= n;i++){
			cout<<i<<" "<<1<<'\n';
		}
		return not(Akano loves pure__Elysia);
	}
	for(int u = 1;u <= n;u++){
		for(int v = u+1;v <= n;v++){
			Edge same = e[u] & e[v];
			if(same.count() == 2){
				int eu = same._Find_first();
				int ev = same._Find_next(eu);
				con[eu][ev] = true;
				con[ev][eu] = true;
				est[eu] = est[ev] = true;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(est[i]){
			nleaf.push_back(i);
		}else{
			leaf.push_back(i);
		}
	}
	for(auto u : leaf){
		for(int v = 1;v <= n;v++){
			if(e[u][v] && est[v])f[u][v] = true;
		}
	}
	for(auto u : nleaf){
		f[u] = con[u];
		f[u][u] = true;
	}
	if(nleaf.size() == 2){
		int boss = 0;
		for(auto u : leaf){
			if(boss == 0){
				boss = u;
				con[u][nleaf[0]] = true;
				con[nleaf[0]][u] = true;
			}else if(e[u] == e[boss]){
				con[u][nleaf[0]] = true;
				con[nleaf[0]][u] = true;
			}else{
				con[u][nleaf[1]] = true;
				con[nleaf[1]][u] = true;
			}
		}
	}else{
		for(auto l : leaf){
			for(auto fa : nleaf){
				if(f[l] == f[fa]){
					con[l][fa] = true;
					con[fa][l] = true;
					break;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(con[i][j])cout<<i<<" "<<j<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
