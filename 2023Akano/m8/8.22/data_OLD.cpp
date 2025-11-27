//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//const int MAXN = 3e5 + 1018 + 1108;
//struct Edge{
//	int nxt,to;
//}e[MAXN * 2];
//int head[MAXN],cnt;
//inline void AddEdge(int from,int to){
//	e[++cnt].to = to;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//ll a[MAXN],b[MAXN],fa[MAXN],n,arr[MAXN];
//vector<int> f[MAXN],now;
//inline ll Calc(vector<int> vec){
//	reverse(vec.begin(),vec.end());
//	ll suma = 0,ret = 0;
//	for(auto i : vec){
//		ret += suma * b[i];
//		suma += a[i];
//	}
//	return ret;
//}
//bool Cmp(int x,int y){
//	return a[x] * b[y] < a[y] * b[x];
//}
//void dfs(int u){
//	for(int i = head[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		dfs(v);
//		now.clear();
//		auto it1 = f[v].begin(),it2 = f[u].begin();
//		while(it1 != f[v].end() && it2 != f[u].end()){
//			if(Cmp(*it1,*it2)){
//				now.push_back(*(it1++));
//			}else{
//				now.push_back(*(it2++));
//			}
//		}
//		while(it1 != f[v].end()){
//			now.push_back(*(it1++));
//		}
//		while(it2 != f[u].end()){
//			now.push_back(*(it2++));
//		}
//		f[u] = now;
//	}
//	now.clear();
//	now.push_back(u);
//	for(auto i : f[u])now.push_back(i);
//	f[u] = now;
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("data/data2.in","r",stdin);
//	cin>>n;
//	for(int i = 2;i <= n;i++){
//		cin>>fa[i];
//		AddEdge(fa[i],i);
//	}
//	for(int i = 1;i <= n;i++){
//		cin>>a[i]>>b[i];
//	}
//	dfs(1);
//	for(auto i : f[1]){
//		cout<<i<<" ";
//	}
//	cout<<endl;
//	sort(f[1].begin(),f[1].end(),Cmp);
//	cout<<Calc(f[1]);
//	return 0;
//}
