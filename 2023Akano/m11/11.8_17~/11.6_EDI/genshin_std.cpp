#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, qx[N], qy[N], fa[N], top[N], son[N], hs[N], d[N], dfn[N], tot, s[N], f[N][2], op[N];
long long asw;
vector<int>v[N], p[N], q[N];
void dfs1(int u, int Fa) {
	d[u] = d[fa[u] = Fa] + 1, son[u] = 1;
	for(auto i : v[u])i != fa[u] && (dfs1(i, u), son[u] += son[i], son[hs[u]] <= son[i] && (hs[u] = i));
}
void dfs2(int u, int T) {
	top[u] = T, dfn[u] = ++tot, hs[u] && (dfs2(hs[u], T), 0);
	for(auto i : v[u])i != fa[u] && i != hs[u] && (dfs2(i, i), 0);
}
int lca(int x, int y) {
	while(top[x] != top[y])d[top[x]] < d[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
	return d[x] < d[y] ? x : y;
}
int ask(int u) {
	int res = 0;
	while(u)res += s[u], u -= u & -u;
	return res;
}
void add(int u, int v) {
	while(u <= n)s[u] += v, u += u & -u;
}
void add(int x, int y, int v) {
	add(x, v), add(y + 1, -v);
}
void Add(int u, int to) {
	while(top[u] != top[to]){
		add(dfn[top[u]], dfn[u], 1), u = fa[top[u]];
	}
	add(dfn[to], dfn[u], 1);
}
int Ask(int u, int to) {
	int res = 0;
	while(top[u] != top[to])res += s[top[u]] - s[hs[u]], u = fa[top[u]];
	return res + s[to] - s[hs[u]];
}
void dfs(int u) {
	for(auto i : v[u]){
		if(i != fa[u]){
			dfs(i);
			f[u][0] += max(f[i][0], f[i][1]);
		}
	}
	s[u] = s[hs[u]], q[u].resize(p[u].size());
	int k = 0;
	for(auto i : p[u]){
		q[u][k++] = f[u][0] - Ask(qx[i], u) - Ask(qy[i], u) + 1;
		f[u][1] = max(f[u][1],q[u][k-1]);
	}
	s[u] += max(f[u][0], f[u][1]) - f[u][0];
}
void DFS1(int u) {
	if(op[u] || ask(dfn[u]) < ask(dfn[fa[u]])){
//		cerr<<u<<" OK"<<endl;
		if(f[u][0] >= f[u][1]) {
//			cerr<<u<<" set2"<<endl;
			op[u] = 2;
			for(auto i : v[u]){
				if(i != fa[u]){
					op[i] = 1;
//					cerr<<i<<" set1"<<endl;
				}
			}
		}
		if(f[u][0] <= f[u][1]) {
			int k = 0;
			for(auto i : p[u]){
				if(q[u][k] == f[u][1]){
//					cerr<<i<<" change "<<qx[i]<<" to "<<u<<" and "<<qy[i]<<" to "<<u<<endl;
					Add(qx[i],u), Add(qy[i],u),add(dfn[u], dfn[u], -1);
				}
				k++;
			}
		}
	}
//	cerr<<"aft "<<u<<" :";
//	for(int i = 1;i <= n;i++)cerr<<ask(i) - ask(i-1)<<" ";
//	cerr<<endl;
	for(auto i : v[u]){
		if(i != fa[u]){
			(DFS1(i), 0);
		}
	}
}
int DFS2(int u) {
	int res = (op[u] == 2);
	for(auto i : v[u]){
		if(i != fa[u]){
			res += DFS2(i);
		}
	}
	if(op[fa[u]] == 2){
		return res;
	}else{
		asw += 1ll * res * res;
		return 0;
	}
	return 0;
}
int main() {
	freopen("genshin/genshin4.in","r",stdin);
	scanf("%d%d", &n, &m);
	for(int x, y, i = 1; i < n; i++)scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	for(int i = 1; i <= m; i++)scanf("%d%d", qx + i, qy + i);
	dfs1(1, 0), dfs2(1, 1);
	for(int i = 1; i <= m; i++){
		p[lca(qx[i], qy[i])].push_back(i);
	}
	dfs(1);
//	for(int i = 1;i <= n;i++){
//		cerr<<i<<" f "<<f[i][0]<<","<<f[i][1]<<" tag "<<s[i]<<endl;
//	}
	memset(s, 0, sizeof(s));
	op[1] = 1, DFS1(1), DFS2(1), printf("%lld\n", asw);
//	for(int i = 1;i <= n;i++){
//		cerr<<op[i];
//	}
//	cerr<<endl;
}
