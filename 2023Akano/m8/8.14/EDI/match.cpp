#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
int Turn;
string t,s;
inline bool Match(char c1,char c2){
	if(c1 == '.' || c2 == '.')return true;
	return (c1 == c2);
}
bool vis[MAXN][MAXN];
queue<pair<int,int> > q;
inline void Insert(int i,int j){
	if(!vis[i][j]){
		vis[i][j] = true;
		q.push(make_pair(i,j));
	}
	return ;
}
inline int BFS(){
	const int tlen = t.length() - 3,slen = s.length() - 3;
	while(!q.empty())q.pop();
	memset(vis,0,sizeof(vis));
	Insert(1,1);
	while(!q.empty()){
		const int tit = q.front().first,sit = q.front().second;
		q.pop();
		if(tit > tlen + 1 || sit > slen + 1)continue;
		if(Match(t[tit],s[sit])){//正常匹配 
			Insert(tit+1,sit+1);
		}
		if(t[tit] == '*'){
			if(Match(s[sit-1],s[sit])){//注意是sit和sit+1匹配 
				Insert(tit,sit+1);//使用星号匹配
			}
			Insert(tit+1,sit);//跳过星号 
		}
	}
	int ret = 0;
	for(int i = 2;i <= slen+1;i++){
		ret += vis[tlen+1][i];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>Turn;
	while(Turn--){
		cin>>s>>t;
		t = "_" + t + "[]",s = ";" + s + "{}";
		cout<<BFS()<<endl;
	}
	return 0;
}
