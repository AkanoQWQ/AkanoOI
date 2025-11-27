#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006118;
string str;
int pi[2006118],q,line,len;
const double EPS = 1e-7;
int KMP(){
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(str[i] != str[j] && j)j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
	}
	return len - pi[len-1];
}
void sread(string& ret){
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
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
bool judge(int l,int pos){
	bool fd = 1;
	for(int i = l+1;i <= len;i++){
		if(str[i] != str[i-l] || i == pos || i-l == pos){
			fd = 0;
			break;
		}
	}
	return fd;
}
bool judgeb(int l){
	bool fd = 1;
	for(int i = l+1;i <= len;i++){
		if(str[i] != str[i-l]){
			fd = 0;
			break;
		}
	}
	return fd;
}
int ables[MAXN];
int main(){
	freopen("a.in","r",stdin);
	freopen("a2.out","w",stdout);//abcdddabc 0 0 0 1 1 1 0 0 0
//aabaabaa 0 1 2 2 2 2 1 0
	str = ".";
	sread(str);
	len = str.length() - 1;
	line = KMP();
	q = read();
	const int bas = (len+1) / 2;
	for(int i = 0;i < line;i++){
		bool able = judgeb(i+bas);
		if(able){
			for(int j = bas + i;j <= len;j += line)ables[j] = 1;
		}
	}
	for(int i = 1;i <= len;i++){
		ables[i] += ables[i-1];
	}
	while(q--){
		int pos,ans = 0;
		pos = read();
		
		for(int l = 1;l < len;l++){
			if(judge(l,pos)){
				ans++;
			}
		}
		write(max(ans,0)),putchar('\n');
	}
	return 0;
}
