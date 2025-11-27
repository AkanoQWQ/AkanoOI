#include<bits/stdc++.h>
using namespace std;
const int MAXM = 500006;
const int MAXN = 250006;
const int MAXK = 20;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,v;
}e[MAXM],e2[MAXM];
int tot = 1,head[MAXN],t2 = 1;
void AddEdge(int from,int to,int w){
	e[++tot].to = to;
	e[tot].v = w;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int dep[MAXN],le[MAXN],fa[MAXN][24],dfn[MAXN],dnt,lj[MAXN][24];
void dfs(int u,int father){
	dfn[u] = ++dnt;
	cout<<u<<" dfn "<<dfn[u]<<endl;
	dep[dnt] = dep[dfn[father]] + 1;
	fa[dfn[u]][0] = dfn[father];
	
//	cout<<"fa"<<u<<" in 2^"<<0<<" is "<<fa[dfn[u]][0]<<endl;
	for(int i = 1;i <= 20;i++){
		fa[dfn[u]][i] = fa[fa[dfn[u]][i-1]][i-1];
		lj[dfn[u]][i] = min(lj[fa[dfn[u]][i-1]][i-1],lj[dfn[u]][i-1]);
//		if(i <= 4)cout<<"fa"<<u<<" in 2^"<<i<<" is "<<fa[dfn[u]][i]<<endl;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			le[dnt+1] = min(e[i].v,le[dfn[u]]);
			lj[dfn[dnt+1]][0] = e[i].v;
			dfs(v,u);
		}
	}
}
int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	}
	if(x == y)return x;
	for(int i = 20;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int LJA(int x,int y){
	cout<<"LJA"<<x<<" , "<<y<<" is ";
	int ret = 0x7fffffff / 4;
	for(int i = 20;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y]){
			ret = min(ret,lj[x][i]);
			x = fa[x][i];
		}
	}
	cout<<ret<<endl;
	return ret;
}
int n,m;
int stk[MAXN],tp,h2[MAXN];
void awa(int from,int to,int v){
	e2[++t2].to = to;
	e2[t2].v = v;
	e2[t2].nxt = h2[from];
	h2[from] = t2;
	return ;
}
void uwu(int from,int to,int v){
	awa(from,to,v);
	awa(to,from,v);
	return ;
}
inline void ins(int u){
	if(tp == 0){
		stk[++tp] = u;
		return ;
	}
	int lc = LCA(u,stk[tp]);
//	cout<<u<<","<<stk[tp]<<"lc "<<lc<<endl;
	while(tp > 1 && dep[lc] < dep[stk[tp-1]]){
		uwu(stk[tp-1],stk[tp],LJA(stk[tp-1],stk[tp]));
		tp--;
	}
	if(tp != 0 && dep[lc] < dep[stk[tp]]){
		uwu(lc,stk[tp],LJA(lc,stk[tp]));
		tp--;
	}
	if(tp == 0 || stk[tp] != lc){
		stk[++tp] = lc;
	}
	stk[++tp] = u;
	return ;
}
void dfs2(int u,int father){
	cout<<"dfs2 "<<u<<endl;
	for(int i = h2[u];i;i = e2[i].nxt){
		const int v = e2[i].to;
		if(v != father){
			dfs2(v,u);
		}
	}
	return ;
}
/*int mset[MAXK],tail;
void show(){
	for(int i = 1;i <= tail;i++){
		cout<<mset[i]<<" ";
	}
	cout<<endl;
	return ;
}
void ins(int inx){
	for(int i = 1;i <= tail;i++){
		if(inx == mset[i])return ;
	}
	mset[++tail] = inx;
	return ;
}
void ers(int ox){
	for(int i = 1;i <= tail;i++){
		if(mset[i] == ox){
			for(int j = i;j < tail;j++){
				mset[j] = mset[j+1];
			}
			tail--;
			return ;
		}
	}
	return ;
}*/
/*void solve(){
	while(1){
		bool cg = 0;
		for(int i = 1;i <= tail;i++){
			for(int j = i+1;j <= tail;j++){
				int lc = LCA(mset[i],mset[j]);
				if(lc != 1 && le[lc] < le[mset[i]] + le[mset[j]]){
					int era = mset[i],erb = mset[j];
					ers(era);
					ers(erb);
					ins(lc);
					cg = 1;
				}
				if(cg)break;
			}
			if(cg)break;
		}
		if(!cg || tail == 1)break;
	}
	return ;
}*/
int main(){
	freopen("war.in","r",stdin);
	//freopen("war.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i < n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	le[1] = INF/4;
	dfs(1,1);
	scanf("%d",&m);
	while(m--){
		memset(h2,0,sizeof(h2));
		t2 = 1;
		int k;
		scanf("%d",&k);
		ins(1);
		while(k--){
			int c;
			scanf("%d",&c);
			cout<<"ins "<<c<<" and dfn "<<dfn[c]<<endl;
			ins(dfn[c]);
		}
		while(tp > 1){
			uwu(stk[tp-1],stk[tp],LJA(stk[tp-1],stk[tp]));
			tp--;
		}
		//solve();
		dfs2(1,1);
		cout<<endl<<endl;
	}
	return 0;
}
