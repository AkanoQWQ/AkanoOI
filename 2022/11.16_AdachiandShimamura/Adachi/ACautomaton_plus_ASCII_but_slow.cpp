#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
unordered_map<int,unordered_map<char,int> > tr;
unordered_map<int,string> mp;
unordered_map<int,int> fail;
string passage;
int n,m,cnt;
void insert(const string& str){
	int u = 0;
	for(int i = 0;i < str.length();i++){
		const char ch = str[i];
		if(!tr[u][ch])tr[u][ch] = ++cnt;
		u = tr[u][ch];
	}
	mp[u] = str;
	return ;
}
queue<int> q;
void build(){
	for(char i = 32;i < CHAR_MAX;i++){
		if(tr[0][i] != 0){
			q.push(tr[0][i]);
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		for(char i = 32;i < CHAR_MAX;i++){
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
		u = tr[u][str[i]];
		if(mp.find(u) != mp.end()){
			cout<<"find "<<mp[u]<<" in "<<i<<endl;
		}
	}
	return ;
}
string instr;
EXCUTE_ST
	freopen("ACautomaton_plus.in","r",stdin);
	cin>>n;
	for(int i = 1;i <= n;i++){
		string instr;
		cin>>instr;
		for(int j = 1;j <= 1000000;j++)insert(instr);
	}
	build();
	cin.clear();
	cin.ignore();
	while(1){
		instr = "";
		getline(cin,instr);
		if(instr == "")break;
		passage += instr + '\n';
	}
	cout<<passage<<endl;
	find(passage);
FILE_ED_And_excute

