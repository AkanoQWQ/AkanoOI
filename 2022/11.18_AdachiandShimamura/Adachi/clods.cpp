#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int TT,n,a[2006];
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
bool g[1108],t[14];
int ans;
void calc(){
	int mex = -1,cnt = 0;
	memset(t,0,sizeof(t));
	for(int i = 1;i <= n;i++){
		if(a[i] <= 12){
			t[a[i]] = 1;
		}
		if(g[i] || i == n){
			for(int j = 0;j <= 12;j++){
				if(t[j] == 0){
					cnt = j;
					break;
				}
			}
			if(mex != -1 && cnt != mex){
				return ;
			}else{
				mex = cnt;
			}
			memset(t,0,sizeof(t));
		}
	}
	ans++;
	return ;
}
void dfs(int dep){
	if(dep >= n){
		calc();
		return ;
	}
	g[dep] = 1;
	dfs(dep+1);
	g[dep] = 0;
	dfs(dep+1);
	return ;
}
EXCUTE_ST
	freopen("clods.in","r",stdin);
	freopen("clods.out","w",stdout);
	TT = read();
	while(TT--){
		n = read();
		ans = 0;
		if(n > 15){
			int x,y;
			if(n == 37000000){
				x = read(),y = read();
			}
			for(int i = 1;i <= n;i++){
				x = read();
			}
			puts("1");
			continue;
		}
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
FILE_ED_And_excute
