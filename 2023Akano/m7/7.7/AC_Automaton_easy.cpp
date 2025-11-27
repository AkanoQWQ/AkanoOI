#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
const int MAXSZ = 1e6 + 6;
const int MAXC = 29;
int Trans(char ch){//Size 26
	if('a' <= ch && ch <= 'z')return (ch - 'a');
	return 0;
}
class ACAutomaton{
	private:
		int fail[MAXSZ],tr[MAXSZ][MAXC],cnt;
		int word[MAXSZ];
		bool vis[MAXSZ];
	public:
		inline void Insert(const string& str){
			int u = 0;
			for(auto i : str){
				const int nxtch = Trans(i);
				if(tr[u][nxtch] == 0)tr[u][nxtch] = ++cnt;
				u = tr[u][nxtch];
			}
			++word[u];
		}
		inline void Build(){
			queue<int> q;
			for(int i = 0;i < 26;i++){
				if(tr[0][i]){
					q.push(tr[0][i]);
				}
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
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
		inline int Find(const string& str){
			int u = 0,ret = 0;
			for(auto i : str){
				const int nxtch = Trans(i);
				u = tr[u][nxtch];
				if(word[u] && !vis[u]){
					ret += word[u],vis[u] = true;
				}
			}
			return ret;
		}
}ACA;
string ins;
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>ins;
		ACA.Insert(ins);
	}
	cin>>ins;
	ACA.Build();
	cout<<ACA.Find(ins);
	return 0;
}

