#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
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
long long tag[MAXN];
int n,pos[MAXN];
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
	void dfs(int u){
		cerr<<u<<" org "<<tag[u]<<endl;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			dfs(v);
			tag[u] += tag[v];
		}
		cerr<<u<<" val "<<tag[u]<<endl;
		return ;
	}
	inline void GetAns(const string& str){
		int u = 0;
		for(auto i : str){
			tag[u]++;
			u = nxt[u][i - 'a'];
		}
		dfs(0);
		return ;
	}
	inline void Build(){
		queue<int> q;
		for(int i = 0;i < 26;i++){
			if(nxt[0][i] != 0){
				q.push(nxt[0][i]);
			}
		}
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			AddEdge(fail[u],u);
			cerr<<fail[u]<<" "<<u<<endl;
			for(int i = 0;i < 26;i++){
				if(nxt[u][i]){
					fail[nxt[u][i]] = nxt[fail[u]][i];
					q.push(nxt[u][i]);
				}else{
					nxt[u][i] = nxt[fail[u]][i];
				}
			}
		}
		return ;
	}
}aca;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		string s;
		cin>>s;
		pos[i] = aca.Insert(s);
	}
	aca.Build();
	string passage;
	cin>>passage;
	aca.GetAns(passage);
	for(int i = 1;i <= n;i++){
		cout<<tag[pos[i]]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
