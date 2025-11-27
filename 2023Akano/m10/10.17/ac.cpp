#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
template<int SIZE,typename infType,bool visOnce>
class AC_Automaton{
private:
	int tr[SIZE][26],fail[SIZE],tot;
	bool vis[SIZE];
	vector<infType> tag[SIZE];
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
			cerr<<u<<" fail "<<fail[u]<<endl;
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
	inline void Find(const string& str,void (*Execute)(infType)){
		int u = 0;
		for(auto ch : str){
			int i = ch - 'a';
			u = tr[u][i];
			int pos = u;
			while(pos){
				if(vis[pos] && visOnce)break;
				vis[pos] = true;
				for(auto now : tag[pos]){
					Execute(now);
				}
				pos = fail[pos];
			}
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
};
AC_Automaton<MAXN,int,true> aca;
bool app[MAXN];
inline void Execute(int no){
	app[no] = true;
	return ;
}
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
	aca.Find(s,Execute);
	for(int i = 1;i <= n;i++){
		ans += app[i];
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
