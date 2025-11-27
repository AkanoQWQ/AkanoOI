#include<bits/stdc++.h>
using namespace std;
const int MAXN = 22006;
int n,tr[MAXN][26],tot = 0,fail[MAXN];
vector<int> word[MAXN];
pair<int,int> ans[MAXN];
string s[MAXN];
void insert(const string& str,int no){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const int v = str[i] - 'a';
		if(tr[u][v] == 0)tr[u][v] = ++tot;
		u = tr[u][v];
	}
	word[u].push_back(no);
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
		for(int p = u;p;p = fail[p]){
			for(int j = 0;j < word[p].size();j++){
				ans[word[p][j]].first++;
			}
		}
	}
	return ;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}
void INIT(){
	for(int i = 0;i <= tot;i++){
		for(int j = 0;j < 26;j++){
			tr[i][j] = 0;
		}
		fail[i] = 0;
		word[i].clear();
		ans[i].first = 0,ans[i].second = 0;
	}
	tot = 0;
	return ;
}
bool execute(){
	cin>>n;
	if(n == 0)return 1;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		insert(s[i],i);
	}
	build();
	string passage;
	cin>>passage;
	find(passage);
	for(int i = 1;i <= n;i++){
		ans[i].second = i;
	}
	sort(ans+1,ans+n+1,cmp);
	cout<<ans[1].first<<endl;
	for(int i = 1;i <= n;i++){
		if(ans[i].first != ans[1].first)break;
		cout<<s[ans[i].second]<<endl;
	}
	return 0;
}
int main(){
	while(1){
		INIT();
		if(execute())break;
	}
	return 0;
}
