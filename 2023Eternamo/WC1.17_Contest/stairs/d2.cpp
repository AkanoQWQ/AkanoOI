#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
inline char cread(){
	char ch = getchar();
	while(ch != '+' && ch != '-' && ch != 'R' && ch != '?'){
		ch = getchar();
	}
	return ch;
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
int m;
namespace subtask1{
	const int MAXN1 = 405;
	const int NN = 400;
	const int MAXM1 = 1002;
	int v[MAXM1][MAXN1];
	char opt;
	void solve(){
		for(int turns = 1;turns <= m;turns++){
			opt = cread();
			if(opt == '+'){
				int a = read(),b = read();
				for(int i = 1;i <= NN;i++){
					v[turns][i] = v[turns-1][i];
					if(i <= a)v[turns][i] += b;
				}
			}else if(opt == '-'){
				int a = read(),b = read();
				for(int i = 1;i <= NN;i++){
					v[turns][i] = v[turns-1][i];
					if(i >= a){
						v[turns][i] -= b;
						if(v[turns][i] < 0)v[turns][i] = 0;
					}
				}
			}else if(opt == 'R'){
				int u = read();
				for(int i = 1;i <= NN;i++){
					v[turns][i] = v[turns-u][i];
				}
			}else if(opt == '?'){
				int q = read();
				for(int i = 1;i <= NN;i++){
					v[turns][i] = v[turns-1][i];
				}
				bool fd = 0;
				for(int i = 1;i <= NN;i++){
					if(v[turns][i] == 0)break;
					for(int j = 1;j <= v[turns][i];j++){
						int k = i;
						while(v[turns][k+1] >= j)k++;
						int calc = (k-i) + (v[turns][i] - j + 1);
						if(calc == q){
							write(i),putchar(' '),write(j),putchar('\n');
							fd = 1;
							break;
						}
					}
					if(fd)break;
				}
				if(!fd){
					puts("-1 -1");
				}
			//	puts("--------------");
			}
		}
		return ;
	}
}

int main(){
	freopen("stairs.in","r",stdin);
//	freopen("st.out","w",stdout);
	m = read();
	subtask1::solve();
	return 0;
}
