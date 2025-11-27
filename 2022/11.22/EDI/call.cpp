#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
const int MOD = 998244353;
vector<int> e1[MAXN],e2[MAXN];
int n,m,a[MAXN],qq;
struct func{
	int opt,p,v,mul,sz;
}f[MAXN];
void show(){
	for(int i = 1;i <= n;i++){
		printf("%d ",a[i]);
	}
	return ;
}
queue<int> q;
int ind[MAXN];
void tp1(){
	while(!q.empty())q.pop();
	for(int i = 0;i <= m;i++){
		ind[i] = e1[i].size();
		if(ind[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		const int u = q.front();
//		cout<<"vis1 "<<u<<endl;
		q.pop();
		for(int i = 0;i < e2[u].size();i++){
			const int v = e2[u][i];
//			cout<<v<<":"<<f[v].mul<<" -> ";
			f[v].mul = (1ll * f[v].mul * f[u].mul) % MOD;
//			cout<<f[v].mul<<" "<<f[u].mul<<"!!!\n";
			ind[v]--;
			if(ind[v] == 0)q.push(v);
		}
	}
}
void tp2(){
	while(!q.empty())q.pop();
	for(int i = 0;i <= m;i++){
		ind[i] = e2[i].size();
		if(ind[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		int nowx = 1;
		for(int i = int(e1[u].size()) - 1;i >= 0;i--){
			const int v = e1[u][i];
			f[v].sz = (1ll * f[v].sz + 1ll * f[u].sz * nowx) % MOD;
//			cout<<u<<" -> "<<v<<" into "<<f[v].sz<<endl;
			nowx = (1ll * nowx * f[v].mul) % MOD;
			ind[v]--;
			if(ind[v] == 0)q.push(v);
		}
	}
}
int main(){
//	freopen("call.in","r",stdin);
//	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i++){
		scanf("%d",&f[i].opt);
		if(f[i].opt == 1){
			scanf("%d%d",&f[i].p,&f[i].v);
			f[i].mul = 1;
		}else if(f[i].opt == 2){
			scanf("%d",&f[i].mul);
		}else{
			f[i].mul = 1;
			int inc,inx;
			scanf("%d",&inc);
			for(int j = 1;j <= inc;j++){
				scanf("%d",&inx);
				e1[i].push_back(inx);
				e2[inx].push_back(i);
			}
		}
	}
	scanf("%d",&qq);
	for(int i = 1;i <= qq;i++){
		int inx;
		scanf("%d",&inx);
		e1[0].push_back(inx);
		e2[inx].push_back(0);
	}
	f[0].sz = 1;
	f[0].mul = 1;
	tp1();
	tp2();
	for(int i = 1;i <= n;i++){
		a[i] = (1ll * a[i] * f[0].mul) % MOD;
	}
	for(int i = 1;i <= m;i++){
		if(f[i].opt == 1){
			const int u = f[i].p;
			a[u] = (1ll * a[u] + 1ll * f[i].sz * f[i].v) % MOD;
		}
	}
	show();//output ans
	return 0;
}

