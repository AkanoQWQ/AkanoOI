#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 400006;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string sread(){
    string s = "";
    char c = getchar();
    while(c != '(' && c != ')'){
		c = getchar();
	}
    while(c == '('|| c == ')'){
		s += c;
		c = getchar();
	}
    return s;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
string s;
int n,qry,cnt,opp[MAXN];
int vis[MAXN],dis[MAXN],ans;
queue<int> q;
inline void execute(int u,int our,int f){
	for(int i = -1;i <= 3;i += 2){
		int v;
		if(i == 3){
			v = opp[u];
		}else{
			v = u + i;
		}
		if(v != 0 && v >= 1 && v <= n){
			if(vis[v] == f){
				ans = dis[v] + dis[u] + 1;
				return ;
			}else if(vis[v] != our){
				vis[v] = our;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		
	}
	return ;
}
void bfs(int st,int obj){
	cnt += 5;
	while(!q.empty()){
		q.pop();
	}
	q.push(st);
	dis[st] = 0;
	vis[st] = cnt;
	q.push(obj);
	dis[obj] = 0;
	vis[obj] = cnt+1;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		if(vis[u] == cnt){
			execute(u,cnt,cnt+1);
		}else{
			execute(u,cnt+1,cnt);
		}
		if(ans != -1)return ;
	}
	return ;
}
stack<int> st;
void build(){
	for(int i = 1;i <= n;i++){
		if(s[i] == ')'){
			const int u = st.top();
			st.pop();
			if(i-u == 1)continue;
			opp[u] = i;
			opp[i] = u;
		}else{
			st.push(i);
		}
	}
	return ;
}
EXCUTE_ST
	freopen("percent.in","r",stdin);
	freopen("percent_BF.out","w",stdout);
	s = "." + sread();
	n = s.length() - 1;
	build();
	qry = read();
	while(qry--){
		ans = -1;
		int l = read(),r = read();
		bfs(l,r);
		write(ans),putchar('\n');
	}
FILE_ED_And_excute
