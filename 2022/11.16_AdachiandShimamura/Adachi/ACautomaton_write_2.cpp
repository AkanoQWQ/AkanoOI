#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXP = 20061;
const int st = 0;
int t[MAXP][26],n,tnt = st,fail[MAXP],m;
unordered_map<int,string> mp;
void insert(const string& str){
	int u = st;
	for(int i = 0;i < str.length();i++){
		const int c = str[i] - 'a';
		if(!t[u][c])t[u][c] = ++tnt;
		u = t[u][c];
	}
	mp[u] = str;
	return ;
}
queue<int> q;
void build(){
	for(int i = 0;i < 26;i++){
		if(t[st][i])q.push(t[st][i]);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(t[u][i]){
				fail[t[u][i]] = t[fail[u]][i];
				q.push(t[u][i]);
			}else{
				t[u][i] = t[fail[u]][i];
			}
		}
	}
	return ;
}
void find(const string& str){
	int u = st;
	bool find_word = 0;
	for(int i = 0;i < str.length();i++){
		if(str[i] == '_')continue;
		u = t[u][str[i] - 'a'];
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
		string instr;
		cin>>instr;
		insert(instr);
	}
	build();
	cin>>m;
	while(m--){
		string passage;
		cin>>passage;
		cout<<passage<<":"<<endl;
		find(passage);
	}
FILE_ED_And_excute

