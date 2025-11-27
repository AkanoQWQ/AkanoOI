#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int n,q,nowl,nowr,L[MAXN][22],R[MAXN][22],Lcnt[MAXN][22],Rcnt[MAXN][22],cnt[MAXN];
string str,imp;
char ch;
inline void Pre(){
	for(int i = 1;i <= n;i++){
		if(L[i][0] - 1 < 0)cerr<<"ERRR!!!"<<endl;
		Lcnt[i][0] = cnt[L[i][0]-1];
		Rcnt[i][0] = cnt[R[i][0]];
	}
	for(int i = n;i >= 1;i--){
		for(int j = 1;j <= 20;j++){
			R[i][j] = R[R[i][j-1]][j-1];
			if(R[i][j] != -1)Rcnt[i][j] = Rcnt[i][j-1] + Rcnt[R[i][j-1]][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 20;j++){
			L[i][j] = L[L[i][j-1]][j-1];
			if(L[i][j] != -1)Lcnt[i][j] = Lcnt[i][j-1] + Lcnt[L[i][j-1]][j-1];
		}
	}
	return ;
}
inline int Dis(int u,int v){
	if(u > v)swap(u,v);
	if(u == v)return 0;
	int ret = 0;
	for(int i = 20;i >= 0;i--){
		if(R[u][i] != -1 && R[u][i] < v){
			u = R[u][i];
			ret += (1<<i);
		}
	}
	return ret+1;
}
inline int Important(int u,int v,int dis){
	int ret = (imp[u] == '1') + (imp[v] == '1');
	dis--;
	const int save = dis;
	for(int i = 20;i >= 0;i--){
		if(dis >= (1<<i)){
			dis -= (1<<i);
			ret += Rcnt[u][i];
			u = R[u][i];
		}
	}
	dis = save;
	for(int i = 20;i >= 0;i--){
		if(dis >= (1<<i)){
			dis -= (1<<i);
			ret -= Lcnt[v][i];
			v = L[v][i];
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	cin>>str>>imp;
	str = "." + str,imp = "." + imp;
	for(int i = 1;i <= n;i++){
		cnt[i] = cnt[i-1] + (imp[i] == '1');
	}
	for(int i = 1;i <= n;i++){
		L[i][0] = R[i][0] = -1;
	}
	nowl = nowr = 0;
	for(int i = 1;i <= 2*n;i++){
		if(str[i] == 'L'){
			nowr++;
		}else{
			nowl++;
			R[nowl][0] = nowr;
		}
	}
	nowl = nowr = n+1;
	for(int i = 2*n;i >= 1;i--){
		if(str[i] == 'R'){
			nowl--;
		}else{
			nowr--;
			L[nowr][0] = nowl;
		}
	}
	Pre();
	while(q--){
		int u,v;
		cin>>u>>v;
		int dis = Dis(u,v);
		cout<<dis<<" "<<Important(u,v,dis)<<'\n';
	}
	cout<<endl;
	return 0;
}
