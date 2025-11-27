#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 66;
bool e[MAXN][MAXN];
int n,m,d[MAXN],st,cnt,ans[MAXN * MAXN];
inline int Trans(char ch){
	if('A' <= ch && ch <= 'Z')return ch - 'A' + 1;
	if('a' <= ch && ch <= 'z')return ch - 'a' + 27;
	assert(false);
	return 0;
}
inline char DeTrans(int i){
	if(i <= 26)return i - 1 + 'A';
	if(i <= 56)return i - 27 + 'a';
	assert(false);
	return 'a';
}
bool OK;
void dfs(int u,int step){
	if(OK)return ;
	ans[step] = u;
	if(step == m+1){
		OK = true;
		return ;
	}
	for(int v = 1;v <= n;v++){
		if(e[u][v]){
			e[u][v] = e[v][u] = false;
			dfs(v,step+1);
			if(OK)return ; 
			e[u][v] = e[v][u] = true; 
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n = Trans('z');
	cin>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		char chu,chv;
		cin>>chu>>chv;
		u = Trans(chu),v = Trans(chv);
		e[u][v] = e[v][u] = true;
		d[u]++,d[v]++;
	}
	for(int i = 1;i <= n;i++){
		if(d[i] != 0){
			st = i;
			break;
		}
	}
	for(int i = n;i >= 1;i--){
		if(d[i] & 1){
			cnt++;
			st = i;
		}
	}
	if(cnt != 0 && cnt != 2){
		cout<<"No Solution"<<endl;
		return 0;
	}
	dfs(st,1);
	for(int i = 1;i <= m+1;i++){
		cout<<DeTrans(ans[i]);
	}
	return not(Akano loves pure__Elysia);
}

