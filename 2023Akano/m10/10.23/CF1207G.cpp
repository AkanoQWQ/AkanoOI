#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 4e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 4];
int strHead[MAXN],failHead[MAXN],cnt;//两个不同的图
void AddEdge(int from,int to,int head[]){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,q,strPos[MAXN],strSize[MAXN],dfn[MAXN],dnt;//字符串在AC自动机里的位置和它的子树大小
bool isRoot[MAXN];
ll ans[MAXN];
char chs[MAXN];
vector<int> querys[MAXN];
template<typename T,int SIZE>
class BIT{
private:
	T val[SIZE];
	inline int Lowbit(int x){
		return x & (-x);
	}
	inline T QueryPre(int x){
		T ret = 0;
		while(x){
			ret += val[x];
			x -= Lowbit(x);
		}
		return ret;
	}
public:
	inline void Change(int x,T _val){
		while(x <= SIZE){
			val[x] += _val;
			x += Lowbit(x);
		}
		return ;
	}
	inline T Query(int l,int r){
		return QueryPre(r) - QueryPre(l-1);
	}
	inline void Clear(){
		memset(val,0,sizeof(val));
		return ;
	}
	BIT(){Clear();}
};
BIT<ll,MAXN> bit;
class ACautomaton{
private:
	int nxt[MAXN][27],fail[MAXN],tot;
public:
	inline int Insert(const string& str){
		int u = 0;
		for(auto i : str){
			if(nxt[u][i - 'a'] == 0)nxt[u][i - 'a'] = ++tot;
			u = nxt[u][i - 'a'];
		}
		return u;
	}
	void failDFS(int u){
		strSize[u] = 1,dfn[u] = ++dnt;
		for(int i = failHead[u];i;i = e[i].nxt){
			const int v = e[i].to;
			failDFS(v);
			strSize[u] += strSize[v];
		}
		return ;
	}
	inline void Build(){
		queue<int> kueue;
		for(int i = 0;i < 26;i++){
			if(nxt[0][i] != 0)kueue.push(nxt[0][i]);
		}
		while(!kueue.empty()){
			const int u = kueue.front();
			kueue.pop();
			AddEdge(fail[u],u,failHead);
			for(int i = 0;i < 26;i++){
				if(nxt[u][i]){
					fail[nxt[u][i]] = nxt[fail[u]][i];
					kueue.push(nxt[u][i]);
				}else{
					nxt[u][i] = nxt[fail[u]][i];
				}
			}
		}
		failDFS(0);
		return ;
	}
	inline int GetNext(int u,int i){
		return nxt[u][i];
	}
}aca;

void GetAns(int u,int pos){
	bit.Change(dfn[pos],1);
	for(auto i : querys[u]){
		ans[i] = bit.Query(dfn[strPos[i]],dfn[strPos[i]] + strSize[strPos[i]] - 1);
	}
	for(int i = strHead[u];i;i = e[i].nxt){
		const int v = e[i].to;
		GetAns(v,aca.GetNext(pos,chs[v] - 'a'));
	}
	bit.Change(dfn[pos],-1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){		
		int opt,oldVer;
		cin>>opt;
		if(opt == 1){
			isRoot[i] = true;
			cin>>chs[i];
		}else if(opt == 2){
			cin>>oldVer>>chs[i];
			AddEdge(oldVer,i,strHead);
		}
	}
	cin>>q;
	for(int i = 1,ver;i <= q;i++){
		string str;
		cin>>ver>>str;
		strPos[i] = aca.Insert(str);
		querys[ver].push_back(i);
	}
	aca.Build();
	for(int i = 1;i <= n;i++){
		if(isRoot[i]){
			GetAns(i,aca.GetNext(0,chs[i] - 'a'));
		}
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}

