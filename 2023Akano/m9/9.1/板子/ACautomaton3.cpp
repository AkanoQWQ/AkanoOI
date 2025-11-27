#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAX_SIZE = MAXN;
int app[MAXN];
template<int SIZE,typename infType,bool visOnce>
class AC_Automaton{//非标准模板! 
	private:
		int tr[SIZE][26],fail[SIZE],tot,vis[SIZE],in[SIZE];
		vector<infType> tag[SIZE];
		vector<int> e[SIZE];
		void dfs(int u){
			for(auto v : e[u]){
				dfs(v);
				vis[u] += vis[v];
			}
			for(auto i : tag[u])app[i] = vis[u];
		}
	public:
		inline void Insert(const string& str,infType inf){
			int u = 0;
			for(auto ch : str){
				int i = ch - 'a';
				if(tr[u][i] == 0)tr[u][i] = ++tot;
				u = tr[u][i];
			}
			tag[u].push_back(inf);
			return ;
		}
		inline void Build(){
			queue<int> q;
			for(int i = 0;i < 26;i++){
				if(tr[0][i])q.push(tr[0][i]);
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				e[fail[u]].push_back(u);
				for(int i = 0;i < 26;i++){
					if(tr[u][i]){
						fail[tr[u][i]] = tr[fail[u]][i];
						q.push(tr[u][i]);
					}else{
						tr[u][i] = tr[fail[u]][i];
					}
				}
			}
			return ;
		}
		inline void Find(const string& str){
			int u = 0;
			for(auto ch : str){
				int i = ch - 'a';
				u = tr[u][i];
				vis[u]++;
			}
			return ;
		}
		inline void Clear(){
			for(int i = 0;i <= tot;i++){
				memset(tr[i],0,sizeof(tr[i]));
				fail[i] = 0,tag[i].clear();
			}
			tot = 0;
			return ;
		}
		inline void Count(){
			dfs(0);
			return ;
		}
};
AC_Automaton<MAX_SIZE,int,false> aca;
int n,ans;
string s;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s;
		aca.Insert(s,i);
	}
	aca.Build();
	cin>>s;
	aca.Find(s);
	aca.Count();
	for(int i = 1;i <= n;i++)cout<<app[i]<<endl;
	return not(Akano loves pure__Elysia);
}
