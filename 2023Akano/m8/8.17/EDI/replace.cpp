#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 1e18 + 14;
ll OBJL,OBJR,n;
ll len[MAXN][26],jump[MAXN][26],tail[MAXN][26];
char ch[MAXN],otp[MAXN];
string str[MAXN];
void dfs(int nowch,int dep,ll nowl,ll nowr){
	if(nowr < OBJL || nowl > OBJR)return ;
	if(dep == n+1){
		if(OBJL <= nowl && nowl <= OBJR){
			otp[nowl - OBJL + 1] = char('a' + nowch);
		}
		return ;
	}
	for(auto i : str[dep]){
		dfs(tail[dep+1][i - 'a'],jump[dep+1][i - 'a'],nowl,nowl + len[dep+1][i - 'a'] - 1);
		nowl += len[dep+1][i - 'a'];
		if(nowl > OBJR)break;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>OBJL>>OBJR>>n;
	for(int i = 1;i <= n;i++)cin>>ch[i]>>str[i];
	for(int i = 0;i < 26;i++){
		len[n+1][i] = 1,jump[n+1][i] = n+1,tail[n+1][i] = i;
	}
	for(int dep = n;dep >= 1;dep--){
		for(int i = 0;i < 26;i++){
			if(i == ch[dep] - 'a'){
				if(str[dep].length() == 1){
					const int OBJ = str[dep][0] - 'a';
					len[dep][i] = len[dep+1][OBJ];
					jump[dep][i] = jump[dep+1][OBJ];
					tail[dep][i] = tail[dep+1][OBJ];
				}else{
					len[dep][i] = 0;
					for(auto nowch : str[dep]){
						len[dep][i] += len[dep+1][nowch - 'a'];
						if(len[dep][i] >= INF)len[dep][i] = INF;
					}
					jump[dep][i] = dep,tail[dep][i] = i;
				}
			}else{
				len[dep][i] = len[dep+1][i];
				jump[dep][i] = jump[dep+1][i];
				tail[dep][i] = tail[dep+1][i];
			}
		}
	}
	dfs(0,1,1,len[1][0]);
	int len = OBJR - OBJL + 1;
	for(int i = 1;i <= len;i++){
		cout<<otp[i];
	}
	return 0;
}
