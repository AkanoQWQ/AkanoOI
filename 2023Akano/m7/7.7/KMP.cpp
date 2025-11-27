#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}

inline vi KMP(string str){
	const int len = str.length();
	vi pi(len);
	for(int i = 1;i < len;i++){
		int j = pi[i-1];
		while(j && str[i] != str[j])j = pi[j-1];
		if(str[i] == str[j])++j;
		pi[i] = j;
	}
	return pi;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;
	vi pi = KMP(b + "." + a);
	for(int i = 0;i < pi.size();i++){
		if(pi[i] == b.length())cout<<i-b.length()*2+1<<endl;
	}
	for(int i = 0;i < b.length();i++){
		cout<<pi[i]<<" ";
	}
	cout<<endl;
	return 0;
}
