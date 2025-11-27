#include<bits/stdc++.h>
using namespace std;
const int MAXSZ = 1018;
string passage,s;
int n;
unordered_map<string,int> vis;
class AC_Automaton{
	private:
		int nxt[MAXSZ][27],fail[MAXSZ],tot;
		set<int> len[MAXSZ];
	public:
		inline void Insert(const string& str){
			int u = 0;
			for(auto i : str){
				if(nxt[u][i-'a'] == 0)nxt[u][i-'a'] = ++tot;
				u = nxt[u][i-'a'];
			}
			len[u].insert(str.length());
			return ;
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
		int dfs(string str){
			if(vis.find(str) != vis.end())return vis[str];
			int u = 0,slen = str.length(),ret = str.length();
			for(int i = 0;i < slen;i++){
				u = nxt[u][str[i] - 'a'];
				if(!len[u].empty()){
					for(auto l : len[u]){
						string newstr;
						for(int j = 0;j < i-l+1;j++)newstr += str[j];
						for(int j = i+1;j < slen;j++)newstr += str[j];
						ret = min(ret,dfs(newstr));
					}
				}
			}
			vis[str] = ret;
			return ret;
		}
}ACA;
int main(){
	//freopen("./datas/string/string2.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>passage>>n;
	for(int i = 1;i <= n;i++){
		cin>>s;
		ACA.Insert(s);
	}
	ACA.Build();
	cout<<ACA.dfs(passage);
	return 0;
}
