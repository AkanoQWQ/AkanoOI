#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 6e5 + 1018 + 1108;
class AC_Automaton{
	private:
		int nxt[MAXN][26],dep[MAXN],fail[MAXN],tot;
		bool vis[MAXN];
	public:
		inline int Insert(const string& str){
			int u = 0;
			for(auto ch : str){
				if(nxt[u][ch - 'a'] == 0){
					nxt[u][ch - 'a'] = ++tot;
					dep[tot] = dep[u] + 1;
				}
				u = nxt[u][ch - 'a'];
			}
			return u;
		}
		inline void Build(){
			queue<int> q;
			for(int i = 0;i < 26;i++){
				if(nxt[0][i] != 0)q.push(nxt[0][i]);
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
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
		inline void Visit(const string& str){
			int u = 0;
			for(auto ch : str){
				u = nxt[u][ch - 'a'];
				vis[u] = true;
			}
			return ;
		}
		inline void Clear(const string& str){
			int u = 0;
			for(auto ch : str){
				u = nxt[u][ch - 'a'];
				vis[u] = false;
			}
			return ;
		}
		inline int GetFail(int u){
			while(u){
				if(vis[u])return dep[u];
				u = fail[u];
			}
			return 0;
		}
		inline int LCA(int u,int v){
			if(dep[u] > dep[v]){
				
			}else{
				
			}
		}
}aca;
int n,q,pos[MAXN];
string str[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string/string2.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>str[i];
		pos[i] = aca.Insert(str[i]);
	}
	aca.Build();
	for(int i = 1;i <= q;i++){
		int u,v;
		cin>>u>>v;
		aca.Visit(str[v]);
		cout<<aca.GetFail(pos[u])<<endl;
		aca.Clear(str[v]);
	}
	return not(Akano loves pure__Elysia);
}

