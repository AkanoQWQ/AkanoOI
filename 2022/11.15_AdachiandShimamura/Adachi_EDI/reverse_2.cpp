#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#pragma GCC optimize(2)
FILE_ST
const int MAXN = 100006;
int n,k,m,s,ans[MAXN];
bool est[MAXN];
queue<int> q;
set<int> set1,set2;
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
	//freopen("reverse.in","r",stdin);
	//freopen("reverse.out","w",stdout);
	n = read();
	k = read();
	m = read();
	s = read();
	for(int i = 1;i <= m;i++){
		int x;
		x = read();
		est[x] = 1;
	}
	for(int i = 1;i <= n;i++){
		ans[i] = -1;
	}
	for(int i = 1;i <= n;i++){
		if(est[i] || i == s)continue;
		if(i%2 == 0){
			set2.insert(i);
		}else{
			set1.insert(i);
		}
	}
	ans[s] = 0;
	q.push(s);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		int l = max(1,u - k + 1),r = min(n,u + k - 1);
		if(l == 1){
			cout<<l + (l + k - 1) - u<<" hei hei "<<endl;
		}
		l = l + (l + k - 1) - u,r = r + (r - k + 1) - u;
		set<int> &st = (l%2 == 0)?set2:set1;
		for(auto i = st.lower_bound(l);i != st.end();){
			if(*i > r)break;
			ans[*i] = ans[u] + 1;
			q.push(*i);
			st.erase(i++);
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d ",ans[i]);
	}
FILE_ED_And_excute
