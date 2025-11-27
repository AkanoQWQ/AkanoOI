#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
string s,t;
inline string sread(){
	string ret = "";
	char ch = getchar();
	while(ch < 'A' || ch > 'C'){
		ch = getchar();
	}
	while(ch >= 'A' && ch <= 'C'){
		ret += ch;
		ch = getchar();
	}
	return ret;
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
int q,lsta[MAXN][2],lt,bn[MAXN][2];
int main(){
//	freopen("always.in","r",stdin);
//	freopen("always.out","w",stdout);
	s = "." + sread();
	t = "." + sread();
	for(int i = 1;i <= s.length();i++){
		if(s[i] == 'C')s[i] = 'B';
		if(s[i] == 'A' && lt == 0){
			lt = i;
		}else if(s[i] != 'A'){
			lt = 0;
		}
		lsta[i][0] = lt;
		bn[i][0] = bn[i-1][0] + (s[i] == 'B');
	}
	lt = 0;
	for(int i = 1;i <= t.length();i++){
		if(t[i] == 'C')t[i] = 'B';
		if(t[i] == 'A' && lt == 0){
			lt = i;
		}else  if(t[i] != 'A'){
			lt = 0;
		}
		lsta[i][1] = lt;
		bn[i][1] = bn[i-1][1] + (t[i] == 'B');
	}
	q = read();
	while(q--){
		int a = read(),b = read(),c = read(),d = read();
		int s_a = b - max(a,lsta[b][0]) + 1;
		int t_a = d - max(c,lsta[d][1]) + 1;
		int s_b = bn[b][0] - bn[a-1][0];
		int t_b = bn[d][1] - bn[c-1][1];
		if(s[b] != 'A')s_a = 0;
		if(t[d] != 'A')t_a = 0;
		//cout<<s_a<<" "<<s_b<<" | "<<t_a<<" "<<t_b<<endl;
		if(t_a > s_a){
			putchar('0');
			continue;
		}
		if(s_b == 0 && t_b == 0){
			if((s_a - t_a) % 3 == 0){
				putchar('1');
				continue;
			}else{
				putchar('0');
				continue;
			}//AA
		}
		
		
		if(s_a > t_a && (s_a - t_a) % 3 != 0){
			s_b += 2;
			s_a = t_a;
		}
		if(s_b == 0){
			s_b = 2;
			s_a--;
		}
		
		if(t_a > s_a){
			putchar('0');
			continue;
		}
		//cout<<s_a<<" "<<s_b<<" | "<<t_a<<" "<<t_b<<endl;
		if(s_b <= t_b && (t_b - s_b) % 2 == 0){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	return 0;
}
