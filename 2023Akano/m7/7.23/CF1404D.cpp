#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
const int MAXM = 4e6 + 1018 + 1108;
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
int pr[MAXN];
bool vis[MAXN];
vector<int> ans1,ans2;
void dfs(int u,bool blk){
	vis[u] = true;
	if(blk){
		ans1.push_back(u);
	}else{
		ans2.push_back(u);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!vis[v])dfs(v,!blk);
	}
	return ;
}
int n;
inline void Solve1(){
	cout<<"Second"<<endl;
	for(int i = 1;i <= n;i++){
		AddEdge(i,i+n),AddEdge(i+n,i);
	}
	for(int i = 1;i <= 2*n;i++){
		int inp;
		cin>>inp;
		if(pr[inp] == 0){
			pr[inp] = i;
		}else{
			AddEdge(pr[inp],i),AddEdge(i,pr[inp]);
		}
	}
	for(int i = 1;i <= 2*n;i++){
		if(!vis[i])dfs(i,true);
	}
	long long cnt1 = 0;
	for(auto i : ans1){
		cnt1 += i;
	}
	if(cnt1 % (2*n) != 0){
		swap(ans1,ans2);
	}
	for(auto i : ans1){
		cout<<i<<" ";
	}
	cout<<endl;
	return ;
}
inline void Solve2(){
	cout<<"First"<<endl;
	for(int i = 1;i <= n;i++){
		cout<<i<<" ";
	}
	for(int i = 1;i <= n;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n & 1){
		Solve1();
	}else{
		Solve2();
	}
	int result = 0;
	cin>>result;
	return 0;
}
