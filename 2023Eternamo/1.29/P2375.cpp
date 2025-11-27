#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 6; 
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
inline string sread(){
	string ret = "";
	char ch = getchar();
	while(ch < 'a' || ch > 'z'){//¼ÇµÃ¸Ä 
		ch = getchar();
	}
	while(ch >= 'a' && ch <= 'z'){
		ret += ch;
		ch = getchar();
	}
	return ret;
}
int t,fail[MAXN];
string s;
void KMP(){
	int len = s.length();
	for(int i = 1;i < len;i++){
		int j = fail[i-1];
		while(s[i] != s[j] && j > 0)j = fail[j];
		if(s[i] == s[j])j++;
		fail[i] = j;
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	t = read();
	while(t--){
		s = sread();
		KMP();
		for(int i = 0;i < s.length();i++)cout<<fail[i]<<" ";
	}
	return 0;
}

