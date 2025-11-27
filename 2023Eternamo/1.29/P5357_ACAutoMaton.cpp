#include<bits/stdc++.h>
using namespace std;
const int MAXU = 2e6 + 6;
const int MAXN = 2e5 + 6;
inline void read(int& ret){
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	ret *= f;
	return ;
}
inline void sread(string& ret){
	ret = "";
	char ch = getchar();
	while(ch < 'a' || ch > 'z'){
		ch = getchar();
	}
	while(ch >= 'a' && ch <= 'z'){
		ret += ch;
		ch = getchar();
	}
	return ;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int tr[MAXU][26],fail[MAXU],from[MAXU],ans[MAXN],val[MAXN],n,tot,ine[MAXN];
vector<int> tag[MAXU];
string s,t;
inline void Insert(const string& str,int no){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		if(tr[u][str[i]-'a'] == 0)tr[u][str[i]-'a'] = ++tot;
		u = tr[u][str[i]-'a'];
	}
	tag[u].push_back(no);
	return ;
}
inline void Build(){
	queue<int> q;
	for(int i = 0;i < 26;i++){
		if(tr[0][i] != 0)q.push(tr[0][i]);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(tr[u][i]){
				fail[tr[u][i]] = tr[fail[u]][i];
				ine[tr[fail[u]][i]]++;
				q.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	return ;
}
inline void Find(const string& str){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		u = tr[u][str[i] - 'a'];
		val[u]++;
	}
	return ;
}
inline void Count(){
	queue<int> q;
	for(int i = 1;i <= tot;i++){
		if(ine[i] == 0)q.push(i);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		ine[fail[u]]--;
		val[fail[u]] += val[u];
		for(int j = 0;j < tag[u].size();j++){
			ans[tag[u][j]] = val[u];
		}
		if(ine[fail[u]] == 0)q.push(fail[u]);
	}
	return ;
} 
int main(){
	read(n);
	for(int i = 1;i <= n;i++){
		sread(t);
		Insert(t,i);
	}
	Build();
	sread(s);
	Find(s);
	Count();
	for(int i = 1;i <= n;i++){
		write(ans[i]),putchar('\n');
	}
	return 0;
}
