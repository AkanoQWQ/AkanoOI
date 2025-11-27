#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e6 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 40];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
string s[MAXN];
map<string,int> cnts;
int n,nnt,no[MAXN][2],f[MAXN];
class Trie{
private:
	int tr[MAXN][2],tot,trno[MAXN][2],lst[MAXN];
	vector<int> tag[MAXN];
public:
	inline void Insert(const string& str,int id){
		int u = 0;
		for(auto ch : str){
			const int i = ch - '0';
			if(tr[u][i] == 0)tr[u][i] = ++tot;
			u = tr[u][i];
		}
		tag[u].push_back(id);
		return ;
	}
	inline void Build(){
		queue<int> q;
		q.push(0);
		trno[0][0] = ++nnt,trno[0][1] = ++nnt;
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			for(auto id : tag[u]){
				//1.如果下面有选择的点的话,此处的点成为前缀,不能选
				//2.如果上面有选择的点的话(已经出现前缀),此处的点不能选(反过来选)
				//3.建立连接,向上传递
				//4.建立连接,向下传递
				AddEdge(trno[u][0],f[id]),AddEdge(trno[lst[u]][1],f[id]);
				AddEdge(id,trno[lst[u]][0]),AddEdge(id,trno[u][1]);
			}
			for(auto id1 : tag[u]){
				for(auto id2 : tag[u]){
					if(id1 == id2)continue;
					//同样的字符串,二选一
					AddEdge(id1,f[id2]);
				}
			}
			for(int i = 0;i < 2;i++){
				const int v = tr[u][i];
				if(v == 0)continue;
				trno[v][0] = ++nnt,trno[v][1] = ++nnt;
				//将向上的信息向上传递(0),向下的信息向下传递(1)
				AddEdge(trno[u][1],trno[v][1]),AddEdge(trno[v][0],trno[u][0]);
				q.push(v);
				lst[v] = u;
			}
		}
		return ;
	}
}trie;
/*2-sat 相关*/
int dfn[MAXN],low[MAXN],dnt,bel[MAXN],SCC_CNT;
stack<int> stk;
bool ins[MAXN];
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u);
	ins[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		SCC_CNT++;
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			ins[tp] = false;
			bel[tp] = SCC_CNT;
			if(tp == u)break;
		}
	}
	return ;
}
inline bool TwoSat(){
	for(int i = 1;i <= n;i++){
		if(!dfn[no[i][0]])Tarjan(no[i][0]);
		if(!dfn[no[i][1]])Tarjan(no[i][1]);
	}
	for(int i = 1;i <= n;i++){
		if(bel[no[i][0]] == bel[no[i][1]]){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		if(++cnts[s[i]] >= 3){
			cout<<"NO"<<endl;
			return not(Akano loves pure__Elysia);
		}
		no[i][0] = ++nnt,no[i][1] = ++nnt;
		f[no[i][0]] = no[i][1];
		f[no[i][1]] = no[i][0];
		int pos = -1;
		for(int j = 0;j < int(s[i].length());j++){
			if(s[i][j] == '?')pos = j;
		}
		if(pos == -1){
			trie.Insert(s[i],no[i][0]);
			trie.Insert(s[i],no[i][1]);
		}else{
			s[i][pos] = '0';
			trie.Insert(s[i],no[i][0]);
			s[i][pos] = '1';
			trie.Insert(s[i],no[i][1]);
		}
	}
	trie.Build();
	if(TwoSat()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return not(Akano loves pure__Elysia);
}
