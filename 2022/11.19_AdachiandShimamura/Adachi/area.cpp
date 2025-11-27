#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 2006;
int n,m,q;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string sread(){
    string s = "";
    char c = getchar();
    while(c != 'O' && c != 'X'){
		s += c;
		c = getchar();
	}
    while(c == 'O' || c == 'X'){
		s += c;
		c = getchar();
	}
    return s;
}
string str;
int ans[MAXN][MAXN],c[MAXN];
inline bool judge(int s,int t,int u,int v){
	return (((u-s) + ((v-t) / 2)) < m);
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
EXCUTE_ST
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			c[j] = 1;
		}
		str = "." + sread();
		for(int j = 1;j <= n;++j){
			if(str[j] == 'O'){
				for(int k = n;k >= i;--k){
					if(c[k] < c[k+1])c[k] = c[k+1];
					while(c[k] <= n && judge(i,j,k,c[k])){
						c[k]++;
					}
					if(i == 1){
						cout<<c[k]<<",";
					}
					if(c[k] >= j){
						++ans[k][c[k]-1];
						--ans[k][j-1];
					}
				}
				cout<<endl;
			}
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = n;j >= 1;--j){
			ans[i][j] += ans[i][j+1];
		}
	}
	q = read();
	while(q--){
		int x = read(),y = read();
		write(ans[x][y]),putchar('\n');
	}
FILE_ED_And_excute
