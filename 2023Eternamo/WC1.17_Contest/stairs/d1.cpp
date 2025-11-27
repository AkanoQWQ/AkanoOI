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
	const int MAXN1 = 56;
	const int MAXM1 = 206;
	int v[MAXM1][MAXN1];
	char opt;
	void solve(){
		for(int turns = 1;turns <= m;turns++){
			opt = cread();
			if(opt == '+'){
				int a = read(),b = read();
				for(int i = 1;i <= 50;i++){
					v[turns][i] = v[turns-1][i];
					if(i <= a)v[turns][i] += b;
				}
			}else if(opt == '-'){
				int a = read(),b = read();
				for(int i = 1;i <= 50;i++){
					v[turns][i] = v[turns-1][i];
					if(i >= a){
						v[turns][i] -= b;
						if(v[turns][i] < 0)v[turns][i] = 0;
					}
				}
			}else if(opt == 'R'){
				int u = read();
				for(int i = 1;i <= 50;i++){
					v[turns][i] = v[turns-u][i];
				}
			}else if(opt == '?'){
				int q = read();
				for(int i = 1;i <= 50;i++){
					v[turns][i] = v[turns-1][i];
				}
				bool fd = 0;
				for(int i = 1;i <= 50;i++){
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
			}
		}
		return ;
	}
}
namespace subtask2{
	const int MAXN2 = 1e3 + 4;
	struct Node{
		int hi[MAXN2];
	}now;
	struct Node2{
		char opt;
		int opts[2];
		bool NEED_BE_SAVED;
	}lx[MAXN2];
	queue<Node> q;
	int h[MAXN2],n;
	int calc(int x,int he){
		int l = x,r = n,ret = x;
		while(l <= r){
			const int mid = (l + r) >> 1;
			if(h[mid] >= he){
				ret = mid;
				l = mid + 1;
			}else if(h[mid] < he){
				r = mid - 1;
			}
		}
		int mainret = (ret - x) + (h[x] - he) + 1;
		return mainret;
	}
	void solve(){
		for(int i = 1;i <= m;i++){
			lx[i].opt = cread();
			if(lx[i].opt == '+'){
				lx[i].opts[0] = read(),lx[i].opts[1] = read();
			}else if(lx[i].opt == '-'){
				lx[i].opts[0] = read(),lx[i].opts[1] = read();
			}else if(lx[i].opt == 'R'){
				lx[i].opts[0] = read();
				lx[i-lx[i].opts[0]].NEED_BE_SAVED = 1;
			}else if(lx[i].opt == '?'){
				lx[i].opts[0] = read();
			}
		}
		for(int i = 1;i <= m;i++){
			if(lx[i].opt == '+'){
				const int a = lx[i].opts[0],b = lx[i].opts[1];
				for(int i = 1;i <= a;i++){
					now.hi[i] += b;
				}
			}else if(lx[i].opt == '-'){
				const int a = lx[i].opts[0],b = lx[i].opts[1];
				for(int i = a;i <= 1000;i++){
					now.hi[i] -= b;
					if(now.hi[i] <= 0){
						now.hi[i] = 0;
						break;
					}
				}
			}else if(lx[i].opt == 'R'){
				if(i - lx[i].opts[0] <= 0)continue;
				now = q.front();
				q.pop();
			}else if(lx[i].opt == '?'){
				const int ask = lx[i].opts[0];
				n = -1;
				for(int i = 1;i <= 1000;i++){
					h[i] = now.hi[i];
					if(h[i] <= 0){
						n = i - 1;
						break;
					}
				}
				if(n == -1)n = 1000;
				bool fd = 0;
				for(int i = 1;i <= n;i++){
					int l = 1,r = h[i];
					while(l <= r){
						const int mid = (l + r) >> 1;
						int ret = calc(i,mid);
						if(ret == ask){
							fd = 1;
							write(i),putchar(' '),write(mid),putchar('\n');
							break;
						}
						if(ret > ask){
							l = mid + 1;
						}else{
							r = mid - 1;
						}
					}
					if(fd)break;
				}
				if(fd == 0){
					puts("-1 -1");
				}
			}
			if(lx[i].NEED_BE_SAVED){
				q.push(now);
			}
		}
		return ;
	}
}
int main(){
	freopen("stairs.in","r",stdin);
//	freopen("stairs.out","w",stdout);
	m = read();
	subtask2::solve();
	return 0;
}
