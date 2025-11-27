#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXP = 20061;
int n,m,cnt;
int tr[MAXP][26],fail[MAXP];
unordered_map<int,string> mp;
void insert(const string& str){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const int c = str[i] - 'a';
		if(!tr[u][c])tr[u][c] = ++cnt;
		u = tr[u][c];
	}
	mp[u] = str;
	return ;
}
queue<int> q;
void build(){
	for(int i = 0;i < 26;i++){
		if(tr[0][i])q.push(tr[0][i]);
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
	bool find_word = 0;
	for(int i = 0;i < str.length();i++){
		u = tr[u][str[i]-'a'];
		if(mp.find(u) != mp.end()){
			cout<<"find "<<mp[u]<<" in "<<i<<endl;
			find_word = 1;
		}
	}
	if(!find_word){
		puts("We found no word in this passage!");
	}
	return ;
}
EXCUTE_ST
	freopen("ACautomaton.in", "r", stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		string s;
		cin>>s;
		for(int j = 1;j <= 1000000;j++)insert(s);
	}
	build();
	cin>>m;
	while(m--){
		string pass;
		cin>>pass;
		cout<<pass<<":"<<endl;
		find(pass);
	}
FILE_ED_And_excute

