#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 6;
int tr[MAXN][26+26+10+3];
int word[MAXN];
int tot = 0;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
inline int to(char a){
	if(a >= '0' && a <= '9')return (a - '0');//0 ~ 9
	if(a >= 'a' && a <= 'z')return (10 + (a - 'a'));//10 ~ 35
	if(a >= 'A' && a <= 'Z')return (36 + (a - 'A'));
	return 0;
}
inline bool est(char a){
	if(a >= '0' && a <= '9')return 1;//0 ~ 9
	if(a >= 'a' && a <= 'z')return 1;//10 ~ 35
	if(a >= 'A' && a <= 'Z')return 1;
	return 0;
}
void insert(const string& str){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const int v = to(str[i]);
		if(tr[u][v] == 0)tr[u][v] = ++tot;
		u = tr[u][v];
		word[u]++;
	}
	return ;
}
void INIT(){
	for(int i = 0;i <= tot;i++){
		for(int j = 0;j <= 64;j++){
			tr[i][j] = 0;
		}
		word[i] = 0;
	}
	tot = 0;
	return ;
}
int find(const string& str){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const int v = to(str[i]);
		if(tr[u][v] == 0)return 0;
		u = tr[u][v];
	}
	return word[u];
}
int t,n,q;
string sread(){
	string ret = "";
	char ch = getchar();
	while(!est(ch)){
		ch = getchar();
	}
	while(est(ch)){
		ret += ch;
		ch = getchar();
	}
	return ret;
}
int main(){
	t = read();
	while(t--){
		INIT();
		n = read(),q = read();
		while(n--){
			string ins = sread();
			insert(ins);
		}
		while(q--){
			string obj = sread();
			printf("%d\n",find(obj));
		}
	}
	return 0;
}
