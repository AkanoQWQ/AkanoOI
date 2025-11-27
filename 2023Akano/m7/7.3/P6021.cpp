#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
const int MAXSZ = 3;//1 ~ 2
const int SIZ = 2;
const int INF = 1e8;
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
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline char ReadC(){
	char ch = getchar();
	while(ch != 'Q' && ch != 'C')ch = getchar();
	return ch;
}
void Write(int x){
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
struct Matrix{
	int c[MAXSZ][MAXSZ];
	int* operator[](const int& _x){
		return c[_x];
	}
	Matrix(){c[1][1] = c[1][2] = c[2][1] = c[2][2] = -INF;}
	Matrix(int u1,int u2,int u3,int u4){c[1][1] = u1,c[1][2] = u2,c[2][1] = u3,c[2][2] = u4;}
};
Matrix def[MAXN];
Matrix operator+(Matrix ma,Matrix mb){
	Matrix ret;
	for(int i = 1;i <= SIZ;i++){
		for(int j = 1;j <= SIZ;j++){
			for(int k = 1;k <= SIZ;k++){
				ret[i][j] = max(ret[i][j],ma[i][k] + mb[k][j]);	
			}
		}
	}
	return ret;
}
ostream& operator<<(ostream& cout,Matrix& mtx){
	cout<<mtx[1][1]<<","<<mtx[1][2]<<endl;
	cout<<mtx[2][1]<<","<<mtx[2][2]<<endl;
	return cout;
}
int n,m,a[MAXN],org[MAXN];
class SegmentTree{
	private:
		Matrix val[MAXN * 4];
		inline void PushUp(int p){//No PushDown()
			val[p] = val[p*2] + val[p*2+1];
			return ;
		}
		void Build(int p,int l,int r){
			if(l == r){
				const int no = org[l];
				val[p] = def[no];
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid);
			Build(p*2+1,mid+1,r);
			PushUp(p);
			return ;
		}
		void Change(int p,int l,int r,int OBJ,const Matrix& mtx){
			if(l == r){
				val[p] = mtx;
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,mtx);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,mtx);
			PushUp(p);
			return ;
		}
		Matrix Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL && mid < OBJR){
				return Query(p*2,l,mid,OBJL,OBJR) + Query(p*2+1,mid+1,r,OBJL,OBJR);
			}else if(mid >= OBJL){
				return Query(p*2,l,mid,OBJL,OBJR);
			}else if(mid < OBJR){
				return Query(p*2+1,mid+1,r,OBJL,OBJR);
			}
			return val[114514];
		}
	public:
		inline void Change(int OBJ,const Matrix& mtx){
			Change(1,1,n,OBJ,mtx);
			return ;
		}
		inline Matrix Query(int OBJL,int OBJR){
			return Query(1,1,n,OBJL,OBJR);
		}
		inline void Build(){
			Build(1,1,n);
			return ;
		}
}tr; 
namespace SLPF{
	int sz[MAXN],heavy[MAXN],fa[MAXN],dfn[MAXN],top[MAXN],tp[MAXN],end[MAXN],dnt;
	int f[MAXN][2],g[MAXN][2];
	void dfs1(int u){
		sz[u] = 1;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if(sz[v] > sz[heavy[u]])heavy[u] = v;
		}
		return ;
	}
	inline void UpdateMatrix(const int& p){
		def[p] = Matrix(g[p][1],g[p][1],g[p][0],-INF);
		return ;
	}
	inline void UpdateFG(const int& p){
		int nowf0 = f[p][0],nowf1 = f[p][1];
		return ;
	}
	void dfs2(int u,int tp){
		dfn[u] = ++dnt,top[u] = tp,end[tp] = u;
		org[dnt] = u;
		f[u][1] = g[u][0] = a[u];
		if(heavy[u]){
			dfs2(heavy[u],tp);
			f[u][0] += max(f[heavy[u]][0],f[heavy[u]][1]);
			f[u][1] += f[heavy[u]][0];
		}
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u] || v == heavy[u])continue;
			dfs2(v,v);
			f[u][0] += max(f[v][0],f[v][1]);
			f[u][1] += f[v][0];
			g[u][0] += f[v][0];
			g[u][1] += max(f[v][0],f[v][1]);//??????IS OK????
		}
		UpdateMatrix(u);
		return ;
	}
	void CheckDfs(int u){
		int g0 = a[u],g1 = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == fa[u])continue;
			CheckDfs(v);
			if(v != heavy[u])g1 += max(f[v][0],f[v][1]),g0 += f[v][0];
		}
		if(g0 != g[u][0] || g1 != g[u][1])cout<<"G Wrong !"<<endl;
	}
	inline void Init(){
		dfs1(1);
		dfs2(1,1);
		CheckDfs(1);
		tr.Build();
		return ;
	}
	inline void Change(int u,int val){
		def[u][2][1] += val - a[u];
  		a[u] = val;
		while(u != 0){
			const int _top = top[u],_end = end[_top];
			
			Matrix orgf = tr.Query(dfn[_top],dfn[_end]);
			const int orgf0 = orgf[1][1],orgf1 = orgf[2][1];
			
			tr.Change(dfn[u],def[u]);
			
			Matrix nowf = tr.Query(dfn[_top],dfn[_end]);
			const int nowf0 = nowf[1][1],nowf1 = nowf[2][1];
			const int _fa = fa[_top];
			u = _fa;
			def[u][1][1] -= max(orgf0,orgf1) - max(nowf0,nowf1),def[u][2][1] -= orgf0 - nowf0;
			def[u][1][2] = def[u][1][1];
		}
		return ;
	}
	inline void Query(int x){
		const int _top = top[x],_end = end[_top];
		Matrix ansf = tr.Query(dfn[_top],dfn[_end]);
		Write(max(ansf[1][1],ansf[2][1])),putchar('\n');
		return ;
	}
}
int main(){
	//freopen("P4719_4.in","r",stdin);
	n = Read();
	for(int i = 1;i <= n;i++)a[i] = Read();
	for(int i = 1;i < n;i++){
		int u = Read(),v = Read();
		AddEdge(u,v),AddEdge(v,u);
	}
	SLPF::Init();
	m = Read();
	while(m--){
		char opt = ReadC();
		if(opt == 'C'){
			int pos = Read(),val = Read();
			SLPF::Change(pos,val);
		}else{
			int x = Read();
			SLPF::Query(x);
		}
		
	}
	return 0;
}
