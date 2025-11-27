#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 6;
struct Node{
	int dep,fail,len,cnt;
	map<char,int> nxt;
	inline bool Exist(char ch){
		return nxt.find(ch) != nxt.end();
	}
};
class PAM{
	private:
		Node node[MAXN];
		string str;
		int last,tot,ine[MAXN];
		inline void Init(){
			node[0].len = 0,node[0].fail = 1;//顺序不能改,因为默认的fail为0 
			node[1].len = -1,node[1].fail = 0;
			str = ".";
			last = 0;
			tot = 1;
			return ;
		}
		inline int GetFail(int u){
			const int pos = str.length()-1;
			while(str[pos - node[u].len - 1] != str[pos]){
				u = node[u].fail;
			}
			return u;
		}
		inline void InsertCh(char ch){
			str += ch;
			int p = GetFail(last);
			if(node[p].nxt[ch] == 0){
				const int cur = ++tot;
				const int curFail = GetFail(node[p].fail);
				node[cur].len = node[p].len + 2;
				node[cur].fail = node[curFail].nxt[ch];
				node[cur].dep = node[node[cur].fail].dep + 1;
				node[p].nxt[ch] = cur;
			}
			last = node[p].nxt[ch];
			node[last].cnt++;
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
			ll ret = 0;
			queue<int> q;
			for(int i = 2;i <= tot;i++){
				++ine[node[i].fail];
			}
			for(int i = 2;i <= tot;i++){
				if(!ine[i])q.push(i);
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				--ine[node[u].fail];
				node[node[u].fail].cnt += node[u].cnt;
				if(!ine[node[u].fail])q.push(node[u].fail);
				ret = max(ret,1ll * node[u].cnt * node[u].len);
			}
			return ret;
		}
		PAM(){Init();}
}pam;
string mains;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>mains;
	pam.Insert(mains);
	cout<<pam.Calc();
	return 0;
}
