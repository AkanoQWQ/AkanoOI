#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 2e5 + 6;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
ll ans[MAXN],f[MAXN],tot[MAXN],sz[MAXN];
vector<pii> v1,v2;
void msort(int l,int r){
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	msort(l,mid),msort(mid+1,r);
	int i = l,j = mid + 1,tail = l;
	ll totcnt = 0;
	for(int i = l;i <= r;i++)totcnt += v1[i].first;
	while(i <= mid && j <= r){
		if(v1[i].second * (totcnt - v1[i].first) < v1[j].second * (totcnt - v1[j].first)){
			v2[tail++] = v1[i++];
		}else{
			v2[tail++] = v1[j++];
		}
	}
	while(i <= mid){
		v2[tail++] = v1[i++];
	}
	while(j <= mid){
		v2[tail++] = v1[j++];
	}
	for(int i = l;i <= r;i++){
		v1[i] = v2[i];
	}
	return ;
}
inline void MergeSort(vector<pii>& vec){
	if(vec.size() == 0)return ;
	v1 = vec,v2 = vec;
	msort(0,vec.size()-1);
	vec = v1;
	return ;
}
void dfs(int u,int fa){
	tot[u] = f[u],sz[u] = 1;
	vector<pii> vec;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		vec.push_back(make_pair(tot[v],sz[v]));
		sz[u] += sz[v];
		tot[u] += tot[v];
		ans[u] += ans[v];
	}
	MergeSort(vec);
	ans[u] += f[u];
	int ccnt = 1;
	for(int i = 0;i < vec.size();i++){
		ans[u] += vec[i].first * ccnt;
		ccnt += vec[i].second;
	}
	return ;
}
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("ex_signin3.in","r",stdin);
//	freopen("signin.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++)cin>>f[i];
	ll mainans = INF;
	for(int root = 1;root <= n;root++){
		memset(ans,0,sizeof(ans));
		memset(tot,0,sizeof(tot));
		memset(sz,0,sizeof(sz));
		dfs(root,root);
		mainans = min(mainans,ans[root]);
	}
	cout<<mainans<<endl;
	return 0;
}
