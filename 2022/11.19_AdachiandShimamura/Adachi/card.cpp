#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 2e5 + 7;
set<int> st;
int n,k,p[MAXN],nxt[MAXN],ans[MAXN],km[MAXN];
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
EXCUTE_ST
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1;i <= n;i++){
		p[i] = read();
		ans[i] = -1;
		if(k == 1){
			ans[p[i]] = i;
		}
	}
	if(k == 1){
		for(int i = 1;i <= n;i++){
			printf("%d\n",ans[i]);
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		set<int>::iterator fd = st.lower_bound(p[i]);
		if(fd == st.end()){
			st.insert(p[i]);
			km[p[i]] = 1;
		}else{
			const int u = *fd;
			const int nowk = km[u];
			nxt[p[i]] = u;
			st.erase(fd);
			if(nowk+1 < k){
				km[p[i]] = nowk + 1;
				st.insert(p[i]);
			}else{
				int pos = p[i];
				while(pos != 0){
					ans[pos] = i;
					pos = nxt[pos];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d\n",ans[i]);
	}
FILE_ED_And_excute
