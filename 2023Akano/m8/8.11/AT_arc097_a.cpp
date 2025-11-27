#include<bits/stdc++.h>
#include<string>
using namespace std;
const int MAXN = 2006 + 1018 + 2006 + 1108;
string str,ans;
int k,cnt = -1,nxt[MAXN][27],pre[MAXN];
void dfs(string now){
	if(ans != "")return ;
	++cnt;
	if(cnt == k){
		ans = now;
		return ;
	}
	for(int i = 0;i < 26;i++){
		string nxt = now + char('a' + i);
		int npos = str.find(nxt);
		if(npos != -1){
			dfs(nxt);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>str>>k;
	int len = str.length();
	str = "." + str;
	dfs("");
	cout<<ans;
	return 0;
}
