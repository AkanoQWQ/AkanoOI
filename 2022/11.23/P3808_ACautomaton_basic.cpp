#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6;
int n,tr[MAXN][26],tot = 0,word[MAXN],fail[MAXN];
bool vis[MAXN];
int a[MAXN],ans;
void insert(const string& str,int no){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const int v = str[i] - 'a';
		if(tr[u][v] == 0)tr[u][v] = ++tot;
		u = tr[u][v];
	}
	word[u]++;
	return ;
}
queue<int> q;
void build(){
	for(int i = 0;i < 26;i++){
		if(tr[0][i] != 0){
			q.push(tr[0][i]);
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
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
void find(const string& str){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		u = tr[u][str[i] - 'a'];
		if(word[u]){
			if(!vis[u]){
				vis[u] = 1;
				ans += word[u];
			}
		}
	}
	return ;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		string s;
		cin>>s;
		insert(s,i);
	}
	build();
	string passage;
	cin>>passage;
	find(passage);
	printf("%d",ans);
	return 0;
}
