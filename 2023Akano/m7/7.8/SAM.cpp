#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using ll = long long;
const int MAXN = 3e6 + 6;
struct Node{
	int len,link,cnt;
	bool cloned;
	map<char,int> nxt;
	inline bool Exist(const int ch){
		return nxt.find(ch) != nxt.end();
	}
}; 
struct Edge{
	int nxt,to;
}e[MAXN];
int head[MAXN],ent;
inline void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
class SAM{
	private:
		Node node[MAXN];
		int last,tot;
		ll ans;
		inline void Init(){
			node[0].len = node[0].cnt = 0,node[0].link = -1;
			last = 0;
			return ;
		}
		inline void InsertCh(char ch){
			const int cur = ++tot;
			node[cur].len = node[last].len + 1;
			node[cur].cnt = 1;
			int p = last;
			while(p != -1 && !node[p].Exist(ch)){
				node[p].nxt[ch] = cur;
				p = node[p].link;
			}
			if(p == -1){
				node[cur].link = 0;
			}else{
				int q = node[p].nxt[ch];
				if(node[q].len == node[p].len + 1){
					node[cur].link = q;
				}else{
					const int clone = ++tot;
					node[clone].len = node[p].len + 1;
					node[clone].link = node[q].link;
					node[clone].nxt = node[q].nxt;
					node[clone].cnt = 0;
					while(p != -1 && node[p].Exist(ch) && node[p].nxt[ch] == q){
						node[p].nxt[ch] = clone;
						p = node[p].link;
					}
					node[q].link = node[cur].link = clone;
				}
			}
			last = cur;
			return ;
		}
		void dfs(int u){
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				dfs(v);
				node[u].cnt += node[v].cnt;
			}
			if(node[u].cnt != 1)ans = max(ans,1ll * node[u].cnt * node[u].len);
			return ;
		}
	public:
		inline void Insert(const string& str){
			for(auto i : str){
				InsertCh(i);
			}
			return ;
		}
		inline ll Calc(){
			for(int i = 1;i <= tot;i++){
				AddEdge(node[i].link,i);
			}
			ans = 0;
			dfs(0);
			return ans;
		}
		SAM(){Init();}
}sam;
string mains;
int main(){
	freopen("P3804_1.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>mains;
	sam.Insert(mains);
	cout<<sam.Calc()<<endl;
	return 0;
}
