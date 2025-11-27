#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MAXN = 18;
const int MAXS = (1<<6) + 10 + 18;
const int MAXM = 506;
const int MAXLEN = 106;
const int SIZE = 2006 + 1018 + 1108;

string s[MAXN];
int n,m,nowarr = 0,nxtarr = 1;

class ACAutomaton{
private:
	inline bool Check(const string& str,int pos){
		int len = str.length();
		for(int i = pos + 1; i < len; i++){
			int mirror = 2 * pos - i + 1;
			if(mirror < 0 || str[mirror] == str[i])return false;
		}
		return true;
	}
public:
	int nxt[SIZE][2],fail[SIZE],tot;
	int pass[SIZE],ed[SIZE];
	inline void Insert(const string& str,int id){
		int u = 0,pos = 0;
		for(auto ch : str){
			int i = ch - '0';
			if(nxt[u][i] == 0)nxt[u][i] = ++tot;
			u = nxt[u][i];
			if(Check(str,pos))pass[u] |= 1<<(id-1);
			pos++;
		}
		ed[u] |= 1<<(id-1);
		return ;
	}
	inline void Build(){
		queue<int> q;
		for(int i = 0;i < 2;i++){
			if(nxt[0][i] != 0){
				q.push(nxt[0][i]);
			}
		}
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			pass[u] |= pass[fail[u]],ed[u] |= ed[fail[u]];
			for(int i = 0;i < 2;i++){
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
}aca;

inline string F(string str){
	for(auto& ch : str){
		ch = (not(ch - '0') + '0');
	}
	return str;
}

ll f[2][SIZE][MAXS];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		aca.Insert(s[i],i);
		reverse(s[i].begin(),s[i].end());
		s[i] = F(s[i]);
		aca.Insert(s[i],i);
	}
	aca.Build();
	f[nxtarr][0][0] = 1;
	const int maxs = (1<<n) - 1;
	for(int i = 1;i <= m;i++){
		swap(nowarr,nxtarr);
		memset(f[nxtarr],0,sizeof(f[nxtarr]));
		for(int j = 0;j <= aca.tot;j++){
			for(int stat = 0;stat <= maxs;stat++){	
				for(int ch = 0;ch < 2;ch++){
					const int nxtPos = aca.nxt[j][ch];
					f[nxtarr][nxtPos][stat | aca.ed[nxtPos]] += f[nowarr][j][stat];
					f[nxtarr][nxtPos][stat | aca.ed[nxtPos]] %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0;i <= aca.tot;i++){
		for(int stat = 0;stat <= maxs;stat++){
			if((stat | aca.pass[i]) == maxs){
				ans += f[nxtarr][i][stat];
				ans %= MOD;
			}
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
