#pragma GCC optimize(3)
#pragma GCC target("avx")
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
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 26;
const int movex[4] = {1,0,-1,0};
const int movey[4] = {0,1,0,-1};
const int MOD = 1000000007;
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
    while(c != '.' && c != '#'){
		s += c;
		c = getchar();
	}
    while(c == '.' || c == '#'){
		s += c;
		c = getchar();
	}
    return s;
}
int r,c,ans,pnt;
string mp[MAXN];
bool vis[MAXN][MAXN];
void calc(){
	int ret = 0;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			if(mp[i][j] == 't'){
				vis[i][j] = 1;
				for(int k = 0;k < 4;k++){
					int OX = i + movex[k],OY = j + movey[k];
					while(OX >= 1 && OX <= r && OY >= 1 && OY <= c && mp[OX][OY] == '.'){
						vis[OX][OY] = 1;
						OX += movex[k];
						OY += movey[k];
					}
				}
			}
		}
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			if(vis[i][j]){
				++ret;
				vis[i][j] = 0;
			}
		}
	}
	ans += ret;
	return ;
}
void dfs(int x,int y){
	if(x > r){
		calc();
		return ;
	}
	if(y > c){
		dfs(x+1,1);
		return ;
	}
	dfs(x,y+1);
	if(mp[x][y] == '.'){
		mp[x][y] = 't';
		dfs(x,y+1);
		mp[x][y] = '.';
	}
	return ;
}
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	r = read(),c = read();
	for(int i = 1;i <= r;i++){
		mp[i] = "!" + sread();
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			pnt += (mp[i][j] == '.');
		}
	}
	if(pnt > 40){
		puts("Never gonna give you up");
		return 0;
	}
	dfs(1,1);
	printf("%d",ans / (1ll<<pnt));
	return 0;
}
