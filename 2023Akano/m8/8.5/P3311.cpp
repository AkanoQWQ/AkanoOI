#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 2006 + 1018 + 1108;
const int MAXLEN = 1220; 
const int MAXS = 1e4;
const int MOD = 1e9 + 7;
class ACAutomaton{
	private:
		int tr[MAXN][11],fail[MAXN],tot;
		bool tag[MAXN];
	public:
		inline void Insert(const string& str){
			int now = 0;
			for(auto i : str){
				const int ch = i - '0';
				if(tr[now][ch] == 0)tr[now][ch] = ++tot;
				now = tr[now][ch];
			}
//			cout<<now<<" IS FLAG "<<endl;
			tag[now] = true;
			return ;
		}
		inline void Build(){
			queue<int> q;
			for(int i = 0;i < 10;i++){
				if(tr[0][i] != 0)q.push(tr[0][i]);
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				for(int i = 0;i < 10;i++){
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
		inline int GetNext(int now,int ch){
			return tr[now][ch];
		}
		inline bool IsFlag(int now){//ÐèÒªÌøfail? 
			while(now){
				if(tag[now])return true;
				now = fail[now];
			}
			return false;
		}
		inline int Size(){
			return tot;
		}
}aca;
string n,str;
int m;
ll f[MAXLEN][MAXS];
ll dfs(int pos,int stat,bool limit,bool lead0){
	if(aca.IsFlag(stat)){
		if(!limit && !lead0)f[pos][stat] = 0;
		return 0;
	}
	if(pos == n.length()){
		if(lead0)return 0;
		return 1;
	}
	if(!limit && !lead0 && f[pos][stat] != -1)return f[pos][stat];
	int up = limit ? (n[pos] - '0') : 9;
	ll ret = 0;
	for(int i = 0;i <= up;i++){
		if(lead0 && i == 0){
			ret += dfs(pos+1,0,limit && (i == up),lead0 && (i == 0));
		}else{
			ret += dfs(pos+1,aca.GetNext(stat,i),limit && (i == up),lead0 && (i == 0));
		}
		
		ret %= MOD;
	}
	if(!limit && !lead0)f[pos][stat] = ret;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(f,-1,sizeof(f));
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>str;
		if(str.length() > n.length())continue;
		aca.Insert(str);	
	}
	aca.Build();
	cout<<dfs(0,0,true,true);
	return 0;
}
