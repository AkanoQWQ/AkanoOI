#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
const int MAXN = 1e6 + 6;
const int MOD = 1e9 + 7;
int pi[MAXN];
inline void KMP(const string& str){
	const int len = str.length();
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(j && str[i] != str[j])j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
	}
	return ;
}
int n,num[MAXN],mem[MAXN],nxt[MAXN][23],len;
int Find(int u){
	if(!u)return 0;
	if(mem[u] != -1)return mem[u];
	return mem[u] = Find(pi[u-1]) + 1;
}
string s;
int main(){
	freopen("P2375_2.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		int ans = 1;
		cin>>s;
		KMP(s);
		len = s.length();
		for(int i = 1;i < len;i++){
			nxt[i][0] = pi[i-1];
			for(int j = 1;j <= 20;j++){
				nxt[i][j] = nxt[nxt[i][j-1]][j-1];
			}
			mem[i] = -1;
		}
		for(int i = 0;i < len;i++){
			int j = pi[i];
			for(int k = 20;k >= 0;k--){
				const int obj = nxt[j][k];
				if(2 * obj > i + 1)j = obj;
			}
			if(2 * j > i + 1)j = nxt[j][0];
			num[i] = Find(j);
			ans = (1ll * ans * (num[i]+1)) % MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
