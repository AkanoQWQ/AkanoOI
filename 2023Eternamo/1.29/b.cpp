#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 6;
const int MAXU = MAXN * 51; 
struct trie{
	int kol;	
}te[MAXU];
int tr[MAXU][28];
int tot;
string s[MAXN];
inline int turn(const char& c){
	if(c >= 'a' && c <= 'z')return (c - 'a');
	if(c == '.')return 26;
	return 27;
}
void Insert(const string& str,int no){
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		if(tr[u][turn(str[i])] == 0)tr[u][turn(str[i])] = ++tot;
		u = tr[u][turn(str[i])];
		te[u].kol--;
	}
	return ;
}
int ans;
bool ST = 1;
void Calc(const string& str){
	++ans;
	int u = 0,len = str.length();
	for(int i = 0;i < len;i++){
		u = tr[u][turn(str[i])];
		if(te[u].kol == -1 || (u == tr[0][turn(str[0])] && ST)){
			if(u == tr[0][turn(str[0])])ST = 0;
			for(int j = 0;j < 28;j++){
				if(tr[u][j] != 0 && te[tr[u][j]].kol == 0)--ans;
			}
		}
		te[u].kol++;
	}
	cout<<ans<<endl;
	return ;
}
int n;
int main(){
	//freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
		Insert(s[i],i);
	}
	for(int i = 1;i <= n;i++){
		Calc(s[i]);
	}
	return 0;
}
