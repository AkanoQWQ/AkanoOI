#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int MAXN = 1e6 + 1018;
const int MAXSZ = MAXN * 2 + 1108;
struct Node{
	int link,nxt[27],cnt,len;//Query nxt is empty!Should be initilized before main()
	bool cloned;
	Node(){link = cnt = len = cloned = 0;}
	Node(int _link,int _len,bool _cloned){
		link = _link,len = _len,cloned = _cloned;
		cnt = cloned ? 0 : 1;
	}
};
class SAM{
	private:
		Node node[MAXSZ];
		int cnt,last,ans;
		inline void InsertCh(char ch){
			const int now = ch - 'a';
			const int cur = ++cnt;
			node[cur].len = (0,node[last].len+1,false);
			int p = last;
			while(p != -1 && node[p].nxt[now] == 0){//=0?OK?
				node[p].nxt[now] = cur;
				p = node[p].link;
			}
			if(p == -1){
				node[cur].link = 0;
			}else{
				int q = node[p].nxt[now];
				if(node[q].len == node[p].len + 1){
					node[cur].link = q;
				}else{
					const int clone = ++cnt;
					node[clone] = node[q];
					node[clone].cloned = true,node[clone].cnt = 0;
					node[clone].len = node[p].len + 1;
					while(p != -1 && node[p].nxt[now] == q){
						node[p].nxt[now] = clone;
						p = node[p].link;
					}
					node[q].link = node[cur].link = clone;
				}
			}
			last = cur;
			return ;
		}
		inline void Init(){
			cnt = last = 0;
			node[0].link = -1,node[0].len = 0,node[0].cnt = 0;
			return ;
		}
		void dfs(int u){
			for(int i = 0;i < 26;i++){
				if(node[u].nxt[i]){
					dfs(node[u].nxt[i]),node[u].cnt += node[node[u].nxt[i]].cnt;
				}
			}
			if(node[u].cnt != 1)ans = max(ans,node[u].cnt * node[u].len);
			return ;
		}
	public:
		inline void Insert(const string& str){
			for(auto i : str){
				InsertCh(i);
			}
			return ;
		}
		inline int Solve(){
			ans = 0;
			dfs(0);
			return ans;
		}
		SAM(){Init();}
}sam;
string ins;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//freopen(".in","r",stdin);
	cin>>ins;
	sam.Insert(ins);
	cout<<sam.Solve();
	return 0;
}
