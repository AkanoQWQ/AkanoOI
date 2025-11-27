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
int tr[MAXU][26],fail[MAXU],from[MAXU],n,tot,wlen[MAXU];
string passage,t;
inline void Insert(const string& str,int no){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		if(tr[u][str[i]-'a'] == 0)tr[u][str[i]-'a'] = ++tot;
		u = tr[u][str[i]-'a'];
	}
	wlen[u] = len;
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
				q.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	return ;
}
stack<pair<int,char> > Nishoj;
inline void Solve(){
	int u = 0,len = passage.length();
	for(int i = 0;i < len;i++){
		Nishoj.push(make_pair(u,passage[i]));
		u = tr[u][passage[i] - 'a'];
		
		if(wlen[u] != 0){
			for(int i = 1;i < wlen[u];i++){
				Nishoj.pop();
			}
			u = Nishoj.top().first;
			Nishoj.pop();
		}
	}
	return ;
}
stack<char> opt;
int main(){
	sread(passage);
	sread(t);
	Insert(t,1);
	Build();
	Solve();
	while(!Nishoj.empty()){
		opt.push(Nishoj.top().second);
		Nishoj.pop();
	}
	while(!opt.empty()){
		putchar(opt.top());
		opt.pop();
	}
	return 0;
}
