#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 4e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,k,dep[MAXN],fa[MAXN],point,hST,hED;
vector<int> cnts[2];
void dfs(int u){
	cnts[dep[u] & 1].push_back(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dep[v]){
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs(v);
		}else{
			if(fa[u] == v || fa[v] == u)continue;
			if(abs(dep[v] - dep[u]) + 1 <= k){
				hST = u,hED = v;
			}else{
				point = v;
				if(dep[u] > dep[v])point = u;
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	dep[1] = 1;
	dfs(1);
	if(hST != 0){
		cout<<2<<endl;
		vector<int> otp;
		if(dep[hST] < dep[hED])swap(hST,hED);
		int pos = hST;
		while(1){
			otp.push_back(pos);
			if(pos == hED)break;
			pos = fa[pos];
		}
		cout<<otp.size()<<endl;
		for(auto i : otp){
			cout<<i<<" ";
		}
		cout<<endl;
	}else if(point != 0){
		int pos = point;
		cout<<1<<endl;
		for(int i = 1;i <= (k+1)/2;i++){
			cout<<pos<<" ";
			pos = fa[pos];
			pos = fa[pos];
		}
		cout<<endl;
	}else{
		cout<<1<<endl;
		if(cnts[0].size() > cnts[1].size()){
			for(int i = 0;i < (k+1)/2;i++){
				cout<<cnts[0][i]<<" "; 
			}
			cout<<endl;
		}else{
			for(int i = 0;i < (k+1)/2;i++){
				cout<<cnts[1][i]<<" "; 
			}
			cout<<endl;
		} 
	}
	return 0;
}
