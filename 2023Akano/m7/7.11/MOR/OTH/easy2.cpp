#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8006;//60pts
const int MAXM = 2e6 + 6;
struct Edge{
	int u,v,val,no;
}e[MAXM];
bool cmp(Edge _a,Edge _b){
	if(_a.val == _b.val)return _a.v < _b.v;
	return _a.val < _b.val;
}
int cnt;
inline void AddEdge(int from,int to,int val,int no){
	e[++cnt].val = val;
	e[cnt].u = from,e[cnt].v = to,e[cnt].no = no;
	return ;
}
int fa[MAXN];
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
int n,m,ans[MAXN],preans[MAXN];
inline bool comp(int a,int b,int c,int d){
	return (a == c && b == d) || (a == d && b == c);
}
int CG,CNT;
inline int Kruskal(int no){
	const Edge obj = e[no];
	if(preans[no] != 0)return preans[no];
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++){
		if(i == no)continue;
		if(comp(GetFa(e[i].u),GetFa(e[i].v),GetFa(obj.u),GetFa(obj.v))){
			if(preans[no] == 0)preans[no] = e[i].val;
			if(preans[i] != 0){
				break;
			}
			preans[i] = e[no].val;
			continue;
		}
		if(GetFa(e[i].u) != GetFa(e[i].v)){
			fa[GetFa(e[i].u)] = fa[e[i].v];
		}
	}
	if(preans[no] == 0)preans[no] = 1e9;
	return preans[no];
}
signed main(){
	freopen("easy4.in","r",stdin);//easy1!!!
	freopen("easy2.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w,i);
	}
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i <= m;i++){
		Kruskal(i);
	}
	for(int i = 1;i <= m;i++){
		ans[e[i].no] = preans[i];
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<'\n';
	}
	cout<<flush;
	return 0;
}

