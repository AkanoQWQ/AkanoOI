#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 2006;
int pi[MAXN];
void get_pi(const string& str){
	const int len = str.length() - 1;
	for(int i = 1;i <= len;i++){
		int j = pi[i-1];
		while(j > 0 && str[i] != str[j])j = pi[j-1];
		if(str[i] == str[j])j++;
		pi[i] = j;
	}
	return ;
}
string ins = "I_love_yuri";
string fds = "yuri";
EXCUTE_ST
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	get_pi(fds+"!"+ins);
	const int m = ins.length();
	const int n = fds.length();
	for(int i = 0;i <= n+m+1;i++){
		if(pi[i] == n){
			cout<<"find in "<<i-n-1<<endl;
		}
	}
FILE_ED_And_excute

