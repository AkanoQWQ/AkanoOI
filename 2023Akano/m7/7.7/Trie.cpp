#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int MAXSZ = 3e6 + 6;
const int MAXC = 65;
int Trans(char ch){//Size 62
	if(isdigit(ch))return ch - '0';
	if('a' <= ch && ch <= 'z')return (ch - 'a') + 10;
	if('A' <= ch && ch <= 'Z')return (ch - 'A') + 36;
	return 0;
}
class Trie{
	private:
		int nxt[MAXSZ][MAXC],pre[MAXSZ],cnt;
	public:
		inline void Clear(){
			for(int i = 0;i <= cnt;i++){
				pre[i] = 0;
				memset(nxt[i],0,sizeof(nxt[i]));
			}
			cnt = 0;
			return ;
		}
		inline void Insert(const string& str){
			int u = 0;pre[u]++;
			for(auto i : str){
				const int nxtch = Trans(i);
				if(nxt[u][nxtch] == 0)nxt[u][nxtch] = ++cnt;
				u = nxt[u][nxtch];
				pre[u]++;
			}
			return ;
		}
		inline int Find(const string& str){
			int u = 0;
			for(auto i : str){
				const int nxtch = Trans(i);
				if(nxt[u][nxtch] == 0)return 0;
				u = nxt[u][nxtch];
			}
			return pre[u];
		}
}tr;
int T,n,q;
string ins;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>q;
		tr.Clear();
		while(n--){
			cin>>ins;
			tr.Insert(ins);
		}
		while(q--){
			cin>>ins;
			cout<<tr.Find(ins)<<endl;
		}
	}
	return 0;
}
